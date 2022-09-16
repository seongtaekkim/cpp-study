#include <iostream>
#include "AutoPtr.h"
using namespace std;

class Resource
{
//private:
public:
    int m_data[100];
public:
    Resource()
    {
        cout << "resource constructed" << endl;
    }
    ~Resource()
    {
        cout << "resource destroyed" << endl;
    }
};

// RAII : resource acquisition is initialization
void doSomething()
{
 /*    try 
    {
        //Resource *res = new Resource; // dull pointer  // 해제 못할 수도 있는 포인터.
        AutoPtr<Resource> res = new Resource; // smart pointer
        if (true)
        {
             throw (-1);
            //return ; // early return
        }
        //delete res;
    }
    catch(...)
    {

    } */
    return ;
}

int main(void)
{
 //   doSomething();

 AutoPtr<Resource> res1(new Resource);
 // error : Resource *res = new Resource; 
 AutoPtr<Resource> res2;

 cout << std::boolalpha;

 cout << res1.m_ptr << endl;
 cout << res2.m_ptr << endl;

 res2 = res1; // move semantics

 cout << res1.m_ptr << endl;
 cout << res2.m_ptr << endl;


 // syntax vs. semantics



 // value semantics (copy semantics)
 // reference semantics (pointer)
 // move semantics (move)

// 우리는  move semantics를 구현한것이다.
    return (0);
}