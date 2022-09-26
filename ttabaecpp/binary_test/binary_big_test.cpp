#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit
#include <sstream>

using namespace std;


int main(void)
{

    // askii 느림 binary 빠름
    /* ofstream ofs("test");
    //ofs.open("test.txt") // same 
    if (!ofs)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    } */
/*     ofstream ofs("test");
    const unsigned num_data = 1010;
    ofs.write((char *)&num_data, sizeof(int)); */



/* ➜  binary_test git:(main) ✗ time ./a.out 
./a.out  9.45s user 4.19s system 95% cpu 14.222 total -> 3.7G
➜  binary_test git:(main) ✗ c++ test.cpp
➜  binary_test git:(main) ✗ time ./a.out
./a.out  70.76s user 16.36s system 98% cpu 1:28.17 total -> 8.3G */

    ofstream ofs("test");
    const unsigned num_data = 1000000000;
    ofs.write((char *)&num_data, sizeof(num_data));

    for (int i =0; i <= num_data ; i++)
    {
       // cout << i;
        ofs.write((char *)&i, sizeof(i));
    }
    //cout << endl;



    ofstream ofs2("test_ascii"); 
    if (!ofs2)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    }
    for ( int i = 0 ; i<= 1000000000 ; i++)
        ofs2 << i ;
 

    return (0);
}