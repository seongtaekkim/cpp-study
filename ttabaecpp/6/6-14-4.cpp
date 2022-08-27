#include <iostream>

using namespace std;

void printElements(int (&arr)[5])
{
    cout << arr << endl;
    arr[0] = 100;
    for (int i =0; i< 5 ; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    const int length = 5;
    int arr[length] = {1,2,3,4,5};
    cout << arr << endl;
    printElements(arr);
    cout << arr[0] << endl;
    return (0);
}