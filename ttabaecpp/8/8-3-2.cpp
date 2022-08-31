#include <iostream>
using namespace std;

class Second
{
public:
    Second()
    {
        cout << "second constructor " << endl;
    }
};

class First
{
    Second sec; // 멤버를 먼저 초기화 하고나서 생성자를 호출함
   public:
    First()
    {
        cout << "first constructor " << endl;
    }
}; 


int main(int argc, char *argv[])
{
    First f;

    return (0);
}