#include <iostream>
using namespace std;

class A
{
public:
    virtual void print() {cout << "A" << endl;}
};

class B : public A
{
public:
    void print() {cout << "B" << endl;}
};

class C : public B
{
public:
    void print() {cout << "C" << endl;}
};

class D : public C
{
public:
    void print() {cout << "D" << endl;}
};


// 오버라이딩은 리턴타입 이름, 파라메터까지 구분함
// 가장 상위의 함수만 virtual로 변경하면, 중간상속관계 내에서는 모두 구현인스턴스의 함수를 호출한다.
// 하지만, 디버그 등 가독성 이슈가 있기에 관련된 모든 함수에 virtual 키워드를 삽입하면 좋다.
// 주의 : virtual table에서 상속관계를 검색하여 사용하기 때문에, 상속관게가 복잡할 경우 성능이슈가 있을 수 있음. 
int main(void)
{
    A a;
    B b;
    C c;
    D d;

    A &r = b;
    r.print();

    B &rb = d;
    rb.print();
    return (0);
}