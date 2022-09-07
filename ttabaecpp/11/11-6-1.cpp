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
    }
    void    setValue(int m_value)
    {
        Base::m_protected = m_value;
    }

};

int main(void)
{
    return (0);
}