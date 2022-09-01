#include <iostream>
using namespace std;

class Simple
{
private:
    int m_id;
    int m_id2;
public:
    Simple(int id)
    {
        this->setId(id); // this 키워드로 인스턴스의 맴버변수, 맴버함수를 가리킬 수 있음.
        cout << this << endl; // 자기자신의 주소를 출력
        cout << &(this->m_id2) << &m_id2 << endl; 
    }
    void setId(int id)
    {
        this->m_id = id;
    }
    int getId()
    {
        return (this->m_id);
    }
};

int main(int argc, char *argv[])
{
    Simple s1(1), s2(2);
    s1.setId(2);
    s2.setId(4);
    cout << &s1 << " " << &s2 << endl;
    
    return (0);
}