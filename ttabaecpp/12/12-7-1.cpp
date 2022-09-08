#include <iostream>
using namespace std;

class Animal
{
protected:
    string m_name;
public:
    Animal(std::string name)
        : m_name(name) {}
    
public:
    string getName()
    {
        return (m_name);
    }
    virtual void speak() const = 0; // pure virtual function
};

class Cat : public Animal
{
public:
    Cat(std::string name)
        : Animal(name) {}
    
    void speak() const
    {
        cout << m_name << " Meow" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(std::string name)
        : Animal(name) {}
    
    void speak() const
    {
        cout << m_name << " Mooo" << endl;
    }
};

int main(void)
{
    //Animal a("hi");

    Dog d("dogg");
    d.speak();

    Animal *a = new Cat("ccat");
    a->speak();
    return (0);
}