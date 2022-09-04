#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction (char c) =  delete;
    explicit Fraction(int num = 0, int den = 1)
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

Fraction doSomething(Fraction f)
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return (temp);
}

void    test(int a)  = delete;

// copy constructor 를 priavte 에 정의하면, copyconstructor 자체가 불가능하다.
int main(void)
{
    //doSomething(7);  // explicit 에 의해 암시적인 casting은 컴파일 에러다.
    doSomething(Fraction(1)); 
   // doSomething('c');  // delete 키워드로 해당 함수는 사용할 수 없다.
    
    return (0);
}