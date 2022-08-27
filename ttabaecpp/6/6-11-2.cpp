#include <iostream>

using namespace std;

int main(void)
{
    // memory leak
    while (true)
    {
        int *ptr = new int;
        cout << ptr << endl;

        delete ptr; //메모리 반환 시 속도 이슈가 있기 때문에, 이에 대한 최적화가 필요하다. java 같은 프로그램과 달리 c++은 이 부분을 개발자가 제어할 수 있기 때문에 성능을 최적화 할 수 있다.
    }
    return (0);
}