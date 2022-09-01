#include <iostream>
using namespace std;

int generateId()
{
    static int s_id = 0;
    return (++s_id);
}

class Something
{
public:
    int m_value = 1;
    static int s_value; // 정적변수는 기본값 할당 못함.
    const static int c_value = 1; // 반드시 초기화 해야함. // singleton 패턴에서 사용함
};

int Something::s_value = 1; // static 이라 접근가능
                            // 정의는 한곳에만 있어야 하므로, cpp에 정의해야 함 (header 안됨)
int main(int argc, char *argv[])
{
    //cout << generateId() << endl;

    cout << &Something::s_value << " " << Something::s_value << endl;

    Something s1;
    Something s2;
    /*
    s1.m_value = 2;
    cout << &s1.m_value << " " << s1.m_value << endl;
    cout << &s2.m_value << " " << s2.m_value << endl;
    */
    s1.s_value = 2;
    cout << &s1.s_value << " " << s1.s_value << endl;
    cout << &s2.s_value << " " << s2.s_value << endl;
    
    return (0);
}