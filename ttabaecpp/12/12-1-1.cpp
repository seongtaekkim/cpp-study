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
    cout << "===============================" << endl << endl;
    Animal *animals[] = {&cats[0], &cats[1], &dogs[0], &dogs[1]};
    for (int i =0; i< 4 ; i++)
        animals[i]->speak();

    cout << "===============================" << endl << endl;
    Animal a = Cat("cat1");
    a.speak();
    cout << "===============================" << endl << endl;

    Cat c("cat2");
    Dog d("dog1");
    a = c;
    a.speak();
    Animal &b = c;
    b.speak();
    b = d;  // 초기화 했던 변수는 변경한 인스턴스 c의 정보를 따르고
            // virtual 함수는 처음 초기화된 인스턴스 d의 정보를 따른다.
    b.speak();

    Dog *d2 = new Dog("dog2");
    b = *d2;
    b.speak();
    cout << "===============================" << endl << endl;

    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;

    cout << "===============================" << endl << endl;

    Animal *aa = new Cat("cat1");
    aa->speak();
    Cat cc("cat2");
    Dog *dd = new Dog("dog");
    Animal *bb = &cc;
    bb->speak();
    bb = dd;
    bb->speak();

    cout << typeid(aa).name() << endl;
    cout << typeid(bb).name() << endl;
    cout << bb << endl;
    cout << &cc << endl;


/*     const std::string str = "HI THIS IS BRAIN";
    const std::string *stringPTR = &str;
    const std::string &stringREF = str;

    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl; */


    return (0);
}