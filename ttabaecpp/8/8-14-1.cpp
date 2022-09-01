#include <iostream>
using namespace std;


class Fruit
{
public:
    enum FruitType // enum class 도 가능함.
    {
        APPLE, BANANA, CHERRY,
    };
    class InnerClass
    {

    };
    struct InnerStruct
    {

    };
private:
    FruitType m_type;
public:
    Fruit(FruitType type): m_type(type)
    {}
    FruitType getType() {return m_type;}
};



int main(int argc, char *argv[])
{
    Fruit apple(Fruit::APPLE);
    if (apple.getType() == Fruit::APPLE)
    {
        cout << "apple" << endl;
    }
    return (0);
}