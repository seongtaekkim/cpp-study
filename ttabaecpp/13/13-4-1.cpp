#include <iostream>
#include "Storage.h"
using namespace std;

template<typename T>
T getMax(T x, T y)
{
    return ((x > y) ? x : y);
}


// 모든 매개변수를 특수화 하는걸 (완전)특수화 라고한다.
template<>
char getMax(char x, char y)
{
    cout << "warning : comparing chars" << endl;
    return ((x > y) ? x : y);
}

int main(void)
{
    cout << getMax(1, 2) << endl;
    cout << getMax<double>(1, 2) << endl;
    cout << getMax('a', 'b') << endl;

    Storage<int> nValue(5);
    Storage<double> dValue(5.5);

    nValue.print();
    dValue.print();
    return (0);
}