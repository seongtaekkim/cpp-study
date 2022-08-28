#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int fibonacci[] = {0, 1, 1, 2 ,3, 5, 8 ,13};
    
    

    // foreach : c++11
    // change arrayu values
    for (int &number : fibonacci)
        number = 10;

    // output
    for (const int &number : fibonacci)
        cout << number << " ";
    cout << endl;
    return (0);
}