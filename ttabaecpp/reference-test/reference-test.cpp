#include <iostream>
using namespace std;
int main(void)
{
    int num1 = 1;
    int num2 = 2;
    int &ref = num1;
    cout << &num1 << endl;
    cout << &ref << endl;

    ref = num2;
    cout << &num1 << endl;
    cout << &ref << endl;

    cout << num1 << " " << num2 << " " << ref << endl;
    cout << &num1 << endl;
    cout << &ref << endl;
    cout << &num2 << endl;

    const int &ref2 = nullptr;
    cout << ref2 << endl;
    return (0);
}