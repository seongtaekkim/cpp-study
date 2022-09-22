#include <iostream>
#include <regex> // begin c++11
using namespace std;

/*
    정규식
    https://cplusplus.com/reference/regex/ECMAScript/
*/
int main(void)
{
    //regex re("\\d");
    //regex re("\\d+"); // 1개 이이상상
    //regex re("\\d*"); // 검사안함
    //regex re("[[:digit:]]{3}"); // 숫자, 개수 :3개
    //regex re("[A-Z]+"); // 대문자, 1개이상
    //regex re("[A-Z]{1,5}"); // 대문자, 1~5개
    //regex re("([0-9]{1})([-]?)([0-9]{1,4})"); // ? : 검사안함 - 있어도 없어도 됨.
    
    
    string str;
    while (true)
    {
        getline(cin, str);
        if (std::regex_match(str, re))
            cout << "match" << endl;
        else   
            cout << "no match" << endl;
        
        // print matches
        {
            auto begin = std::sregex_iterator(str.begin(), str.end(), re);
            auto end = std::sregex_iterator();
            for (auto itr = begin; itr != end; ++itr)
            {
                std::smatch match = *itr;
                cout << match.str() << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
    return (0);
}