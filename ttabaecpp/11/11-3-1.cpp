#include <iostream>
using namespace std;

class Mother
{
public:
    int m_i;
    Mother() {}
    Mother(const int &i_in)
        :m_i(i_in)
        {
            cout << "mother construction " << endl;
        }
};

class Child : public Mother
{
public:
    double m_d;
    Child()
        : Mother(1024), m_d(1.0)
        {
            cout << "child constructr " << endl;
        }
};


int main(void)
{
    Child();
    return (0);
}