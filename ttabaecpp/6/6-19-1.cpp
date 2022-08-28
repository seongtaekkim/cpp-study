#include <iostream>

using namespace std;

int main(void)
{
    int *ptr = nullptr;
    int **ptrptr = nullptr;

    int value = 5;
    ptr = &value;
    ptrptr = &ptr;

    cout << ptr << " " << *ptr << " " << &ptr << endl;
    cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
    cout << *(*ptrptr) << endl;

    return (0);
}