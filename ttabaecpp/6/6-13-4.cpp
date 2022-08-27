#include <iostream>

using namespace std;

int main(void)
{
    int value = 5;
    const int *const ptr = &value;

    //ptr = &value;
    //*ptr = 10;


    return (0);
}