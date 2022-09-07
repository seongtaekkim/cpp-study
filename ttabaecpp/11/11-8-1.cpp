#include <iostream>
using namespace std;

class Base
{
protected:
    int b_value;
public:
    //Base() {}
    Base(const int &value)
        :b_value(value) {}
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

    using Base::b_value;

private:
    using Base::print; // do not add ()
    //void print() = delete; // c++11
};


int main(void)
{
    Derived d(5);
    d.b_value = 5;
   // d.print();
    Base b(10);
    b.print();

    return (0);
}