#include <string>

class Student
{
private:
    std::string m_name;
    int m_level;
public:
    Student() {}
    Student(const std::string &name, const int &level)
        : m_name(name), m_level(level) {}
    std::string getName() const
    {
        return (m_name);
    }
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

