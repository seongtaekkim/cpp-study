#include <iostream>
#include <array>
#include <functional> // c++11

using namespace std;

int func()
{
    return (5);
}

int goo()
{
    return (10);
}


bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    return false;
}
bool isOdd(const int& number)
{
    if (number % 2 == 1) return true;
    return false;
}

/*
    bool 타입으로 홀수짝수를 구분해서 출력함.
*/
void    printNumbers(const array<int, 10> &my_array, bool print_even)
{
    for (auto element : my_array)
    {
        if (print_even && element % 2 == 0)
            cout << element;
        if (!print_even && element % 2 == 1)
            cout << element;
    }
    cout << endl;
}

// 구조체로 타입을 alias해서 사용가능
//typedef bool (*check_fcn_t)(const int&); 

// 혹은 using으로 타입이름을 정의하여 사용 가능
using check_fcn_t = bool(*)(const int&);

// 함수포인터를 잘 사용하면 다형성 이해에 좋다.
// 함수포인터는 기본값으로 함수를 가질 수 있다.
void    printNumbers2(const array<int, 10> &my_array, 
check_fcn_t check_fcn = isEven)
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true)
            cout << element;
    }
    cout << endl;
}

// function 개념 추가
void    printNumbers3(const array<int, 10> &my_array, 
function<bool(const int&)> check_fcn)
{
    for (auto element : my_array)
    {
        if (check_fcn(element) == true)
            cout << element;
    }
    cout << endl;
}

int main(void)
{
    cout << &func << endl; // 메모리 출력.. 이 안되는데 ?

    // 함수 포인터 정의
    int (*funcptr)() = func; 

    // 리턴타입과 매개변수 개수,타입이 같으면 다른 함수주소를 할당받을 수 있다.
    funcptr = goo;

    // 함수호출
    cout << funcptr() << endl;


    //홀수짝수 출력
    array<int, 10> my_array {1,2,3,4,5,6,7,8,9,10};

    printNumbers(my_array, true);
    printNumbers(my_array, false);

    printNumbers2(my_array);
    printNumbers2(my_array, isOdd);

    // function 을 사용 시 실행할 함수를 호출 단에서 정할 수 있다.
    // 뒤에 단원에 가면 편리한 기능이 더 나오는듯 ?
    function<bool(const int&)> fcnptr = isEven;

    printNumbers3(my_array, fcnptr);
    fcnptr = isOdd;
    printNumbers3(my_array, fcnptr);
    
    
    return (0);
}