//#include "timer.h"
#include "AutoPtr2.h"
#include "Resource.h"
#include <memory>
#include <iostream>
    using namespace std;


unique_ptr<Resource> doSomething()
//auto doSomething()
{
/*     auto res1 = std::make_unique<Resource>(5);
    return (res1); d*/

return (unique_ptr<Resource>(new Resource(5)));

//    return make_unique<Resource>(5); // 내부적으로 move sementics사용
}

void doSomething2(unique_ptr<Resource> & res)
//void do Something2(Resource &* res)
{
    res->setAll(10);
}

int main(void)
{

    { 
        unique_ptr<int> uni(new int);
        //unique_ptr<Resource> res1(new Resource(5));
        //auto res1 = std::make_unique<Resource>(5);
        auto res1 = doSomething();

        res1->setAll(5);
        res1->print();

        unique_ptr<Resource> res2;

        cout << boolalpha;
        cout << static_cast<bool>(res1) << endl;
        cout << static_cast<bool>(res2) << endl;

        //res2 = res1; // unique ptr 은 copy semantics 안됨
        res2 = std::move(res1);

        cout << boolalpha;
        cout << static_cast<bool>(res1) << endl;
        cout << static_cast<bool>(res2) << endl;

        if (res1 != nullptr) res1->print();  // copy asignment 로직에서 nullptr setting 주의
        if (res2 != nullptr) res2->print(); // (*res2).print();
    }

 /*     {
        auto res1 = make_unique<Resource>(5);
        res1->setAll(1);
        res1->print();

        doSomething2(res1); // l-value reference
                             // parameter 가 value copy 일 경우. 에러 발생 (unique ptr)
        //doSomething2(move(res1)); // parameter 가 value copy 일 경우.
                                    // ptr move
        //res1 = doSomething2(move(res1)); // 주소를 다시 받고 싶으면, return 받는다.
        //doSomething2(res1.get()); // parameter가 address copy 인경우, get() 함수를 사용해서 처리.

        res1->print();
    }  */

  /*   {
        Resource *res = new Resource;
        unique_ptr<Resource> res1(res);
        unique_ptr<Resource> res2(res); // 포인터 소유권을 한군데에서만 해야 함.

        delete res; // delete 하지마셈
    } */

    return (0);
}