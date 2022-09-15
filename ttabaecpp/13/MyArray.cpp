#include "MyArray.h"

template<typename T>
void    MyArray<T>::print()
{
    for (int i = 0 ; i< m_length ; i++)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}

// 자료형이 아닌 템플릿 매개변수는 explicit instanciation 할 때, 모든 케이스 (값)에 대해
// 작성해야 하므로,
// explicit instanciation 할수 있는 방법이 없어 보인다.
// => cpp에 구현을 하지 않고 헤더에 구현한다.

template class MyArray<char>;
template class MyArray<double>;
//template void MyArray<char>::print();
//template void MyArray<double>::print();