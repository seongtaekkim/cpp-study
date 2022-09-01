#include <iostream>
using namespace std;


class B; // forward declaration

class A
{
private:
    int m_value = 1;

    friend void doSomething(A& a, B& b);
};

class B
{
private:
    int m_value = 2;

    friend void doSomething(A& a, B& b);
};

void doSomething(A& a, B& b)
{
    cout << a.m_value << " " << b.m_value << endl;
}


int main(int argc, char *argv[])
{
    A a;
    doSomething(a);
    return (0);
}