#include <iostream>
#include <string>
#include <iomanip> // input/output manipulators

using namespace std;

int main(void)
{
    {   
        // buffer 최대치를 넘어가면 runtime error
        char buf[10];
        cin >> buf;
        cout << buf << endl;
    }
    
    {   
        // setw : 최대 입력받는 글자를 제한
        char buf[10];
        cin >> setw(5) >> buf;
        cout << buf << endl;
        cin >> setw(5) >> buf;
        cout << buf << endl;
        cin >> setw(5) >> buf;
        cout << buf << endl;
    }

    {
        // 버퍼로부터 글자를 계속가져우는데, cin이라서 공백을 무시하고 출력함.
        char ch;
        while (cin >> ch)
            cout << ch;
    }

    {
        // cin공백 특징을 이용해서 두개변수에 각각 stream 할 수 있다.
        int i;
        float f;
        cin >> i >> f;
        cout << i << " " << f << endl;
    }

    {
        // cin.get() 은 공백을 인식하고 출력한다.
        char ch;
        while (cin.get(ch))
            cout << ch;
        cout << endl;
    }

    {
        // get 두번 째 인자는 버퍼에 최대 입력가능 크기를 나타냄
        char buf[5];
        cin.get(buf, 5);
        cout << cin.gcount() << " " << buf << endl;
        cin.get(buf, 5);
        cout << cin.gcount() << " " << buf << endl;
    }

    {
        // getline : 한 줄 단위로 읽어들임. (줄바꿈까지 같이 읽어들임)
        char buf[100];
        cin.getline(buf, 100);
        cout << cin.gcount() << " " << buf << endl;
        cin.getline(buf, 100);
        cout << cin.gcount() << " " << buf << endl;
    }

    {
        // cin 으로 getline 을 호출하지 않았기 때문에 gcount는 0이다.
        string buf;
        getline(cin, buf);
        cout << cin.gcount() << " " << buf << endl;
    }

    {
        char buf[1024];
        cin.ignore(2); // 입력된 문자 중 byte 수 만큼 제외한다.
        cin >> buf;
        cout << buf << endl;
    }
    {
        /// peek : 데이터를 꺼내지는 않고 가져오기만 한다.
        char buf[1024];
        cout << (char)cin.peek() << endl;
        cin >> buf;
        cout << buf << endl;

        // unget : 마지막으로 읽은 문자를 다시 버퍼에 넣는다.
        cin.unget();
        cin >> buf;
        cout << buf << endl;

        // putback : 원하는 문자를 다시 버퍼에 넣는다.
        cin.putback('A'); 
        cin >> buf;
        cout << buf << endl;
    }

    return (0);
}