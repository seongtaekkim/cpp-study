#include <iostream>
using namespace std;

class Simple
{
    private:
        int m_id;
    public:
        Simple(const int& id_in)
            : m_id(id_in) {
                cout << "const " << endl;
            }
        ~Simple()
        {
            cout << "destructor " << m_id << endl;
        }
};
int main(int argc, char *argv[])
{
    Simple s1(0);
    Simple s2(1);

    Simple *s3 = new Simple(2);
    delete s3;  // 동적할당 시 영역이 끝나도 메모리가 해제 되지 않으므로, delete 를 통해
                    // 소멸자를 호출해야 한다.
    return (0);
}
