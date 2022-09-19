#include <string>
#include <iostream>
#include <vector>

int main(void)
{
    using namespace std;

    string str1("one");
    string str2;
    str2 = str1;
    str2 = "two";
    str2.assign("two").append("three").assign("four");


    cout << str1 << " " << str2 << endl;
    std::swap(str1, str2);
    cout << str1 << " " << str2 << endl;

    str1.swap(str2),

    cout << str1 << " " << str2 << endl;

    str2.swap(str1);
    cout << str1 << " " << str2 << endl;
    
    
    str1.append("three");
    cout << str1 << endl;
    
    str1 += "three";
    cout << str1 << endl;
    
    str1 = str2 + "five";
    cout << str1 << endl;
    
    str1.push_back('a');
    cout << str1 << endl;

    str1.insert(2,"kk");
    cout << str1 << endl;


   /*  string test1("1234567890");
    for (int i =0; i<100000000 ; i++)
        test1.append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
       //test1 += "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    cout << test1.size() << endl; */

    
    return (0);
}