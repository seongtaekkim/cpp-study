#include <iostream>
using namespace std;


class A
{
private:
    int &m_int;
public:
    A(int &n)
        :m_int(n)
    {
        cout << "A default constructor " << endl;
    }
    A(const A &a)
        :m_int(a.m_int)
    {
        cout << "A copy constructor " << endl;
    }
    A & operator = (const A &a)
    {
        cout << "A copy assignment constructor " << endl;
        return *this;
    }

};

class B : public A
{
public:
    B(int &n)
        : A(n)
    {
        cout << "B default constructor " << endl;
    }
    B(const B &b)
        : A(b)
    {
        cout << "B copy constructor " << endl;
    }
    B & operator = (const B &a)
    {
        A::operator=(a);
        cout << "B copy assignment constructor " << endl;
        return *this;
    }
};

int main(void)
{
    int n = 1;
    B b(n);
    B b2(b);
    b2 = b;
    return (0);
}