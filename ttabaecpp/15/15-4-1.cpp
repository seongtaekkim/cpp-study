//#include "timer.h"
#include "AutoPtr2.h"
#include "Resource.h"
#include <vector>
template<class T>
void mySwap(T &a, T &b)
{
   // T tmp = a;
   // a = b;
   // b = tmp;

    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

int main(void)
{
    using namespace std;
/*     {
        AutoPtr<Resource> res1(new Resource(1000000));
        cout << res1.m_ptr << endl;
    
        //AutoPtr<Resource> res2 = res1;
        AutoPtr<Resource> res2 = std::move(res1);

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    } */

     /* {
        AutoPtr<Resource> res1(new Resource(3));
        
        res1->setAll(3);
        
        AutoPtr<Resource> res2(new Resource(5));
        res2->setAll(5);

        res1->print();
        res2->print();

        mySwap(res1, res2);

        res1->print();
        res2->print();
        
    }  */

/*     {
        cout << "===========================\n" << endl;
        vector<string> v;
        string str = "hello";
        v.push_back(str);

        cout << str << endl;
        cout << v[0] << endl;

        //v.push_back(std::move(str));
        v.push_back((str));

        cout << str << endl;
        cout << v[0] << " " << v[1] << endl;
    } */
    
/*     {
        cout << "===========================\n" << endl;
        string x("abc");
        string y("de");

        cout << "x: " << x << endl;
        cout << "y: " << y << endl;

        mySwap(x, y);

        cout << "x: " << x << endl;
        cout << "y: " << y << endl;

    } */
    return (0);
}