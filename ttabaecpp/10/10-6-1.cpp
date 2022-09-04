
#include <iostream>
class IntArray
{
private:
    size_t m_length = 0;
    int *m_data = nullptr;
public:
    IntArray() {}
    IntArray(const int *list, size_t size)
        :m_length(size)
    {
        initialize();
        setData(list);
    }
    ~IntArray() 
    {
 //       delete[] this->m_data;
    }
    void initialize()
    {
        m_data = new int[this->m_length];
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
    void    push_back(const int &value)
    {

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
    const int arr[5] = {1,3,5,7,9};
    IntArray my_arr {arr, 5};
    std::cout << my_arr << std::endl;
    my_arr.resize(10);
    std::cout << my_arr << std::endl;
    my_arr.insertBefore(10, 1); // 1 10 3 5 7 9
    std::cout << my_arr << std::endl;
    my_arr.reset();
    std::cout << my_arr << std::endl;


    my_arr.remove(3); // 1 10 3 7 9
    //my_arr.push_back(13); // 1 10  3 7 9 13

   // std::vector<int> int_vec;
    //std::array<int, 10> int_arr;

    return (0);
}