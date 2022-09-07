#include <iostream>
using namespace std;

class A
{
public:
    //virtual void print() final {cout << "A" << endl;}
     void print() {cout << "A" << endl;}
    virtual A* getThis() {
        cout << "a getthis" << endl;
        return this;}
};

class B : public A
{
public:
    void print()  {cout << "B" << endl;}
    virtual B* getThis()  {
        cout << "b getthis" << endl;
        return this;}
};


// override : c++11, 작성한 함수가 오버라이드 목적임을 명시하고, 문법적으로 오버라이드함수가 아니면 오류를 발생
//  , operride 는 부모함수가 virtual 인 경우에만 사용이 가능.
// final : c++11 , 자식들은 해당 함수를 오버라이드 할 수 없음을 문법적으로 명시.
/*
    공변변환값 : 함수일 경우, override를 명시하지 않으면 경고가 발생함. 
    
*/
int main(void)
{
    A a;
    B b;

    A &r = b;
    b.getThis()->print();
    r.getThis()->print();
    /*
        virtual 인 b의 포인터를 리턴 후, virtaul 이 아닌 print를 호출했기에a가 출력됨 
    */

    cout << typeid(b.getThis()).name() << endl;
    cout << typeid(r.getThis()).name() << endl;
    
   
    return (0);
}