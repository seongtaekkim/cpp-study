#include <iostream>
using namespace std;
#include <vector>
#include <functional>
class Base
{
public:
    int m_i = 0;
    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;
    virtual void print() override
    {
        cout << "I'm Derived " << endl;
    }
};

void    doSomething(Base &b)
{
    b.print();
}

int main(void)
{
    Derived d;
    Base &b = d;
    // Base b = d : 슬라이싱 발생 
    b.print();
    doSomething(b);


    Derived d2;
    Base b2;
    std::vector<Base> my_vec;
    my_vec.push_back(b2);
    my_vec.push_back(d2);

    // puchback 하면서 강제로 슬라이싱이 발생함.
    for (auto & e : my_vec)
        e.print();
    

    std::vector<Base*> my_vec2;
    my_vec2.push_back(&b2);
    my_vec2.push_back(&d2);

    for (auto & e : my_vec2)
        e->print();


    //std::vector<Base&> my_vec3;
    std::vector<std::reference_wrapper<Base>> my_vec3;
    my_vec3.push_back(b2);
    my_vec3.push_back(d2);

    for (auto & e : my_vec3)
        e.get().print();
    return (0);
}