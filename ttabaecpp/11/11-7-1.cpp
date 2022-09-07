#include <iostream>
using namespace std;

class Base
{
private:
    int m_value;
public:
    //Base() {}
    Base(const int &value)
        :m_value(value) {}
    void    print() const
    {
        cout << "Base print" << endl;
    }
};

class Derived : public Base
{
private:
    int m_value;
public:
    Derived(const int &value)
        : Base(value), m_value(value) {}
    void    print() const
    {
        Base::print();
        cout << "derived print" << endl;
    }

};

std::ostream & operator << (std::ostream &out, const Base &d)
{
    out << "Base output operator ";
    return (out);
}

std::ostream & operator << (std::ostream &out, const Derived &d)
{
    // protected 는 상위 캐스팅이 안됨
    out << static_cast<Base>(d);
    out << "derived output operator ";
    return (out);
}

int main(void)
{
    Base b(5);
    //b.print();
    cout << b << endl;
    Derived d(10);
    ///d.print();
    cout << d << endl;
    return (0);
}