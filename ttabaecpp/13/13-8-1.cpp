#include <iostream>
using namespace std;

template<class T>
class A
{
private:
    T m_value;
public:
    A(const T &input)
        : m_value(input)
    {}
    void print()
    {
        cout << m_value << endl;
    }
    template<typename TT>
    void doSomething(const TT &input)
    {
        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
    }
};

/* template<class T>
class A<T*>
{
private:
    T* m_value;
public:
    A( T* input)
        : m_value(input)
    {}
    void print()
    {
        cout << *m_value << endl;
    }
}; */

int main(void)
{
    A<int> a_int(123);
    a_int.print();
    a_int.doSomething<float>(12.2);
    a_int.doSomething(12.2l);

    return (0);
}