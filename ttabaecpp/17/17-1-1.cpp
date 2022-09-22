#include <string>
#include <cstddef>
#include <iostream>
#include <locale>

int main(void)
{
    // c-style string example
    {
        char *strHello = new char[7];
        strcpy(strHello, "hello");
        std::cout << strHello << std::endl;
    }

    // basic string 구조 파악하기
    // basic_string<>, string, wstring
    // basic_string<string>. basic_string<wstring>
    {
        std::string string;
        std::wstring wstring;

        wchar_t wc; // wide-character/unicode
                    // 여러국가에서 사용할 프로그램을  만들경우 사용함.
    }

    // wstring example
    {
        using std::wcout;
        using std::endl;

        const wchar_t * const texts[] = {
        L"안녕하세요",
        L"Ñá", //Spanish
        L"forêt intérêt", //French
        L"Gesäß", //German
        L"取消波蘇日奇諾", //Chinese
        L"日本人のビット", //Japanese
        L"немного русский", //Russian
        L"ένα κομμάτι της ελληνικής", // Greek
        L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
        L"کمی از ایران ", // Persian (I know it, from 300 movie)
        L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
        L"Но какво, по дяволите, е това?" //Bulgarian
        };
        std::locale::global(std::locale(""));
        wcout.imbue(std::locale());

        for ( size_t i = 0; i < 11; ++i )
            wcout << texts[i] << endl;
    }

    return (0);
}