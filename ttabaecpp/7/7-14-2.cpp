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
    const int x = 2;

    // runtime 시 오류를 발생
    assert(x == 5);
    // conpile time에 오류를 발생
    static_assert(x == 5, "x should be 5");
    return (0);
}