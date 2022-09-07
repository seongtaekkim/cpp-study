#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "~base()" << endl;
    }
};

class Derived : public Base
{
private:
    int *m_array;
public:
    Derived(int length)
    {
        m_array = new int [length];
    }
    virtual ~Derived() override
    {
        cout << "~Derived" << endl;
        delete[] m_array;
    }
};

int main(void)
{
    Derived d0(5);
    Derived *d = new Derived(5);
    Base *b = d;
    cout << sizeof d << endl; // pointer
    cout << sizeof *d << endl;
    cout << sizeof d0 << endl;
    delete b;
    
}