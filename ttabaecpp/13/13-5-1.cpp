#include <iostream>
#include "Storage8.h"

using namespace std;


template<typename T>
class A
{
public:
    A(const T &input)
    {}
    void    doSomething()
    {
        cout << typeid(T).name() << endl;
    }
    void    test()
    {}
}; 

template<>
class A<char>
{
public:
    A(const char &temp)
    {}
    void    doSomething()
    {
        cout << "char type specialization" << endl;
    }
};



int main(void)
{
    //A     a_int(1); // c++17부터 가능
    A<int>     a_int(1);
    A<double>   a_double(3.24);
    A<char>     a_char('a');
    
    a_int.test();
    a_double.test();
    // 다른클래스를 사용하는 것에 불과하기때문에, 구현하지 않은 기능은 당연히 사용할 수 업다
    // a_char.test();

    a_int.doSomething();
    a_double.doSomething();
    a_char.doSomething();

    Storage8<int>   intStorage;

    for (int count = 0; count < 8; count++)
        intStorage.set(count, count);

    for (int count = 0; count < 8; count++)
        cout << intStorage.get(count) << endl;

    // 4바이트(int)를 배열(8)로 생성하여 32
    cout << "sizeof storage8<int> " << sizeof(Storage8<int>) << endl;


    Storage8<bool> boolStorage;
    for (int count = 0; count < 8; count++)
        boolStorage.set(count, count);

    for (int count = 0; count < 8; count++)
        cout << boolStorage.get(count) << endl;

    // class specialization : 1바이트(bool)을 1개 변수에 생성하여 1바이트
    // no specialization : 1바이트(bool)을 8개짜리 배열에 생성하여 8바이트
    cout << "sizeof storage8<bool> " << sizeof(Storage8<bool>) << endl;
    return (0);
}