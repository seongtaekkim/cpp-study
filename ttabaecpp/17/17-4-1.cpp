#include <string>
#include <iostream>

int main(void)
{
    using namespace std;

    string my_str("abcdefg");
    cout << my_str[0] << endl;
    cout << my_str[3] << endl;

    try
    {
        /*
            매모리에 직접 접근은 속도는 빠르지만,
            exception정의가 안되어 있기 때문에 catch할 수 없어서 
            runtime error가 발생할 수 있다.
        */
        // my_str[100] = 'X'; // error ?
        
        /*
            string class 내부에 out of range에 대한 exception이 존재하기 때문에 
            catch가 가능하다.
            안전하지만, 속도는 메모리접근 방법에 비해 느리다.
        */
        my_str.at(100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout<< my_str <<endl;

    cout << my_str.c_str() << endl;
    const char *arr = my_str.c_str();
    cout << (int)arr[6] << endl;
    cout << (int)arr[7] << endl; // c_str변환 시, 문자열 마지막에 \0이 추가된다.

    char buf[20];
    my_str.copy(buf ,5, 1);
    buf[5] = '\0'; // c-style 문자열에 stirng을 복사할 경우, 문자열 마지막에 \0를 넣어 주어야 한다.
    cout << buf << endl;

    return (0);
}