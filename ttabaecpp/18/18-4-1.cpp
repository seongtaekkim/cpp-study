#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;


//https://cplusplus.com/reference/cctype/
void printCharacterClassification(const int & i)
{
    cout << boolalpha;
    cout << "isalnum " << bool(std::isalnum(i)) << endl;
    cout << "isblank " << bool(std::isblank(i)) << endl;    // cin에서 공백 구분을 못하므로, 체크하지 못함.
    cout << "isdigit " << bool(std::isdigit(i)) << endl;
    cout << "islower " << bool(std::islower(i)) << endl;
    cout << "isupper " << bool(std::isupper(i)) << endl;
}


//https://cplusplus.com/reference/ios/ios/rdstate/
void printStates(const std::ios& stream)
{
    cout << boolalpha;
    cout << "good()=" << stream.good() << endl;
    cout << "eof()=" << stream.eof() << endl;
    cout << "fail()=" << stream.fail() << endl;
    cout << "bad()=" << stream.bad() << endl;
}


bool isAllDigit(const string & str)
{
    bool ok_flag = true;
    for (auto e : str)
        if (!std::isdigit(e))
        {
            ok_flag = false;
            break ;
        }
    return (ok_flag);
}

bool classifyCaracters(const string & str)
{
    bool ok_flag = true;
    for (auto e : str)
    {
        cout << e << endl;
        cout << "isdigit " << std::isdigit(e) << endl;
        cout << "isblank " << std::isblank(e) << endl;
        cout << "isalpha " << std::isalpha(e) << endl;
    }
    return (ok_flag);
}


int main(void)
{

    while (true)
    {
        // char i;
        int i;
        cin >> i;
        printStates(cin);

        cout << boolalpha;
        cout << std::bitset<8>(cin.rdstate()) << endl;
        cout << std::bitset<8>(std::istream::goodbit) << endl;
        cout << std::bitset<8>(std::istream::failbit) << endl;
        cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;
        cout << (cin.rdstate() == std::istream::failbit) << endl;


        printCharacterClassification(i);

        cin.clear();
        cin.ignore(1024, '\n');
        cout << endl;
    }


    // 정규표현식이 더 나은 방법
    /* cout << boolalpha;
    cout << isAllDigit("1234") << endl;
    cout << isAllDigit("a1234") << endl; */


    /* classifyCaracters("1234");
    classifyCaracters("a 1234"); */
    return (0);
} 