#include <iostream>

using namespace std;

int main(void)
{
    int value1 = 5;
    const int *ptr = &value1; // ptr이 가리키는 값은 바꿀 수 없지만,
                                // ㅔ
    int value2 = 6;
    ptr = &value2;
    return (0);
}