#include <iostream>
#include <exception>
#include <string>
using namespace std;

class CustomeException : public std::exception
{
public:
    const char * what() const noexcept override // noexcept : c++11 
    {
        return "Custom exception";
    }
};
int main(void)
{
    try
    {
        //std::string s;
        //s.resize(-1);

        // throw std::runtime_error("bas thing happend");
        throw CustomeException();
    }
    catch(const std::length_error& e)
    {
        cout << typeid(e).name() << endl;
        cerr << e.what() << endl;
    }
    catch(const std::exception& e)
    {
        cout << typeid(e).name() << endl;
        cerr << e.what() << endl;
    }
    
    return (0);
}