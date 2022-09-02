#include <iostream>
//#include <fstream>

using namespace std;

class Point
{
private:
    double m_x, m_y, m_z;
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        :m_x(x), m_y(y), m_z(z)
        {}
    double getX() {
        return (m_x);
    }
    double getY() {
        return (m_y);
    }
    double getZ() {
        return (m_z);
    }
    /* void    print() {
        cout << m_x << " " << m_y << " " << m_z << endl;
    } */

    // 멤버함수로 만들기 어렵다. (파라메터에 output stream이 있기 때문)
    friend std::ostream& operator << (std::ostream &out, const Point &point)
    {
        out << "( " << point.m_x << " " << point.m_y << " " << point.m_z << " )";
        return (out);
    }

    friend std::istream& operator >> (std::istream &in, Point &point)
    {
        in >> point.m_x >> point.m_y >> point.m_z;
        return (in);
    }
};

int main(int argc, char *argv[])
{
    //ofstream of("out.txt");

    Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

    /* p1.print();
    p2.print();
    cout << endl; */

    cin >> p1 >> p2;
    cout << p1 << " " << p2 << endl;
    //of << p1 << " " << p2 << endl;
    //of.close();

    return (0);
}
