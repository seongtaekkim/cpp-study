#include <iostream>
#include <string>
using namespace std;



class Date
{
//public: // default : private
    int m_month;
    int m_day;
    int m_year;
    
    public:
    void setDate(const int& month_input, const int& day_input, const int& year_input)
    {
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    }
    void    setMonth(const int& month_input)
    {
        m_month = month_input;
    }
    const int& getDay()
    {
        return m_day;
    }
    void copyFrom(const Date& o) // 같은클래스라면 다른 인스턴스라도 접근가능하다.
    {
        m_month = o.m_month;
        m_day = o.m_day;
        m_year = o.m_year;
    }
};

int main(int argc, char *argv[])
{
    Date today;
    /*
    today.m_month = 8;
    today.m_day = 4;
    today.m_year = 2022;
    */
    today.setDate(8, 4, 2022);
    today.setMonth(12);
    cout << today.getDay() << endl;

    Date copy;
    copy.copyFrom(today);

    return (0);
}