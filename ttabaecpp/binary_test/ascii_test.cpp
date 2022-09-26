#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
struct A {
    std::string mystr;
    int myint;
};
 
int main() {

    
    unsigned long long   i = 4294967295; // 2^32 -1 // 4바이트 이상 담을 수 가 없음 ...

    ofstream ofs2("test_ascii"); 
    if (!ofs2)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    }
    ofs2 << i ;



}
