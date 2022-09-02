#include <iostream>
//#include <fstream>

using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0)
        : m_cents(cents) {}
    int getCents() {
        return (m_cents);
    }

    friend ostream& operator << (ostream& out, const Cents &cents)
    {
        out << cents.m_cents;
        return (out);
    }

   /*  friend int operator - (const Cents &cents)
    {
        return (-cents.m_cents);
    } */
    Cents operator - () const
    {
        return (Cents(-m_cents));
    }

    bool operator ! () const
    {
        return (m_cents == 0 ? true : false);
    }

};
int main(int argc, char *argv[])
{
    
    Cents c1(10);
    cout << -Cents(60) << endl;

    //auto temp = c1;
    cout << !c1 << endl;
    return (0);
}
