#include <iostream>

using namespace std;

int main(void)
{
    int x = 5;
    int &ref = x;

    const int y = 8;
    const int &ref2 = y; // const에 할당행햐함.

    int value1 = 5;
    int value2 = 10;
    int &ref1 = value1;

    cout << ref1 << endl;
    ref1 = value2;

    cout << ref1 << endl;
    return (0);
}