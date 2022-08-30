#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
// call by value

void    addOne(int &y)
{
    cout << y << " " << &y << endl;
    y = y + 1;
}
// const : 입력
// 레퍼런스 : 출력
void    getSinCos(const double &degree, double &sin_out, double &cos_out)
{
    static const double pi = 3.141592; // header로 뺀다.
    const double radians = degree * pi / 180.0;
    sin_out = sin(radians);
    cos_out = cos(radians);
}

void foo(const int &x)
{
    cout << x << endl;
}

///typedef int* pint;
// void foo2(pint &ptr)
void foo2(int *&ptr)
{
    cout << *ptr << " " << *&ptr << endl;
}

// vector를 사용하거나, 클래스 객체를 인자로 넘겨주면, 배열을 넘기는것처럼 어렵게 코드하지 않아도 됨.
// void printElement(vector<int>& arr)
void printElement(int (&arr)[4])
{

}

// modern 도입 이후에, 1. return value optimization 2. 여러개의 리턴타입을 구현하는게 복잡하지 않음
int main(void)
{

    int x = 5;
    cout << x << " " << &x << endl;

    addOne(x);

    cout << x << " " << &x << endl;

    double sin(0.0);
    double cos(0.0);

    getSinCos(30.0, sin, cos);
    cout << sin << " " << cos << endl;

    foo(5);


    x = 5;
    int *ptr = &x;
    //pint ptr = &x;
    foo2(ptr);
    cout << *ptr << " " << ptr << endl;

    int arr[]{1,2,3,4};
    printElement(arr);
    vector<int> arr2{1,2,3,4};
    return (0);
}