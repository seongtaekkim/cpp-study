#include <iostream>

using namespace std;

void doSomething(int &n)
{
    n = 10;
    cout << &n << endl;
    cout << "in something " << n  << endl;
}

int main(void)
{
    int n = 5;
    doSomething(n);
    cout << n << endl;
    cout << &n << endl;
    doSomething(n);
    return (0);
}