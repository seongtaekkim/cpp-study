#include <iostream>
#include <cstdlib>
using namespace std;

// https://www.inflearn.com/course/following-c-plus/unit/14796?category=questionDetail&tab=community&q=105164

template <class T, int size>
class StaticArray
{
private:
    T m_array[size];
public:
    T *getArray()
    {
        return (m_array);
    }
    T& operator[](int index)
    {
        return (m_array[index]);
    }
};

template <typename T, int size>
void print(StaticArray<T, size> &array)
{
    for (int c=0 ; c<size; c++)
        cout << array[c] << ' ';
    cout << endl;
}

// 함수 부분 스페셜라이제이션
template <int size>
void print(StaticArray<char, size> &array)
{
    for (int c=0 ; c<size; c++)
        cout << array[c];
    cout << endl;
}

int main(void)
{
    StaticArray<int, 4> int4;
    int4[0] = 1;
    int4[1] = 2;
    int4[2] = 3;
    int4[3] = 4;
    print(int4);

    StaticArray<char, 14> char14;
    char14[0] = 'H';
    char14[1] = 'e';
    strncpy(char14.getArray(), "Hello, World", 14);
    print(char14);
    return (0);
}