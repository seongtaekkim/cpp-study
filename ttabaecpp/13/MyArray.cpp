#include "MyArray.h"

template<typename T>
void    MyArray<T>::print()
{
    for (int i = 0 ; i< m_length ; i++)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}

// explicit instantiation
// 특정타입으로 컴파일 해야 한다고 명시

template class MyArray<char>;
template class MyArray<double>;
//template void MyArray<char>::print();
//template void MyArray<double>::print();