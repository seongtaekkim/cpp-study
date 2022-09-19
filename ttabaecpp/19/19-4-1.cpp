#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <atomic>

using namespace std;

mutex mtx;  //mutual exclusion

int shared_memory(0); // race condition
//atomic<int> shared_memory(0);

int main(void)
{
    auto count_func  =[]() {
        for (int i=0 ; i<1000 ; i++)
        {
            this_thread::sleep_for(chrono::microseconds(1));
            //mtx.lock();
            ///lock_guard lock(mtx); // c++11
            //scoped_lock lock(mtx); // c++17
            shared_memory++;
            //shared_memory.fetch_add(1);
            //mtx.unlock();
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);


    t1.join();
    t2.join();

    cout << "After" << endl;
    cout << shared_memory << endl;


    return (0);
}