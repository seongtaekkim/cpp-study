
class Position2D
{
private:
    int m_x;
    int m_y;
public:
    Position2D(const int &x, const int &y)
        : m_x(x), m_y(y) {}
    void    set(Position2D pos)
    {
        set(pos.m_x, pos.m_y);
    }
    void    set(const int &x, const int &y)
    {
        m_x = x;
        m_y = y;
    }
    int getX()
    {
        return (m_x);
    }
    int getY()
    {
        return (m_y);
    }
};