#include <iostream>

using namespace std;
// call by value

void    doSomething(int y)
{
    cout << "in func : " << y << " " << &y << endl;
}



int main(void)
{

    int x = 1;

    cout << "in main " << x << " " << &x << endl;

    doSomething(x);
    doSomething(x + 1);
    return (0);
}