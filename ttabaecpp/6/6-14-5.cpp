#include <iostream>

using namespace std;

struct Something
{
    int v1;
};

struct Other
{
    Something st;
};


int main(void)
{
    Other ot;

    int &v1 = ot.st.v1;
    v1 = 1;
    
    int value = 5;
    int *const ptr = &value;
    int &ref = value;

    *ptr = 10;
    ref = 10;
    return (0);
}