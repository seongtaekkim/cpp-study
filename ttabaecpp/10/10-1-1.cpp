#include <iostream>
#include "Monster.h"

int main(void)
{
    Monster m1("staek", Position2D(1,1));
    std::cout << m1 << std::endl;
    m1.moveTo(Position2D(4,4));
    std::cout << m1 << std::endl;
    return (0);
}