#include <iostream>
using namespace std;

class Something
{
public:
    string m_value = "default";
    const string& getValue() const  // const함수로 오버로딩이 가능하다.
    {
        cout << "const version" << endl;
        return m_value;
    }
    string& getValue()
    {
        cout << "non const version" << endl;
        return m_value;
    }
    
};

int main(int argc, char *argv[])
{
    const Something s;
    s.getValue();
    Something s2;
    s2.getValue();

    return (0);
}