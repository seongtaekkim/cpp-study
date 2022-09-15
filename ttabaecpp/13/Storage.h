#pragma once

#include <iostream>

template<typename T>
class Storage
{
private:
    int m_value;
public:
    Storage(T value)
        : m_value(value)
    {}
    ~Storage()
    {

    }
    void    print()
    {
        std::cout << m_value << std::endl;
    }

};

// function specialization 구현
// cpp로 옮기면 컴파일러는 이 기능을 인식하지 못한다.
// 헤더에 그냥 구현 하던지, cpp에 소스를 넣고 include 하던지, 헤더를 여러개 쓰던지
template<>
void    Storage<double>::print()
{
    std::cout << "double type ";
    std::cout << std::scientific << m_value << '\n';
}