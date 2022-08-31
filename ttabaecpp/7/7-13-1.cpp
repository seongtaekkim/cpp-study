#include <iostream>
#include <string>

using namespace std;


int main(void)
{
    // syntax error
    // int x

    // semantic errors
    int x;
    cin >> x;
    if (x >= 5)
        cout << "x is greater than 5" << endl;

    // violated assumption
    string hello = "hello, my name is jack jack";
    while (true)
    {
        unsigned long ix;
        cin >> ix; // 10000 입력 시  에러
        
        if (ix >0 && ix <= hello.size() - 1)
        {
            cout << hello[ix] << endl;
            break;
        }
        else
            cout << "again" << endl;
    }
    return (0);
}