#include "Person.h"

class Teacher : public Person
{
private:

public:
    Teacher() {}
    Teacher(const std::string &name)
        : Person(name) {}
};

std::ostream &operator << (std::ostream &out, const Teacher teacher)
{
    out << teacher.getName();
    return (out);
}