//#include "timer.h"
#include "Resource.h"
#include <memory>
#include <iostream>
using namespace std;

void doSomething(std::unique_ptr<Resource> res)
{

}
int main(void)
{
    doSomething(unique_ptr<Resource>(new Resource(100000)));    // 불안전
    //doSomething(make_shared<Resource>(new Resource(100000))); // 안전

    Resource *res = new Resource(3);
    res->setAll(1);
    {
        // 포인터의 소유권을 여러 변수가 사용 가능.
        shared_ptr<Resource> ptr1(res); // ptr1 범위를 넘어설 때, ptr1 이 res와 함께 메모리 해제가 됨.

        ptr1->print();
            { 
            shared_ptr<Resource> ptr2(ptr1);
                shared_ptr<Resource> ptr2(res); // ptr1은 ptr2존재를 모르기 때문에, ptr2범위가 끝날 때 메모리를 해제하기 때문에
                                            // ptr1을 사용할 수 없게 된다.

                ptr2->setAll(3);
                ptr2->print();

                cout << "Going out of the block" << endl;
            }
        ptr1->print();

        cout << "Going out of the outer block" << endl;
    }
    return (0);
}