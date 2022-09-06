
#include "Student.h"
#include "Teacher.h"

int main(void)
{
    Student s("kim1", 1);
    s.setName("kim2");
    std::cout << s.getName() << std::endl;
    Teacher t1("dr a");
    return (0);
}