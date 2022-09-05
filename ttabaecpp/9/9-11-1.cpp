#include <cassert>
#include <iostream>
using namespace std;

class MyString
{
//private:
public:
    char *m_data = nullptr;
    int m_length = 0;
public:
    MyString(const char *source = "")
    {
        assert(source);

        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];
        m_data[m_length - 1] = '\0';
    }

    MyString(const MyString &source)
    {
        cout << "copy constructor " << endl;

        m_length = source.m_length;
        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];
            for (int i =0; i< m_length ; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }

    MyString & operator = (const MyString & source)
    {
        cout << "assigment operator " << endl;

        // 같은객체에 대입하면 문제가 발생할 수 있어 예외처리
        if (this == &source)
            return *this;

        delete[] m_data;
        m_length = source.m_length;
        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];
            for (int i=0 ; i < m_length ; i++)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
        return (*this);
    }

    ~MyString()
    {
        delete[] m_data;
    }
    char *getString() {
        return (m_data);
    }
    int getLength() {
        return (m_length);
    }
};
 


int main()
{
    MyString hello("hello");

    cout << (int*)hello.m_data << endl;
    cout << hello.getString() << endl;

    {
        MyString copy = hello; // copy constructor 호출
        cout << (int*)copy.m_data << endl;
        cout << copy.getString() << endl;
    }

    cout << hello.getString() << endl;

    MyString hello2("hello");
    MyString str1(hello2);
    MyString str2;
    str2 = hello2;
}