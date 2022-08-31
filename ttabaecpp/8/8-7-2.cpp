#include <iostream>
using namespace std;

class Calc
{
private:
    int m_value;
public:
    Calc(int init_value)
        : m_value(init_value) {}
    Calc& add(int value)
    {
        m_value += value;
        return (*this);
    }
    Calc& sub(int value) 
    {
        m_value -= value;
         return (*this);
    }
    Calc& mul(int value)
    {
        m_value *= value;
         return (*this);
    }
    void print()
    {
        cout << m_value << endl;
    }
};
// 연쇄 호출
int main(int argc, char *argv[])
{
    Calc c(10);
    // c.add(10);
    // c.sub(5);
    // c.mul(2);
    Calc &temp1 = c.add(10);
    Calc &temp2 = temp1.sub(5);
    Calc &temp3 = temp2.mul(2);
    temp3.print();
    c.add(10).sub(5).mul(2).print();
    Calc(10).add(3);
    c.print();
    return (0);
}