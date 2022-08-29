#include <iostream>

using namespace std;

int foo(int x, int y); // parameter

int foo(int x, int y)
{
    return (x + y);
}

int main(void)
{

    int x = 1;
    int y = 2;
    foo(7, 7); // arguments (actual parameters)
    foo(x, y);
   
}