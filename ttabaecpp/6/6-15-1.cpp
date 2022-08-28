#include <iostream>

using namespace std;

void    doSomething(const int &n)
{
    cout << n << endl;
}

int main(void)
{
    const int &ref_x = 3 + 4;
    //const int ref_x = 3 + 4; 결국 뭔차이 ?
    doSomething(5);
    doSomething(ref_x + 5);
    return (0);
}