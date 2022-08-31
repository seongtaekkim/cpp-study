#include <iostream>
#include <string>
#include <vector>
using namespace std;


// friend : nname ,ad

/*
void print(const string &name ....)
{
    cout ...
}
*/

struct Friend_
{
    string name;
    string address;
    int age;
    double height;
    double weight;

    void print(const Friend &f)
    {
    cout << address << endl; // ..
    }
};


class Friend
{
public: // access specifier (public, private, protected)
    string name;
    string address;
    int age;
    double height;
    double weight;

    void print()
    {
    cout << address << endl; // ..
    }
};



int main(int argc, char *argv[])
{

    // step 1
    string name;
    string address;
    int age;
    double height;
    double weight;
    vactor<string> name_vec;
    vector<string> addr_vec;
    ...
    print(name, address, age, height, weight);
    print(name_vec[0], addr_vec[0] ...);


    // step 2
    Friend f {"seongtki", "address", 11, 111, 55}; // instanciation, instance
    cout << &f << endl;
    print(f);
    f.print();

    // step 3
    vector<Friend> my_f;
    my_f.resize(2);
    for (auto &e : my_f)
        e.print();

    return (0);
}