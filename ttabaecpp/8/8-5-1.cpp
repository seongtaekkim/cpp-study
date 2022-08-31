#include <iostream>
using namespace std;

class Student
{
private:
    int m_id;
    string m_name;
public:
    Student(const string& name_in)
        : Student(0, name_in) {}     // 위임생성자는 c++11 부터 사용가능
    Student(const int& id_n, const string &name_in)
        //: m_id(id_n), m_name(name_in) {}
        {
            init(id_n, name_in);
        }
    void print()
    {
        cout << m_id << " " << m_name << endl;
    }

    void init(const int& id_in, const string& name_in) // 초기화 함수를 따로 만들고 사용 하기도 함.
    {
        m_id = id_in;
        m_name = name_in;
    }
};

int main(int argc, char *argv[])
{
    Student s(1, "seongtki");
    return (0);
}