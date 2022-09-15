#include <iostream>
using namespace std;

class Exception
{
public:
    void report()
    {
        cerr << "Exception report" << endl;
    }
};

class ArrayException : public Exception
{
public:
    void report()
    {
        cerr << "ArrayException" << endl;
    }
};

class MyArray
{
private:
    int m_data[5];
public:
    int & operator [] (const int & index)
    {
        //if (index < 0 || index >= 5) throw -1;
        //if (index < 0 || index >= 5) throw Exception();
        if (index < 0 || index >= 5) throw ArrayException();
        return (m_data[index]);
    }
};

void doSomething()
{
    MyArray my_array;
    try
    {
        my_array[100];
    }
    /*  catch (ArrayException e)
    {
        e.report();
    }  */
    catch (Exception e)
    {
        e.report();
        //throw e;    // e의 클래스에 대한 예외를 throw함.
       throw ;    // 발생한 예외 클래스 자체를 throw 함
    }
    catch (const int &x)
    {
        cerr << "Exception " << x << endl;
    }
}

/*
    더 큰 범위를 케어하는 예외는 더 적은 범위를 포함하는 예외보다 앞에 나올 수 없다.
*/
int main(void)
{
    try
    {
        doSomething();
    }
   /*  catch(...)
    {
        cout << "el";
    } */
   /*  catch(ArrayException e)
    {
        e.report();
    }  */
     catch(Exception e)
    {
        e.report();
    } 

    return (0);
}