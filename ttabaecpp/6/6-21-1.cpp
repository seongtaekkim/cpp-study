#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
    vector<int> array;

    vector<int> array2 = {1,2,3,4,5};

    cout << array2.size() << endl;

    vector<int> array3 {1,2,3,4,5};
    cout << array3.size() << endl;


    vector<int> arr = {1,2,3,4,5};
    for (auto &itr : arr)
        cout << itr << " ";
    cout << endl;

    arr.resize(10);

    for (auto &itr : arr)
        cout << itr << " ";
    cout << endl;
         return (0);

         // delete 가 자동으로 됨
}