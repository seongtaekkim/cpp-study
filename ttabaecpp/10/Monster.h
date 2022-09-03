#include "Position2D.h"

class Monster
{
private:
    std::string m_name;
    Position2D m_location;
public:
    Monster(const std::string &name, const Position2D &location)
        : m_name(name), m_location(location) {}
    void    moveTo(const Position2D &pos_target)
    {
        m_location.set(pos_target);
    }
    Position2D getPos()
    {
        return (m_location);
    }
};

std::ostream &operator << (std::ostream &out, Monster &monster)
{
    out << monster.getPos().getX() << " " <<  monster.getPos().getY();
    return (out);
}