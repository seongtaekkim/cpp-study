#include <iostream>
#include <cassert>

class IntList
{
private:
    int m_list[10] = {1,2,3,4,5,6,7,8,9,10};
public:
    void    setItem(int index, int value)
    {
        m_list[index] = value;
    }
    int getItem(int index)
    {
        return (m_list[index]);
    }
    int * getList()
    {
        return (m_list);
    }

    int & operator [] (const int index)
    {
        assert(index >= 0);
        assert(index < 10);

        return (m_list[index]);
    }
    const int & operator [] (const int index) const
    {
        assert(index >= 0);
        assert(index < 10);

        return (m_list[index]);
    }
};

int main(void)
{
    /* IntList my_list;
    my_list.setItem(3, 1);
    std::cout << my_list.getItem(3) << std::endl;
    my_list.getList()[3] = 10;
    std::cout << my_list.getList()[3] << std::endl; */

    const IntList my_list;
    //my_list[3] = 3;
    std::cout << my_list[3] << std::endl;

    IntList *list = new IntList;
    //list[3] = 10;
    (*list)[3] = 10;
    return (0);
}