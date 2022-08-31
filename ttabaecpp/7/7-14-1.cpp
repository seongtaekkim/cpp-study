#include <iostream>
#include <array>
#include <cassert>
using namespace std;


void printValue(const array<int, 5> &my_array, const int& ix)
{
    assert(ix >= 0);
    assert(ix <= my_array.size() - 1);

    cout << my_array[ix] << endl;
}

int main(void)
{
    int number = 5;

    // release 에서는 실행하지 않음 ??gcc에서 어케 ?
    // debug에서만 실행함
    assert(number == 5);

    array<int, 5> my_arr{1,2,3,4,5};

    printValue(my_arr, 100);
    return (0);
}