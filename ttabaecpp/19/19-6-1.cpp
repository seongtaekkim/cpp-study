#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>  // std::inner_product
#include <execution> // parallel execution

using namespace std;

mutex mtx;

void dotProductNative(const vector<int> &v0, const vector<int> &v1,
            const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
    for (unsigned i = i_start ; i < i_end ; i ++)
        sum += v0[i] * v1[i];
}

/*
    기존 : 반복연산에 global변수가 포함되어있어 반복연산 내부에 mutex이 필요해 속도가 저하되었음.
    개선 : 반복연산은 local하게 처리하고, 결과를 sum 하는 부분만 lock 한다.
*/
void dotProductLock(const vector<int> &v0, const vector<int> &v1,
        const unsigned i_start, const unsigned i_end, unsigned long long  &sum)
{
    unsigned long long tmp = 0;

    // for 밖에 lock 하면 시퀀셜하게 진행되고,
    // 내부에 lock 하면 병렬처리되지만, 빈번하게 lock 하므로 성능이 저하된다.
    cout << "thread start " << endl;
    for (unsigned i = i_start ; i < i_end ; i++)
    {
        //std::scoped_lock lock(mtx); // begin c++17
        tmp += v0[i] * v1[i];
        //sum += v0[i] * v1[i];
    }

    std::scoped_lock lock(mtx); // begin c++17
    sum = sum + tmp;
    cout << "thread end " << endl;
}

/*
    thread 와 마찬가지로 개선.
*/
void dotProductAtomic(const vector<int> &v0, const vector<int> &v1
            , const unsigned i_start, const unsigned i_end, atomic<unsigned long long> &sum)
{
    unsigned long long tmp = 0;

    for (unsigned i = i_start ; i < i_end ; i++)
    {
        //sum += v0[i] * v1[i];
        tmp += v0[i] * v1[i];
    }
    sum = sum + tmp;
}

auto dotProductFuture(const vector<int> &v0, const vector<int> &v1,
            const unsigned i_start, const unsigned i_end)
{
    int sum = 0; // local sum
    for (unsigned i = i_start; i < i_end ; i++)
    {
        sum += v0[i] * v1[i];
    }
    return (sum);
}

int main()
{
/*
    v0 = {1, 2, 3}
    v1 = {4, 5, 6}
    v0_dot_v1 = 1*4 + 2*5 + 3*6;
*/
    const long long n_data = 100'000'000;
    const unsigned n_threads = 4;   

    // initialize vectors
    std::vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);

    random_device seed;
    mt19937 engine(seed());
    uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0; i < n_data; i++)
    {
        v0.push_back(uniformDist(engine));
        v1.push_back(uniformDist(engine));
    }
    cout << "std::inner_product" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Native" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        unsigned long long sum = 0;
        vector<thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t] =std::thread(dotProductNative, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        for (unsigned t = 0; t < n_threads ; t++)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "dotProductLock" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        unsigned long long sum = 0;
        vector<thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t] =std::thread(dotProductLock, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        for (unsigned t = 0; t < n_threads ; t++)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }


    cout << "dotProductAtomic" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        atomic<unsigned long long> sum = 0;
        vector<thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t] =std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        for (unsigned t = 0; t < n_threads ; t++)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "dotProductFuture" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        unsigned long long sum = 0;
        vector<std::future<int>> futures;
        futures.reserve(n_threads);

        const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            futures[t] =std::async(dotProductFuture, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread);
        for (unsigned t = 0; t<n_threads; t++)
            sum += futures[t].get();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    // std::execution::par mac 지원안함
    /*  cout << "std::transform_reduce" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }  */
    // use divide and conquer strategy for std::thread
    // use promise

    /*
        
        1. thread 
        2. atomic
        3. thread + promise (async 대신에 thread 로 구현)
    */
    return (0);
}