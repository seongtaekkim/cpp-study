#include <iostream>
using namespace std;

class IntArray
{
private:
    int *m_arr = nullptr;
    int m_length = 0;
public:
    IntArray(const int length_in)
    {
        m_length = length_in;
        m_arr = new int[m_length];
    }
    ~IntArray()
    {
        if (m_arr != nullptr)
            delete[] m_arr;
    }
    int size() {
        return m_length;
    }
};
int main(int argc, char *argv[])
{
    while (true)
    {
        IntArray i(10);
    }
    return (0);
}