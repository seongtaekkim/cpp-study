#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents) {
        m_cents = cents;
    }
    int getCents() const {
        return (m_cents);
    }
};

Cents add(const Cents &c1, const Cents &c2)
{
    return Cents(c1.getCents() + c2.getCents());
}

int main(int argc, char *argv[])
{
    cout << add(Cents(6), Cents(8)).getCents() << endl; // rvalue 처럼 작동
    cout << int(6) + int(8) << endl;
    return (0);
}