#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;  //mutual exclusion

int main(void)
{
    const int num_pro = thread::hardware_concurrency();
    cout << thread::hardware_concurrency() << endl;
    cout << this_thread::get_id() << endl;

    /* thread t1 = thread([]() {
        cout << this_thread::get_id() << endl;
        while (true)
        {}
    }); */


    // step1
    /* vector<thread> my_threads;
    my_threads.resize(num_pro);

    for (auto & e : my_threads)
        e = thread([]() {
            cout << this_thread::get_id() << endl;
            while (true)
            {}
        });
    for (auto & e : my_threads)
        e.join(); */


    // step2
    auto work_func = [](const string &name)
    {
        for (int i = 0; i < 5; i ++)
        {
            this_thread::sleep_for(chrono::microseconds(100));
            mtx.lock();
            cout << name << " " << this_thread::get_id() << " is working " << i << endl;
            mtx.unlock();
        }
    };

    //work_func("jackacjk");
    //work_func("dash");

    thread t1 = thread(work_func, "jackjack");
    thread t2 = thread(work_func,"dash");

    t1.join();
    t2.join();


    return (0);
}