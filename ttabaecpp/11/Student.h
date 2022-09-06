#include "Person.h"

class Student : public Person
{
private:
    int m_level;
public:
    Student() {}
    Student(const std::string &name, const int &level)
        : Person(name), m_level(level) {}
    int getLevel() const
    {
        return (m_level);
    }
    void    setLevelUp()
    {
        this->m_level += 1;
    }
    
};

std::ostream & operator << (std::ostream &out, const Student student)
{
    out << student.getName() << " " << student.getLevel();
    return (out);
}

