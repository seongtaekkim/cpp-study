#include <iostream>
#include <tuple>

using namespace std;


// 사용자정의 자료형 처럼 된다.
tuple<int, double> getTuple()
{
    int a = 10;
    double d = 3.14;
    return (make_tuple(a, d));
}

int main(void)
{
    tuple<int, double> my_tp = getTuple();
    cout << get<0>(my_tp) << endl; // a
    cout << get<1>(my_tp) << endl; // d


    // c++17 부터는 auto로 tuple 타입을 받을 수 있음.
    auto[a, d] = getTuple();
    cout << a << endl;
    cout << d << endl;
    return (0);
}