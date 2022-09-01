#include <iostream>
using namespace std;


class Something
{
private:
    static int s_value; // 정적변수는 기본값 할당 못함.
public:
    static int getValue()
    {
        //return this->s_value; // static 함수는, static 이외의 맴버변수나, this로접근하는 static 맴버변수에 접근못한다.
        return s_value;
    }
    int temp()
    {
        return this->s_value;
    }
}; 

int Something::s_value = 1; // static 이라 접근가능
                            // 정의는 한곳에만 있어야 하므로, cpp에 정의해야 함 (header 안됨)
int main(int argc, char *argv[])
{

    //cout << Something::s_value << endl; private static 은 접근 불가능
    cout << Something::getValue() << endl; // 특정 인스턴스와 상관없이 실행시킴

    Something s1, s2;
    
    int (Something::*fptr1)() = &Something::temp; // 맴버함수는 인스턴스 마다 메모리가 할당되는게 아니라, 한 곳에만 존재한다.
    cout << (s2.*fptr1)() << endl;

    int (*fptr2)() = &Something::getValue; // 정적함수는 특정 인스턴스와 상관없이 함수를 실행시킬 수 있다. 
    cout << fptr2() << endl;

    return (0);
}