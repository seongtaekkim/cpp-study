#include <iostream>
#include <vector>
#include <utility> // std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct &s)
{
    cout << "pass by L-ref" << endl;
}

void func(MyStruct &&s)
{
    cout << "pass by R-ref" << endl;
}

/* template<typename T>
void func_wrapper(T t)
{
    func(t);
}
 */
template<typename T>
void func_wrapper(T&& t)
{
    // 파라메터가 l-value 이면, l-value로,
    // r-value 이면 r-value로 변환해서 넘겨준다.
    func(std::forward<T>(t));
}

int main(void)
{
    MyStruct s;

    //func(s);
    //func(MyStruct());

    // 둘다 l-ref 처럼 실행된다
    // templete이 구분을 못하기 때문.
    func_wrapper(s);
    func_wrapper(MyStruct());
}