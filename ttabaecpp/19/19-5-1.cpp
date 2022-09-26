#include <iostream>
#include <string>
#include <thread>
#include <future>

using namespace std;

int main(void)
{
    // multi thread
    {
        int result;
        std::thread t([&] {result = 1 + 2;} );
        t.join();

        cout << result << endl;
    }

    // task-based parallelism
    {
        auto fut = std::async([] {return  1 + 2;} );
        cout << fut.get() << endl;
    }

    // future and promise
    {
        std::promise<int> prom;
        auto fut = prom.get_future();

        auto t = std::thread([](std::promise<int>&& prom)
        {
            prom.set_value(1 + 2);
        }, std::move(prom));

        cout << fut.get() << endl;
        t.join();
    }


    {
        auto f1 = std::thread([] {
            cout << "async1 start" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "async1 endl" << endl;
        });

        auto f2 = std::thread([] {
            cout << "async2 start" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "async2 endl" << endl;
        });
        f1.join();
        f2.join();
        cout << "main function " << endl;
        
    }

    return (0);
}