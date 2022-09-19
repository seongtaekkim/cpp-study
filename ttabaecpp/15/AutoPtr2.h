#pragma once

#include <iostream>

template<class T>
class AutoPtr
{
public:
    T *m_ptr;
public:
    AutoPtr(T *ptr = nullptr)
        : m_ptr(ptr)
    {
        std::cout << "Autoptr default constructor " << std::endl;
    }
    ~AutoPtr()
    {
        std::cout << "Autoptr destructor " << std::endl;
        if (m_ptr != nullptr)
            delete m_ptr;
    }
    AutoPtr(const AutoPtr &a)
    {
        std::cout << "Autoptr copy constructor " << std::endl;
        
        //deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }
    AutoPtr & operator = (const AutoPtr &a)
    {
        std::cout << "Autoptr copy assignment " << std::endl;

        if (&a == this)
            return (*this);
        if (m_ptr != nullptr)
            delete m_ptr;
        // deep copy

        m_ptr = new T;
        *m_ptr = *a.m_ptr;
        a.m_ptr = nullptr;
        return (*this);
    }

    //AutoPtr(const AutoPtr &a) = delete;
    //AutoPtr & operator=(const AutoPtr &a) = delete;
 
    AutoPtr(AutoPtr&& a)
        : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
        std::cout << "Autoptr move constructor " << std::endl;
    }
    AutoPtr & operator=(AutoPtr&& a)
    {
        std::cout << "AutoPtr move assignment " << std::endl;
        if (&a == this)
            return (*this);
        if (!m_ptr)
            delete m_ptr;
        //shallow copy
        m_ptr = a.m_ptr; // resource copy asignment 호출을 안함.
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