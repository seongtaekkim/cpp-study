#pragma once

#include <iostream>


// mini std::auto_ptr; since c++98, c++11 부터 사용안하기로, c++17 부터 해당기능 삭제.
// 이유는 복잡한상황에서 해당 라이브러리가 할 수 없는 일을 대체할 수 있는 라이브러리가 존재하기 때문.
template<class T>
class AutoPtr
{
public:
    T *m_ptr = nullptr;
public:
    AutoPtr(T *ptr = nullptr)
        : m_ptr(ptr)
    {

    }
    ~AutoPtr()
    {
        if (m_ptr != nullptr)
            delete m_ptr;
    }

    AutoPtr(AutoPtr &a)
    {
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }
    AutoPtr & operator = (AutoPtr &a)
    {
        if (&a == this)
            return (*this);
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return (*this);
    }
    
    T& operator*() const
    {
        return (*m_ptr);
    }
    T* operator->() const
    {
        return (m_ptr);
    }
    bool isNull() const
    {
        return (m_ptr == nullptr);
    }
};