#include <iostream>
#include <cassert>
#include <initializer_list> // c++11

using namespace std;

class IntArray
{
private:
    unsigned m_length;
    int *m_data ;
public:
    IntArray() {}
    IntArray(unsigned length)
        :m_length(length)
        {
            m_data = new int[length];
        }
    IntArray(const std::initializer_list<int> &list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto & e : list)
        {
            m_data[count] = e;
            ++count;
        }
    }

    IntArray & operator = (const IntArray & source)
    {
        cout << "assigment operator " << endl;

        // 같은객체에 대입하면 문제가 발생할 수 있어 예외처리
        if (this == &source)
            return *this;

        if (m_data != nullptr)
            delete[] m_data;
        m_length = source.m_length;
        if (source.m_data != nullptr)
        {
            m_data = new int[m_length];
            for (int i=0 ; i < m_length ; i++)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
        return (*this);
    }

    ~IntArray()
    {
        delete[] this->m_data;
    }
    int *getData()
    {
        return (m_data);
    }
    unsigned getLength()
    {
        return (m_length);
    }

};

ostream & operator << (ostream &out, IntArray &arr)
{
    for(unsigned i = 0; i < arr.getLength() ; ++i)
        out << arr.getData()[i] << " ";
    return (out);
}

int main(void)
{
    int my_arr1[5] = {1,2,3,4,5};
    int *my_arr2 = new int[5]{1,2,3,4,5};

    //auto il = {1,2,3,};
    initializer_list<int> il = {1,2,3};
    cout << il.size() << endl;
    IntArray int_array {1,2,3,4,5};
    cout << int_array << endl;


    // 동적할당 여부에 대한 생각
    IntArray int_array2 {1};
    int_array2 = {1,2,3,4,5};
    cout << int_array2 << endl;
}