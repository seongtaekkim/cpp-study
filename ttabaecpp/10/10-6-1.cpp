
#include <iostream>
using namespace std;

class IntArray
{
private:
    size_t m_length = 0;
    int *m_data = nullptr;
public:
    IntArray() {}
    IntArray(unsigned length)
        :m_length(length)
    {
        m_data = new int[length];
    }
    ~IntArray() 
    {
 //       delete[] this->m_data;
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

    void initialize()
    {
        //m_data = new int[this->m_length];
    }
    void    setData(const int *list)
    {
        size_t index;

        index = 0;
        while (index < this->m_length)
        {
            m_data[index] = list[index];
            index++;
        }
    }
    void    reset()
    {
        delete[] this->m_data;
        this->m_length = 0;
    }
    void    resize(const int & size)
    {
        int *tmpData;
        int index;

        index = 0;
        tmpData = new int[this->m_length];
        while (index < this->m_length)
        {
            tmpData[index] = this->m_data[index];
            index++;
        }
        delete[] this->m_data;
        this->m_data = new int[size];
        setData(tmpData);
        this->m_length = size;
        delete[] tmpData;
    }
    size_t  getSize()
    {
        return (this->m_length);
    }
    int *getData()
    {
        return (this->m_data);
    }
    void    insertBefore(const int & value, const int & ix)
    {
        if (this->m_length - 1 < ix)
            return ;
        int *tmpData;
        int index;

        index = 0;
        tmpData = new int[this->m_length];
        while (index < this->m_length)
        {
            tmpData[index] = this->m_data[index];
            index++;
        }
        delete[] this->m_data;
        this->m_data = new int[this->m_length + 1];
        index = 0;
        while (index < ix)
        {
            this->m_data[index] = tmpData[index];
            index++;
        }
        this->m_data[index++] = value;
        while (index < this->m_length + 1)
        {
            this->m_data[index] = tmpData[index - 1];
            index++;
        } 
        this->m_length += 1;
        delete[] tmpData;

    }
    void    remove(const int & ix)
    {
        if (this->m_length - 1 < ix)
            return ;
        int *tmpData;
        int index;

        index = 0;
        tmpData = new int[this->m_length];
        while (index < this->m_length)
        {
            tmpData[index] = this->m_data[index];
            index++;
        }
        delete[] this->m_data;
        this->m_data = new int[this->m_length - 1];
        index = 0;
        while (index < ix)
        {
            this->m_data[index] = tmpData[index];
            index++;
        }
        index++;
        while (index < this->m_length)
        {
            this->m_data[index - 1] = tmpData[index];
            index++;
        } 
        this->m_length -= 1;
        delete[] tmpData;
    }
    void    push_back(const int &value)
    {
        int *tmpData;
        int index;

        index = 0;
        tmpData = new int[this->m_length];
        while (index < this->m_length)
        {
            tmpData[index] = this->m_data[index];
            index++;
        }
        delete[] this->m_data;
        this->m_data = new int[this->m_length + 1];
        index = 0;
        while (index < this->m_length)
        {
            this->m_data[index] = tmpData[index];
            index++;
        }
        this->m_data[index] = value;
        this->m_length += 1;
        delete[] tmpData;
    }
};

std::ostream & operator << (std::ostream &out, IntArray arr)
{
    int index;

    index = 0;
    while (index < arr.getSize())
    {
        out << arr.getData()[index++] << " ";
    }
    return (out);
}

int main(void)
{
    IntArray my_arr = {1,3,5,7,9};
    std::cout << my_arr << std::endl;
    my_arr.resize(10);
    std::cout << my_arr << std::endl;
    my_arr.insertBefore(10, 1); // 1 10 3 5 7 9
    std::cout << my_arr << std::endl;
    //my_arr.reset();
    my_arr.remove(3); // 1 10 3 7 9
    std::cout << my_arr << std::endl;
    my_arr.push_back(13); // 1 10  3 7 9 13
    std::cout << my_arr << std::endl;
    return (0);
}