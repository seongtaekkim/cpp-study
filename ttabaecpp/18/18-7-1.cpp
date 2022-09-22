#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit
#include <sstream>

using namespace std;

int main(void)
{

    const string filename = "test.txt";

    // make a file
    {
        ofstream ofs(filename);
        for (char i = 'a' ; i <= 'z' ; i++)
            ofs << i;
        ofs << endl;
    }

    // read the file
    {
        ifstream ifs(filename);
        ifs.seekg(5); // ifs.seekg(5, ios::beg); // beg : begin

        cout << (char)ifs.get() << endl;

        ifs.seekg(5, ios::cur); // 현재 위치에서 5바이트 이동 후.
        cout << (char)ifs.get() << endl;

        ifs.seekg(-5, ios::end);

        cout << ifs.tellg() << endl; // 현재 위치

        string str;
        getline(ifs, str);
        cout << str << endl;

    }

    {
        //fstream iofs(filename, ios::in | ios::out);
        fstream iofs(filename);

        iofs.seekg(5);
        cout << (char)iofs.get() << endl; // read

        iofs.seekg(5);
        iofs.put('A');
    }
    return (0);
}