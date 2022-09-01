#include <iostream>
using namespace std;


class Something
{
public:
    class _init // inner class 를 사용해서 간접적으로 static 변수를 초기화할 수 있다.
    {
    public:
        _init()
        {
            s_value = 1234;
        }
    };
private:
    int m_value;
    static int s_value;
    static _init s_initializer;
public:
    Something()
        : m_value(123) {} // static 맴버변수는 생성자 안에서 초기화 못함. 생성자가 static이 안되기 때문.
    static int getValue()
    {
        return s_value;
    }
    int temp()
    {
        return this->s_value;
    }
}; 

// int Something::s_value;
Something::_init Something::s_initializer;

int main(int argc, char *argv[])
{

    //cout << Something::s_value << endl; private static 은 접근 불가능
    cout << Something::getValue() << endl; // 특정 인스턴스와 상관없이 실행시킴

    Something s1, s2;
    
    int (Something::*fptr1)() = &Something::temp;
    cout << (s2.*fptr1)() << endl;
    int (*fptr2)() = &Something::getValue;
    cout << fptr2() << endl;
    
    return (0);
}