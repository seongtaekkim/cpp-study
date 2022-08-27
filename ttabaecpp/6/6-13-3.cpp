#include <iostream>

using namespace std;

int main(void)
{
    int value = 5;
    int *const ptr = &value;

    *ptr = 10;

    int value2 =8;
    //ptr = &value2;


    return (0);
}