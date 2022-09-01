#include <iostream>
using namespace std;

class Something
{
public:
    int m_value = 0;
    Something()
    {
        cout << "constructor " << endl;
    }
    Something(const Something& st_in) // 복사생성자가 default 로 있는데, 사용자가 다시 구현할 수 있다.
    {
        m_value = st_in.m_value;
        cout << "copy constructor" << endl;
    }
    void setValue(int value) {
        m_value = value;
    }
    int getValue() const {
        return m_value;
    }
};

void print(Something s) // 복사 생성자가 호출되어 인스턴스를 복사한다. (기본생성자를 호출하지 않음)
{
    cout << &s << endl;

    cout << s.m_value << endl;
}


void print2(const Something &s)
{
    cout << &s << endl;
    
    cout << s.getValue() << endl;
}

int main(int argc, char *argv[])
{
     Something s;
    //s.setValue(3);
    cout << &s << endl;
    print(s);
    print2(s);
    cout << s.getValue() << endl;

    return (0);
}