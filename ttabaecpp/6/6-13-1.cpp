#include <iostream>

using namespace std;

int main(void)
{
    const int value = 5;
    const int *ptr = &value;
    //*ptr = 6; // const 라서 역참조하여 할당할 수 는 없다.
    cout << *ptr << endl;

    int value2 = 5;
    const int *ptr2 = &value2;
    //*ptr2 = 6;
    value2 = 7;
    cout << *ptr2<< endl;
    return (0);
}