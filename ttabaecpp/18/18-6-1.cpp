#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit
#include <sstream>

using namespace std;

int main(void)
{
    // writing
    if(true)
    {
        // askii 느림 binary 빠름
        ofstream ofs("test.txt");  // ios::app -> append
                                   // , ios::binary
        //ofs.open("test.txt") // same 
        if (!ofs)
        {
            cerr << "Couldn't open file" << endl;
            exit(1);
        }

        /* ofs << "linie 1" <<endl; // 텍스트모드로 파일에 저장. 아스키포멧에 맞추어서 저장됨.
                                // 아스키는 느리므로 바이너리로 저장해야 함
        ofs << "linie 2 " <<endl; */

        // 데이터 범위를 약속해서 알고 있어야 한다. (어디까지 저장되는지 모름)
        const unsigned num_data = 10;
        ofs.write((char *)&num_data, sizeof(num_data));

        for (int i =0; i < num_data ; i++)
            ofs.write((char *)&i, sizeof(i));

/*
        stringstream ss;
        ss << "Line 1" << endl;
        ss << "Line 2" << endl;
        string str  = ss.str();

        unsigned str_length = str.size();
        ofs.write((char *)&str_length, sizeof(str_length));
        ofs.write(str.c_str(), str_length);

        ofs.close(); // not necessary */
    }

    //reading
    if (true)
    {
        ifstream ifs("test.txt");

        if (!ifs)
        {
            cerr << "cannot open file" << endl;
            exit(1);
        }

        /*
            ascii read
        */
        /* while (ifs)
        {
            std::string str;
            getline(ifs, str);
            
            cout << str << endl;
        } */

        /*
            binary read
        */
        unsigned num_data = 0;
        ifs.read((char *)&num_data, sizeof(num_data));

        for (unsigned i = 0 ; i<num_data ; i++)
        {
            int num;
            ifs.read((char *)&num, sizeof(num));
            cout << num << endl;
        }
/*
        unsigned str_len = 0;
        ifs.read((char *)&str_len, sizeof(str_len));

        string str;
        str.resize(str_len);
        ifs.read(&str[0], str_len);

        cout << str << endl;

        ifs.close(); */
    }
    return (0);
}