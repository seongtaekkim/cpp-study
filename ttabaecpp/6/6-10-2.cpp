#include <iostream>

using namespace std;

const char* getName()
{
    return "jack jack";
}

int main(void)
{
    int int_arr[5] = {1, 2, 3, 4, 5};
    char char_arr[] = "hello woarld";
    const char *name = "jack jack";

    cout << int_arr << endl; 
    cout << char_arr << endl; // cout에서 문자열은 특별 취급하여 주소가 아닌, 문자열을 출력함.
    cout << name << endl;
    return (0);
}