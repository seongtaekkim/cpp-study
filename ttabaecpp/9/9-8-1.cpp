#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(const int cents = 0)
        : m_cents(cents) {}
    int getCents() const
    {
        return (m_cents);
    }
    void    setCents(const int cents) 
    {
        this->m_cents = cents;
    }
    operator int()
    {
        return (this->m_cents);
    }
};

class Dollar
{
private:
    int m_dollar = 0;
public:
    Dollar(const int &input)
        : m_dollar(input) {}
    operator Cents()
    {
        return (Cents(m_dollar * 100));
    }
};

void    printInt(const int &value)
{
    std::cout << value << std::endl;
}

int main(void)
{
    Cents cents(10);
    int value = (int)cents;
    value = int(cents);
    value = static_cast<int>(cents);
    printInt(cents);

    printInt(Cents(Dollar(2)));
    Dollar d(2);
    Cents c = d;
    printInt(c);
}