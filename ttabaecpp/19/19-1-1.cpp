#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void goodbye(const string &s)
{
    cout << "Goodbye " << s << endl;
}

class Object
{
public:
    void hello(const string &s)
    {
        cout << "hello" << s << endl;
    }
};

int main(void)
{
    // lambda-introducer
    // lambda-parameter-declaration
    // lambda-return-type-clause
    // compound-statement
    auto func = [](const int& i) -> void { cout << "hello" << endl;};

    func(123);

    [](const int& i) -> void {cout << "hello " << endl;} (1234);
    
    {
        string name = "staack";
        [&]() {cout << name << endl;} ();
        //[&name]() {cout << name << endl;} ();
        //[=]() {cout << name << endl;} (); // copy
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    auto func2 = [](int val) {cout << val << endl;};
    for_each(v.begin(), v.end(), func2);
    //for_each(v.begin(), v.end(), [](int val) {cout << val << endl;});

    cout << []() -> int {return 1;}() << endl;

    std::function<void(int)> func3 = func2;
    func3(123);
    func3(1234);

    // parameter 를 생략하기위해 bind함수를 사용.
    std::function<void()> func4 = std::bind(func3, 456);
    func4();

    {
        Object instance;
        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

        f(string("hello"));
        auto f2 = std::bind(&goodbye, std::placeholders::_1);

        f2(string("world"));
    }



    return (0);
}