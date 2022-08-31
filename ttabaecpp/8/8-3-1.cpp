#include <iostream>
using namespace std;


class Fraction
{
private:
    int m_numerator = 1;    // c++11 부터 기본값 가능
    int m_denominator = 2;
public:
    Fraction() // 정의하지 않아도 default 생성자는 기본으로 생성되어잇다.
                // 기본생성자 이외의 생성자가 있으면, 기본생성자는 정의하지 않으면 생성되어 있지 않다.
    {
        m_numerator = 0;
        m_denominator = 1;
    }
    Fraction(const int& num, const int& den = 10)
    {
        m_numerator = num;
        m_denominator = den;
    }
    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

int main(int argc, char *argv[])
{
    //Fraction f {0, 1};
    Fraction f; // 생성자에 매개변수가 없는 경우에만 () 가 없음
    Fraction one_thirds(1); // 기본값 여부에 따라 인자를 안넣어도 됨
                            // 기본값을 입력하여 사용할 시에 오버로딩 사용에 유의해야함.
    f.print();
    one_thirds.print();
    
    Fraction one_thirds = Fraction(1); // copy initialization
    Fraction f {0, 1}; // 형변환 엄격 (double -> int ) 불가능
    Fraction f (0, 1); // 형변환 필요 시 경고만 발생
    return (0);
}