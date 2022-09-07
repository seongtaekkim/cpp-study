class Base
{
private:
    int m_private;
protected:
    int m_protected;
public:
    int m_public;
};

class Derived : protected Base
{
public:
    Derived()
    {
        Base::m_public;
        Base::m_protected;
        //Base::m_private;
    }

};

class GrandChild : public Derived
{
public:
    GrandChild()
    {   
        Base::m_public;
        //Derived::m_public;
       // Derived::m_protected;
    }
    
};

int main(void)
{
    return (0);
}