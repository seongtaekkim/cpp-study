#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0)
        :m_cents(cents) {}
    int getCents() const
    {
        return (m_cents);
    }
    int &getCents()
    {
        return (m_cents);
    }
// 맴버로만 해야하는 연산자 =, []. (), ->  
Cents operator + (const Cents &c2)
{
    return  this->m_cents + c2.getCents();
}
};

/* Cents add(const Cents &c1, const Cents &c2)
{
    return  c1.getCents() + c2.getCents();
} */

/* Cents operator + (const Cents &c1, const Cents &c2)
{
    return  c1.getCents() + c2.getCents();
} */

int main(void)
{
    Cents c1(10);
    Cents c2(20);

    Cents sum;
    //add(c1, c2);

   // cout << add(c1, c2).getCents() << endl; 

    cout << (c1 + c2).getCents() << endl;

    // 연산오버로딩 안되는경우 ?:  :: sizeof . .*
    // ^ 이거는 우선순위가 너무 낮아서 괄호를 쌓아한다 차라리 그냥 쓰자
};