#include <iostream>

using namespace std;

int main(void)
{
    //const int length = 5;
    //int array[length];

    int length;
    cin >> length;
    int *array = new int[length];
    // int *array = new int[length](); // 0으로 초기화
    // int *array = new int[length]{1, 2, 3, 4, 5};

    array[0] = 1;
    array[1] = 2;
    for (int i=0 ; i < length ; ++i)
    {
        cout << (uintptr_t)&array[i] << " ";
        cout << array[i] << endl;
    }
    delete[] array;
    return (0);
}