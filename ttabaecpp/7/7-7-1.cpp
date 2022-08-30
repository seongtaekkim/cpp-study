#include <iostream>
#include <string>

using namespace std;

int add(int x, int y)
{
    return (x + y);
}

int add(double x, double y)
{
    return (x + y);
}

void    getRandom(int &x) {};
void    getRandom(double &x) {};

typedef int my_int;

void print(int x) {}
//void print(my_int x) {}

void    print2(const char *value) {}
void    print2(int value) {}

void    print3(unsigned int value) {}
void    print3(float value) {}

int main(void)
{
    add(1, 2);
    add(3.0, 5.0); // 컴파일할때 결정되어야 함.
                    // 매개변수 타입이 달라야함.
                    // 매개변수가 아애 없다고 하더라도 안됨


    // 매개변수 없이 리턴타입만 다른경우,
    // 리턴을 void로 하고, 파라메터를 참조변수로 작성하여 리턴하도록 작성하면 된다.
    // 이방법이 안되면, dummy인자를 넘긴다.
    int x;
    getRandom(x);


    //
    print2(0);
    print2('a'); // int로 인식해서 넘겨진다.
    print2("a"); // 명확하게 문자열로 인식하게 하기위해 함수 구현체의 파라메터를 const로 변환해야한다.

    // overload 함수 인자로 모호한 상태가 될 수 있으니, 명확한 타입의 인자로 넘겨주어야 한다.
    print3((unsigned int)'a');
    print3(0u);
    print3(3.14f);
    return (0);
}