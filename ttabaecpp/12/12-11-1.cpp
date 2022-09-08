#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Base";
        return (out);
    }
};

std::ostream& operator << (std::ostream &out, const Base &b)
{
    return (b.print(out));
}

class Derived : public Base
{
public:
    Derived() {}
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Derived";
        return (out);
    }
};

int main(void)
{
    Base b;
    std::cout << b << '\n';
    Derived d;
    std::cout << d << '\n';
    Base &bref = d;
    std::cout << bref << '\n';

    return (0);
}