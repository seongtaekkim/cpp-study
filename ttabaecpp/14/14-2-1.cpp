#include <iostream>
using namespace std;


//void last() throw() // 인자없는 throw는 예외가 없다고 명시 : 예외가발생하면 컴파일 에러 발생
void last() throw(int) // 예외 인자가 꼭 실제 예외를 의미하지 않음.
{
    cout << "last" << endl;
    cout << "throws exception " << endl;

    throw -1;

    cout << "end last" << endl;
}

void third()
{
    cout << "third" << endl;

    last();

    cout << "end third" << endl;
}

void second()
{
    cout << "second" << endl;
    try
    {
        third();
    }
    catch(double)
    {
        cerr << "second caught double exception " << endl;
    }
    
}

void first()
{
    cout << "first" << endl;
    try
    {
        second();
    }
    catch(int)
    {
        cerr << "first caught int exception " << endl;
        throw;
    }
    
}

int main(void)
{
    cout << "start" << endl;
    try
    {
        first();
    }
    /* catch(int)
    {
        cerr << "main caught int exception " << endl;
    } */
    catch(...)
    {
        cerr << "main caught ellipses exception "<< endl;
    }
    cout << "end main" << endl;
    return (0);
}