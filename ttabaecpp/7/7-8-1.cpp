#include <iostream>

using namespace std;


// 기본값이 있는 파라메터의 오른쪽에 기본값이 없으면 안됨.

// header 혹은 구현체 한군데에서만 기본값을 설정할 수 있다.
//void    print(int x = 10, int y = 100, int z = 1000);

void    print(int x = 10, int y = 100, int z = 1000)
{
    cout << x << " " << y << " " << z << endl;
}

void    print2(string str) {}
void    print2(char ch = ' ') { }

void    print3(int x) {}
void    print3(int x, int y = 30) {}

int main(void)
{
    // 기본값이 있는 파라메터는 호출하지 않아도 됨.
    print(10);
    print(20, 200);

    // 기본값이 있는 char ch 을 호출함
    print2();

    // 파라메터의 기본값에 따라 오버로딩이 안될 수 있다. (ambiguous)
    //print3(10);
    return (0);
}