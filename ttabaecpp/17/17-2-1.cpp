#include <string>
#include <cstddef>
#include <iostream>
#include <locale>

#include <vector>
#include <sstream>
using namespace std;

template <typename T>
std::string ToString(T x)
{
    std::ostringstream osstream;
    osstream << x;
    //cout << "out : " << osstream.str() << endl;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string & str, T &x)
{
    std::istringstream isstream(str);
    //cout << (isstream >> x) << endl;
    //cout << "is : " << isstream.str() << endl;

    return (isstream >> x) ? true : false;
}

int main(void)
{

    //std::string my_string("my string");
    const char * my_string = "my string";
    cout << my_string << endl;

    cout << "========================== " << endl << endl;



    std::vector<char> vec;
    for (auto e : "today is a good day.")
        vec.push_back(e);
    std::string second_string(vec.begin(), vec.end());
    //std::string second_string(vec.begin(), std::find(vec.begin(), vec.end(), 'g'));
    std::cout << second_string << std::endl;

    cout << "========================== " << endl << endl;


    std::string my_str(std::to_string(1004));

    my_str += std::to_string(128);

    int i = std::stoi(my_str);
    float f = std::stof(my_str);

    std::cout << my_str << std::endl;
    std::cout << i << std::endl;
    std::cout << f << std::endl;
    cout << "========================== " << endl << endl;

    std::string my_str2(ToString("3.141592"));
    std::cout << my_str2 << std::endl;

    double d;
    if (FromString(my_str2, d))
        std::cout << d << std::endl;
    else    
        std::cout << "Cannot convert string to double" << std::endl;
    return (0);
}