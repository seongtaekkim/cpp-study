#include <iostream>
using namespace std;

class Animal
{
protected:
    string m_name;
    int    *m_int; 
    int    &m_mnt; // int &m_mnt implicit copy assignment
public:
    Animal(string name, int n, int &m) // int &m implicit copy assignment
        : m_name(name), m_mnt(m) { // 생성자초기화 목록으로 초초기기화  해해야 함.
            m_int = new int;
            *m_int = n;
            //&m_mnt = m; // 생성자초기화 목록으로  초기화 헤야함.
            cout << "animal " << this << endl;
        }
    Animal(const Animal &a)
        : m_mnt(a.m_mnt)
    {
        cout <<"animal copy constructor " << endl;
    }
    Animal & operator = (const Animal &a) // Animal &a = d;
    {
        cout << "animal copy assignment : " << a.m_name << " " << this->m_name << endl;
        return (*this);
    }
    
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
    Cat(string name, int n, int &m) // int &m implicit copy assignment
        :Animal(name, n, m) {
            cout << "cat " << this << endl;
        }
    Cat(const Cat &c)
        : Animal(c)
    {
        //Animal(c.m_name, c.m_int, c.m_mnt);
        cout <<"cat copy constructor" << endl;
    }
    Cat & operator = (const Cat &a)
    {
        cout << "copy assignment : " << a.m_name << endl;
        return (*this);
    }
    void speak() const
    {
        cout << m_name << " Meow" << " " << &m_int << " " << &m_name << " " << this << endl;
    }
    void print()
    {
        cout << "print cat" << " " << this << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name, int n, int &m)
        :Animal(name, n, m) {
            cout << "dog " << this << endl;
        }
    Dog & operator = (const Dog &a)
    {
        cout << "copy : " << a.m_name << endl;
        return (*this);
    }
    void speak() const
    {
        cout << m_name << " Woof" <<  " " << m_int << " "  << this << endl;
    }
    void print()
    {
        cout << "print dog" << " " << this << endl;
    }
};

int main(void)
{
     int m1 = 1, m2 = 2;
    Cat c("cat2", 1, m1);
    Dog d("dog1", 2, m2);
    cout << endl << endl;
    Animal &b = c;
    b.speak();
    b = d;  // 부모의 copy asignment 가 작동함. -> 오버로딩 하고나서 복사를 안하면 해결이 되긴 함..
    b.speak();
    
    cout << &b << endl;
    cout << &c << endl; // b, c주소가 같음
    cout << &d << endl; 

    /* Dog *d2 = new Dog("dog2");
    b = *d2;
    b.speak();
 */

    Cat c2("cat22", 1, m1);
    Cat c3("cat33", 2, m2);
    c2.print();
    c3.print();
    //c2 = c3; // 객체 주소에 연결된 가상함수 주소매핑이 변경이 안되기 때문에, speak는 변경이 안되는듯.
        
    c2.print(); 

    cout << endl << endl;
    Cat c4("cat22", 1, m1);
    Cat c5("cat33", 2, m2);
    Cat &c6 = c4;
    c4.speak();
    c6.speak();
    //c6 = c5; // 객체 주소는 안바뀜. 포인터변수 값은 바뀌고, 주소는 안바뀜. 맴버변수 주소는 안바뀌고 값이 바뀜.
                // -> 참조변수는 초기화 후 할당하려 하면, 값복사만 되고 주소복사는 안됨.
             //  자식의 copy asignment 됨.
    c5.speak();
    c6.speak();

  //  Animal a7;
   //Cat c7("cat22", 1, m1);
    //Cat c8 = c7;
   // Cat c8(c7);
    //c8 = c7;
    //a7 = c8; 

 
    return (0);
}