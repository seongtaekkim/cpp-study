#pragma once
#include <string>
#include <iostream>
class Person
{
private:
    std::string m_name;
public:
    Person()
        : m_name("no name")
    {}
    Person(const std::string &name_in)
        : m_name(name_in) {}
    std::string getName() const
    {
        return (m_name);
    }
    void setName(const std::string &name_in)
    {
        m_name = name_in;
    }
}; 