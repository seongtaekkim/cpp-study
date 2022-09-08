#include <iostream>
using namespace std;

class Base
{
public:
    int m_i = 0;
    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived1 : public Base
{
public:
    int m_j = 1024;
    virtual void print() override
    {
        cout << "I'm Derived1 " << endl;
    }
};

class Derived2 : public Base
{
public:
    string m_name = "kim";
    virtual void print() override
    {
        cout << "I'm Derived2 " << endl;
    }
};

int main(void)
{
    Derived1 d1;
    //d1.m_j = 1;
    Base *base = &d1;
    //Base *b = new Derived1;
    ///b->print();
    //base->m_i = 

    auto *base_to_d1 = dynamic_cast<Derived1*>(base);
    if (base_to_d1 != 0)
        cout << base_to_d1->m_j << endl;
    else
        cout << "failed " << endl;


    auto *base_to_d2 = dynamic_cast<Derived2*>(base);
    //auto *base_to_d1 = static_cast<Derived2*>(base); // 알수없는 문자열
    if (base_to_d2 != 0)
        cout << base_to_d2->m_name << endl;
    else
        cout << "failed " << endl;
    return (0);
}