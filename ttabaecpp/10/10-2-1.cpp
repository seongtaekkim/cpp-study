#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

int main(void)
{
    using namespace std;
    
    Teacher t1("prof. hong");
    Teacher t2("prof. taek");
    Student s1("kim1", 0);
    Student s2("kim2", 1);
    Student s3("kim3", 2);

    Lecture lec1("introduction to computer programming");
    lec1.assignTeacher(t1);
    lec1.registerStudent(&s1);
    lec1.registerStudent(&s2);
    lec1.registerStudent(&s3);

    Lecture lec2("computational thingking");
    lec2.assignTeacher(t2);
    lec2.registerStudent(&s1);

    {
        cout << lec1 << endl;
        cout << lec2 << endl;

        lec2.study();

        cout << lec1 << endl;
        cout << lec2 << endl;
    }
    return (0);
}