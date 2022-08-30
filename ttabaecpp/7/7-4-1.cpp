#include <iostream>

using namespace std;
// call by value


// 실용적인건 참조변수가 좋다.
void    foo(int *ptr) // 포인터 변수는 call by value
{
    cout << *ptr << " " << ptr << " " << &ptr << endl;

    *ptr = 10;  // 역참조는, 참조변수로 값을 변경한것과 같은 기능을 한다.
}
 
// modern 도입 이후에, 1. return value optimization 2. 여러개의 리턴타입을 구현하는게 복잡하지 않음
int main(void)
{

    int x = 5;
    cout << x << " " << &x << endl;
    
    int *ptr = &x;

    cout << &ptr << endl;
    foo(ptr);
    foo(&x);
    //foo(5);
    return (0);
}