#include <iostream>
#include <array>
#include <algorithm>
using namespace std;


int main(void)
{
    array<int, 5> my_arr = {5, 4, 3, 2, 1};


    // 참조변수를 이용하면, 값복사를 하지 않으므로 효율적
    for (int &element : my_arr)
        cout << element << " ";
    cout << endl;

    sort(my_arr.begin(), my_arr.end()   );
    
    for (int &element : my_arr)
        cout << element << " ";
    cout << endl;
     return (0);
}