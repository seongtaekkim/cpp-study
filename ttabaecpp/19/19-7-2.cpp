#include <iostream>
#include <vector>
#include <cstdio>
#include <utility> // std::forward

using namespace std;

class CustomVector
{
public:
    unsigned n_data = 0;
    int *ptr = nullptr;

    CustomVector(const unsigned & _n_data, const unsigned & _init = 0)
    {
        cout << "constructor" << endl;
        init(_n_data, _init);
    }

    CustomVector(CustomVector & l_input)
    {
        cout << "copy constructor " << endl;
        init(l_input.n_data);

        for (unsigned i = 0 ; i< n_data ; i++)
            ptr[i] = l_input.ptr[i];
    }

    CustomVector(CustomVector && r_input)
    {
        cout << "move constructor " << endl;
        n_data = r_input.n_data;
        this->ptr = r_input.ptr;

        r_input.n_data = 0;
        r_input.ptr = nullptr;
    }

    ~CustomVector()
    {
        delete[] ptr;
    }

    void init(const unsigned & _n_data, const int & _init =0)
    {
        n_data = _n_data;
        ptr = new int[n_data];
        for (unsigned i = 0; i < n_data ; i++)
            ptr[i] = _init;
    }

};

void doSomething(CustomVector & vec)
{
    cout << "pass by l-reference " << endl;
    CustomVector new_vec(vec);
}
void doSomething(CustomVector && vec)
{
    cout << "pass by r-reference" << endl;
    CustomVector new_vec(std::move(vec));
    //CustomVector new_vec(vec); // 이렇게하면 l-value 로 받게된다.
                                // vec을 r-value로 받지만, vec 자체는 l-value이기 때문이다.
}


/*
    && : perfact forwarding 을 위해 파라메터에 작성.
    std::forward : 파라메터 객체 vec이 r-value 이면 r-value로, l-value이면 l-value로 인자를 넘겨준다.
*/
template<typename T>
void doSomethingTemplate(T && vec)
{
    doSomething(std::forward<T>(vec));
}

int main()
{
    CustomVector my_vec(10, 1024);

    //CustomVector temp(my_vec);
    //CustomVector temp(std::move(my_vec));
    //cout << my_vec.n_data << endl;

    //doSomething(my_vec);
    //doSomething(CustomVector(10, 7));

    doSomethingTemplate(my_vec);
    doSomethingTemplate(CustomVector(10, 7));

}