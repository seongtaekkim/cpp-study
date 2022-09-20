#include <iostream>
#include <string>
#include <iomanip> // input/output manipulators

using namespace std;

int main(void)
{
    {   
    char buf[10];
    cin >> buf;
    cout << buf << endl;
    }
    
    {   
    char buf[10];
    cin >> setw(5) >> buf;
    cout << buf << endl;
    cin >> setw(5) >> buf;
    cout << buf << endl;
    cin >> setw(5) >> buf;
    cout << buf << endl;
    }

    {
        char ch;
        while (cin >> ch)
            cout << ch;
    }
    {
        int i;
        float f;
        cin >> i >> f;
        cout << i << " " << f << endl;
    }

    {
        char ch;
        while (cin.get(ch))
            cout << ch;
        cout << endl;
    }

    {
        char buf[5];
        cin.get(buf, 5);
        cout << cin.gcount() << " " << buf << endl;
        cin.get(buf, 5);
        cout << cin.gcount() << " " << buf << endl;
    }

    {
        char buf[100];
        cin.getline(buf, 100);
        cout << cin.gcount() << " " << buf << endl;
        cin.getline(buf, 100);
        cout << cin.gcount() << " " << buf << endl;
    }

    {
        string buf;
        getline(cin, buf);
        cout << cin.gcount() << " " << buf << endl;
    }

    {
        char buf[1024];
        cin.ignore(2);
        cin >> buf;
        cout << buf << endl;
    }
    {
        char buf[1024];
        cout << (char)cin.peek() << endl;
        cin >> buf;
        cout << buf << endl;

        cin.unget();
        cin >> buf;
        cout << buf << endl;

        cin.putback('A');
        cin >> buf;
        cout << buf << endl;
    }

    return (0);
}