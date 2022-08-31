#include <iostream>
using namespace std;

class B
{
    private:
    int m_b;
    public:
    B(const int& b) : m_b(b) {}
};

class Something
{
    private:
        int m_i = 100;   // 생성자 기본값이 우선순위가 더 높음
        double m_d = 10.1;
        char m_c = 'b';
        int m_arr[5] = {5,6,7,8,9};
        B m_b {1024};
    public:
        Something() 
            : m_i(1)
            , m_d(3.14)
            , m_c('c')
            , m_arr{1,2,3,4,5}
            , m_b(m_i - 1)
        {
            m_i = 1000;
        }
        void print()
        {
            cout << m_i << " " << m_d << " " << m_c << " " << endl;
            for(auto &e : m_arr)
                cout << e;
            cout << endl;
            
        }
};

int main(int argc, char *argv[])
{
    Something s;
    s.print();
    return (0);
}