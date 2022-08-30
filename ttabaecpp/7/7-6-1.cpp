#include <iostream>

using namespace std;



inline  int min(int x, int y)
{
    return (x > y ? y : x);
}

int main(void)
{
    cout << min(5, 6) << endl;
    cout << min(3, 2) << endl;

    cout << (5 > 6 ? 6 : 5) << endl; // 컴파일 시 이와같이 된다.
                                        // 요즘 컴파일러는, 컴파일러판단하에 inline으로 변경해서
                                    // 사람이 inline 으로 명시한다고 해서 크게 나아지지 않는다.
                                    // 이렇게 작성한다고 해서 컴파일러가 inline으로 하려하지 않을수도잇다
    return (0);
}