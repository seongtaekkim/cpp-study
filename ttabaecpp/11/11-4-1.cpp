#include <iostream>
using namespace std;

class Mother
{
private:
    double m_i;
public:
    Mother() {}
    Mother(const int &i_in)
        :m_i(i_in)
        {
            cout << "mother construction " << endl;
        }
    ~Mother()
    {
        cout << "mother destruc " << endl;
    }
};

class Child : public Mother
{
private:
    double m_d;
public:
    Child()
        : Mother(1024), m_d(1.0)
        {
            cout << "child constructr " << endl;
        }
    ~Child()
    {
        cout << "child destruc " << endl;
    }
};


int main(void)
{
    Child c;
    Mother b;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    
    return (0);
}