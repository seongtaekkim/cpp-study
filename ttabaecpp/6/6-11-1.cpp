#include <iostream>

using namespace std;

int main(void)
{
    //int array[1000000]; // stack memmory 를 넘기면 에러가 발생한다.
    
    // int 크기의 메모리를 포인터 변수에 할당함.
    int *ptr = new int;
    // int *ptr = new int{7};
    // int *ptr = new (std::nothrow) int {7};
    *ptr = 7;

    cout << ptr << endl;
    cout << *ptr << endl;
    delete ptr; // os에 메모리를 돌려줌 (메모리 해제)
                // 프로그램이 종료하면, 자동으로 os가 해제함.

    ptr = nullptr;
    cout << "after delete" << endl;
    if (ptr != nullptr)
    {
    cout << ptr << endl;
    cout << *ptr << endl;
    }
    else
        cout << "could not allowed memmory";
     
    return (0);
}