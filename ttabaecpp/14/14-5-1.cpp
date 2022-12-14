#include <iostream>
using namespace std;

class A
{
private:
    int m_x;
public:
    A(int x) : m_x(x)
    {
        if (x <= 0)
            throw 1;
    }
};

class B : public A
{
public:
   /*  B(int x)
        : A(x)
    {} */
    B(int x) try :A(x)
    {
        // do initialization
    }
    catch (...)
    {
        cout << "catch in B constructor" << endl;
       // throw;
    }
};

void doSomething()
try
{
    throw -1;
}
catch(...)
{
    cout << "catch in doSomething()" << endl;
}


// class 생성자에서는 try catch 시 throw; 없이도 호출자로 throw 함.
int main(void)
{
    try
    {
      //  doSomething();
      B b(0);
    }
    catch(...)
    {
        cout << "catch in main()" << endl;
    }
    
    return (0);
}