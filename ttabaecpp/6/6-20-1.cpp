#include <iostream>
#include <array>

using namespace std;


// 배열을 인자로 받으면 array가 복사가 됨, 레퍼런스로 받으면 같은 주소를 사용함 
void printLength(array<int , 5> &my_arr)
{
    cout << &my_arr << endl;
        cout << my_arr.size() << endl; 
}

int main(void)
{
    //int arrays[5] = {1, 2, 3, 4, 5};

    array<int, 5> my_arr = {1, 2, 3, 4, 5};

    // c++11 부터 가능함
    //my_arr = {0, 1, 2, 3, 4};
    //my_arr = {0, 1, 2};

    cout << my_arr[0] << endl;
    cout << my_arr.at(2) << endl; // outof range : runtime error
    cout << my_arr.size() << endl; 
    printLength(my_arr);
    cout << &my_arr << endl;

     return (0);
}