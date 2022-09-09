#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int size>
class StaticArray_Base
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

    // 함수 내부에 this는 대체 어떻게 어딜 가르키나 ?>
    void print()
    {
        for (int c=0 ; c<size; c++)
            cout << (*this)[c] << ' ';
        cout << endl;
    }
};

template <class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{
};

// specialization 할 함수가 속한 class를 상속한 후, 
// 자식클래스를 class specialization 한다.
// 이렇게 매개변수 중 부분만 특수화하는 것을 부분특수화 라고 한다.
template <int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
    void print()
    {
        for (int c=0 ; c<size; c++)
            cout << (*this)[c];
        cout << endl;
    }
};


int main(void)
{
    StaticArray<int, 4> int4;
    int4[0] = 1;
    int4[1] = 2;
    int4[2] = 3;
    int4[3] = 4;
    int4.print();

    StaticArray<char, 14> char14;
    char14[0] = 'H';
    char14[1] = 'e';
    strncpy(char14.getArray(), "Hello, World", 14);
    char14.print();
    return (0);
}