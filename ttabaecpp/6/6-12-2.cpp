#include <iostream>

using namespace std;

int main(void)
{
   // int fixedArray[] = {1, 2, 3, 4, 5};
    
    int *array = new int[5]();
    // size를 반드시 입력해야 한다.
    cout << *array << endl;
    // resizing
    // 더 큰 메모리를 할당받아서 복사하고, 새로운 데이터를 넣는다.
    // vector 에서 해주는 기능
    delete[] array;
    return (0);
}