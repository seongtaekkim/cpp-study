#include <iostream>
using namespace std;


void doSomething(int &v)
{
    cout << "l-value : " << v << endl;
}
void doSomething(int &&v)
{
    cout << "r-value : " << v << endl;
}

int getResult()
{
    return (100 * 100);
}

int main(void)
{
    int x = 5;
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    // L-value references

    int &lr1 = x;       // Modifiable l-value
    // int &lr2 = cs;   // Non-modifiable l-value
    // int &lr3 = 5;    // R-values

    const int &lr4 = x; // Modifiable l-value
    const int &lr5 = cx; // Non-modifiable l-value
    const int &lr6 = 5; // R-value

    // R-value references

    // int &&rr1 = x;
    // int &&rr2 = cs;
    int &&rr3 = 5;
    int &&rrr = getResult();

    cout << rr3 << " " << &rr3 << endl;
    rr3 = 10;
    cout << rr3 << " " << &rr3 << endl;
    // const int &&rr4 = x;
    // const int &&rr5 = cx;
    const int &&rr6 = 5;

    // L/R-value reference parameters
    doSomething(x);
    //doSomething(cx);
    doSomething(5);
    doSomething(getResult());




    return (0);
}