#include <iostream>
using namespace std;

class A
{
public:
    int m_value;
    A(const int& input)
        :m_value(input)
    {
        cout << "constructor " << endl;
    }
    ~A()
    {
        cout << "distructor " << m_value << endl;
    }
    void print()
    {
        cout << m_value << endl;
    }
};

int main(int argc, char *argv[])
{
    A a(1);
    a.print();

    A(2).print(); // rvalue 처럼 동작하는 익명객체부터 소멸됨.
    return (0);
}