#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    double x;
    cin >> x;

    try
    {
        //if (x < 0.0) throw std::string("Nagative input");
        if (x < 0.0) throw "Nagative input"; // const char*
      //  throw -1;
    }
    catch (double x)
    {
        cout << "INteger";
    }
    catch (const char *error_message)
    {
        cout << "char* "<< error_message << endl;
    }
    catch (std::string error_message)
    {
        cout << error_message << endl;
    }
    return (0);
}