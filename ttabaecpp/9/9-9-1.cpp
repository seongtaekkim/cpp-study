#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
        {
            assert(den != 0);
        }
    Fraction(const Fraction &fraction)
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "copy constructor called " << endl;
    }
    const int getNum() const
    {
        return (this->m_numerator);
    }
    const int getDen() const
    {
        return (this->m_denominator);
    }
};

std::ostream & operator << (std::ostream &out, const Fraction &f)
{
    out << f.getNum() << " / " << f.getDen();
    return (out);
}

Fraction doSomething()
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return (temp);
}

// copy constructor 를 priavte 에 정의하면, copyconstructor 자체가 불가능하다.
int main(void)
{
    Fraction f(3 ,5);
    //Fraction copy = f;
    //Fraction copy(Fraction(2,2)); // 인스턴스를 생성하면서 인자로 입력하면, copy를 생략한다.
    Fraction copy = doSomething(); // 설명은 debug는 copy, release는 아니었지만, 실제론 둘다 copy를 안한다.
    cout << &copy << endl;
    cout << f << " " << copy << endl;
    return (0);
}