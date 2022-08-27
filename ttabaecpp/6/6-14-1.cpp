#include <iostream>

using namespace std;

int main(void)
{
    int  value = 5;
    
    int *ptr = nullptr;
    ptr = &value;

    int &ref = value; // 참조변수는 반드시 초기화 되어야하고,
                      // literal 이 입력되면 안된다 (주소를 갖는 lvalue 만 할당 가능)

    cout << ref << endl;
    ref = 10;
    cout << value << " " << ref << endl;

    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr << endl;
    cout << &ptr << endl;

    return (0);
}