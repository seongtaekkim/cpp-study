#include <iostream>
using namespace std;

class Digit
{
private:
    int m_digit;
public:
    Digit(int digit = 0)
        :m_digit(digit) {}
    int getDigit() const
    {
        return (m_digit);
    }
    Digit & operator ++ ()
    {
        ++m_digit;
        return (*this);
    }
    Digit operator ++ (int)
    {
        Digit temp(m_digit);
        //cout << this << endl;
        //cout << &(this->m_digit) << endl;
        //++(*this);
        ++(this->m_digit);
        return (temp);
    }
};

std::ostream & operator << (std::ostream &out, const Digit digit)
{
    out << digit.getDigit();
    return (out);
}


int main()
{
    cout << Digit(5) << endl;;
    cout << Digit(10)++ << endl;
    cout << ++Digit(15) << endl;   
}