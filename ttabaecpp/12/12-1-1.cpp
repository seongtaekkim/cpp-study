#include <iostream>
using namespace std;

class Animal
{
protected:
    string m_name;
public:
    Animal(string name)
        : m_name(name) {}
    string getName()
    {
        return (m_name);
    }
    virtual void    speak() const
    {
        cout << m_name << " ??? " << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string name)
        :Animal(name) {}
    void speak() const
    {
        cout << m_name << " Meow" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name)
        :Animal(name) {}
    void speak() const
    {
        cout << m_name << " Woof" << endl;
    }
};

int main(void)
{
    Cat cats[] = {Cat("cat1"), Cat("cat2")};
    Dog dogs[] = {Dog("dog1"), Dog("dog2")};
    
    for (int i =0; i< 2 ; i++)
        cats[i].speak();
    
    for (int i =0; i< 2 ; i++)
        dogs[i].speak();

    Animal *animals[] = {&cats[0], &cats[1], &dogs[0], &dogs[1]};
    for (int i =0; i< 4 ; i++)
        animals[i]->speak();

    return (0);
}