#include <iostream>

using namespace std;


enum Type
{
    INT,
    FLOAT,
    CHAR,
};

int main(void)
{
    // void pointer == generic pointer
    int     i = 1;
    float   f = 1.1;
    char    c = 'a';

    void    *ptr = nullptr;

    ptr = &i;
    ptr = &c;
    ptr = &f;

    //cout << ptr + 1 << endl; // 어떤 자료형인지 몰라 몇바이트를 더해야 하는 지 알 수 없어 컴파일에러
    cout << &f << " " << ptr << endl;
    //cout << *ptr << endl; // 어떤 자료형읹 ㅣ모르기 때문에 컴파일에러가 발생함.

    Type type = FLOAT;
    if (type == FLOAT)
        cout << *static_cast<float*>(ptr) << endl;
    else if (type == INT)
        cout << *static_cast<int*>(ptr) << endl;

    cout << static_cast<int*>(ptr) << endl;
    cout << static_cast<int*>(ptr) +1 << endl;
    return (0);
}