#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    stringstream os;

    os << "helloee woard!"; // << : insertion overator, >> : extraction operator
    //os.str("hello world"); // 기존 버퍼를 없애고 할당됨.

    os << "and hi"; // 기존 버퍼에 append 됨.
    string str;
    os >> str;

    cout << str << endl; // 문자열 잘림

    str = os.str();
    cout << str << endl;

    cout << "=======================" << endl << endl;

    stringstream os2;


    // 공백을 지우면 처음 변수에 버퍼를 모두 stream 한다.
    //os2 << "12345 67.89";

    int i = 12345;
    double d = 67.89;

    // 공백여부에 따라 버퍼가 변수로 stream되는 경우가 나뉜다.
    os2 << i << d ;
    //os2 << i << " " << d ; 
    

    string str1;
    string str2;
 
    os2 >> str1 >> str2;

    cout << str1 << " | "  << str2 << endl;


    return (0);
}