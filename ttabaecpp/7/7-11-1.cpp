#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    vector<int> v {1,2,3};
    //size capacity
    v.resize(2);
    for (auto &e : v)
    //for (unsigned int i = 0; i< v.size() ; ++i;
        cout << e << " ";
    cout << endl;
    cout << v.size() << " " << v.capacity() << endl;;
    
    cout << v[2] << endl;
    //cout << v.at(2) << endl;
    
    int *ptr = v.data();
    cout << ptr[2] << endl;
    return (0);
}