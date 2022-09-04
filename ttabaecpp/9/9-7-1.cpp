#include <iostream>
using namespace std;

// 괄호 연연산산자  오오버버로로딩딩과 함수객체
// Function object (functor)
class Accumulataor
{
private:
    int m_counter = 0;
public:
    int operator () (int i)
    {
        return (m_counter += i);
    }
};

int main(void)
{
    Accumulataor acc;
    std::cout << acc(10) << std::endl;
    std::cout << acc(10) << std::endl;
}