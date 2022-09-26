#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit
#include <sstream>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(void)
{

    const unsigned num_data = 1;


    ofstream ofs("test2");
    
    unsigned int   i = 4294967295; // 2^32 -1 // 4바이트 이상 담을 수 가 없음 ... unsigned long long 이 안됨
    cout << i << endl;
    ofs.write((char *)&num_data, sizeof(num_data));
    ofs.write((char *)&i, sizeof(i));


    ifstream ifs("test2");
    ifs.read((char *)&num_data, sizeof(num_data));


    unsigned int  num;
    ifs.read((char *)&num, 4);
    cout << num << endl;

    return (0);
}