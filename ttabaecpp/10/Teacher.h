#include <string>

class Teacher
{
private:
    std::string m_name;
public:
    Teacher() {}
    Teacher(const std::string &name)
        : m_name(name) {}
    std::string getName() const
    {
        return (m_name);
    }
};

std::ostream &operator << (std::ostream &out, const Teacher teacher)
{
    out << teacher.getName();
    return (out);
}