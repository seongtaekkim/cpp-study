#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0)
        : m_cents(cents) {}
    int getCents() const {
        return (m_cents);
    }
    int& getCents() {
        return (m_cents);
    }
    friend ostream& operator << (ostream& out, const Cents &cents)
    {
        out << cents.m_cents;
        return (out);
    }

    Cents operator - () const
    {
        return (Cents(-m_cents));
    }

    bool operator ! () const
    {
        return (m_cents == 0 ? true : false);
    }

};

bool operator == (const Cents &cents1, const Cents &cents2)
{
    return (cents1.getCents() == cents2.getCents());
}

bool operator < (const Cents &cents1, const Cents &cents2)
{
    return (cents1.getCents() < cents2.getCents());
}

int main(int argc, char *argv[])
{
    
    Cents c1(10);
    Cents c2(10);

    
    vector<Cents> arr(20);
    for (unsigned int i = 0; i< 20 ; ++i)
        arr[i].getCents() = i;


    // c++17 부터 deplecated 되어서 <random> 의 std::shuffle 을 사용해야한다
    std::random_shuffle(begin(arr), end(arr));

    for (auto &e : arr)
        cout << e << " ";
    cout << endl;

    sort(begin(arr), end(arr));

    for (auto &e : arr)
        cout << e << " ";
    cout << endl;
    return (0);
}
