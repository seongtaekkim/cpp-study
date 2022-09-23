#include <iostream>
#include <tuple>

using namespace std;

auto my_func()
{
    //return tuple<int, int>(123, 123, 123); // begin c++14 
                                             // tuple은 c++14부터 정의 가능.
    return tuple(123, 123, 123); // begin c++17 
                                 // tuple 인자 타입 및 개수를 정하지 않아도 호출 가능.
}

int main()
{
     auto result = my_func();
     //cout << get<0>(result) << " " << get<1>(result) << get<1>(result) << endl;
     
     auto[a, b, c] = my_func();
     cout << a << " " << b << " " << c << " " <<  endl;
     
     return (0);
}