#include <iostream>
using namespace std;


class A
{
private:
    int m_value;
public:
    A(int n)
        :m_value(n)
    {}
    int getValue() 
    {
        return (m_value);
    }
    string print2()
    {
        return ("print2");
    }
    void print()
    {
        cout << (*this).print2() << endl;
        cout << this->print2() << endl;
    }
};

int main(void)
{
    A(5).print();
    return (0);
}