#include <iostream>
#include <array>

using namespace std;

struct S
{
    int a,b,c,d;
};

S getStruct()
{
    S my_s {1,2,3,4}; // c++11부터 가능
    return (my_s);
}
// 단점 : 함수별로 구조체를 만들어야 하므로, 개발비용이 발생.
int main(void)
{
    S my_s = getStruct();
    cout << my_s.b << endl;
    return (0);
}