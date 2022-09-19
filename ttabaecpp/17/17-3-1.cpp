#include <string>
#include <iostream>

int main(void)
{
    using namespace std;

    string my_str("01234567");

    cout << my_str.size() << endl;
    cout << std::boolalpha;
    cout << my_str.empty() << endl;

    my_str = ""; // string 객체 내부에는 /0 을 포함하지 않음
                 // 내부적으로 길이를 포함하고 있기 때문에 필요하지 않음.
    //cout << my_str
    cout << my_str.size() << endl;
    cout << std::boolalpha;
    cout << my_str.empty() << endl;

    my_str = "01234567";
    cout << std::boolalpha;
    cout << my_str.length() << endl;
    cout << my_str.size() << endl;
    cout << my_str.capacity() << endl;
    cout << my_str.max_size() << endl; // 2^64
     my_str.reserve(1000);
    
    cout << my_str.length() << endl;
    cout << my_str.size() << endl;
    cout << my_str.capacity() << endl;

    return (0);
}