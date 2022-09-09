#include "MyArray2.h"

int main(void)
{

    // 자료형이 아닌 템플릿 매개변수는 컴파일 타임에 결정이 되는 자료형만 들어올 수 있다 (변수 x)
    MyArray<double, 100> my_array(10);
    for (int i=0; i<my_array.getLength(); i++)
        my_array[i] = i * 10;
    my_array.print();
    return (0);
}