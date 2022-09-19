//#include "timer.h"
#include <memory>
#include <iostream>
using namespace std;


class Person
{
private:
    string m_name;
    //shared_ptr<Person> m_partner;
    weak_ptr<Person> m_partner;

public:
    Person(const string &name)
        : m_name(name)
        {
            cout << m_name << " created\n";
        }
    ~Person()
    {
        cout << m_name << " destroyed\n";
    }
    friend bool partnerUp(shared_ptr<Person> &p1, shared_ptr<Person> &p2)
    {
        if (!p1 || !p2)
            return (false);
        p1->m_partner = p2;
        p2->m_partner = p1;

        cout << p1->m_name << " is partnered with " << p2->m_name << endl;

        return true;
    }

    const shared_ptr<Person> getPartner() const
    {
        return m_partner.lock(); // week ptr 은 ptr로 무언가 할 때 shared ptr 로 변경하여 사용해야 하낟.
    }

    const string & getName() const
    {
        return m_name;
    }
};

int main(void)
{
    auto lucy = make_shared<Person>("Lucy");
    auto ricky = make_shared<Person>("Ricky");

    partnerUp(lucy, ricky);
    cout << lucy->getName() << endl;
    cout << lucy->getPartner()->getName() << endl;

    return (0);
}