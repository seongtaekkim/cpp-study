#include <string>
#include "Student.h"
#include "Teacher.h"
#include <vector>

class Lecture
{
private:
    std::string name;
    std::vector<Student*> studentList;
    Teacher teacher;
public:
    Lecture(const std::string name)
        : name(name) {}
    void    assignTeacher(const Teacher  &teacher)
    {
        this->teacher = teacher;
    }
    /* void    registerStudent(const Student  &student) // const ?
    {
        this->studentList.push_back(student);
    } */
    void    registerStudent(Student  *student) // const ?
    {
        this->studentList.push_back(student);
    }
    /* void study()
    {
        std::cout << this->name << " study " << std::endl << std::endl;
        for (auto &e : this->studentList)
            e.setLevelUp();
    } */
    void study()
    {
        std::cout << this->name << " study " << std::endl << std::endl;
        for (auto &e : studentList)
            e->setLevelUp();
    }
    std::string getName() const
    {
        return (this->name);
    }
    std::string getTeacherName() const
    {
        return (this->teacher.getName());
    }
    /* std::vector<Student> getStudentList() const
    {
        return (this->studentList);
    } */
    std::vector<Student*> getStudentList() const
    {
        return (studentList);
    }
};

std::ostream & operator << (std::ostream &out, const Lecture lecture)
{
    out << "lecture : " << lecture.getName() << std::endl;

    out << lecture.getTeacherName() << std::endl;
    for (auto &e : lecture.getStudentList())
    {
        out << *e << std::endl;
    }
    return (out);
}