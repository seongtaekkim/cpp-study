#include <iostream>

using namespace std;

const char* getName()
{
    return "jack jack";
}

int main(void)
{
    //char name[] = "jack jack";
    //char *name = "jack jcak"; // 리터럴을 이라서 포인터는 메모리 주소를 가리키기만 하므로 할당 못함
    const char *name = "jack jack "; // 예외적으로 const 는 가능
    const char *name2 = "jack jack";

    cout << (uintptr_t)name << endl;
    cout << (uintptr_t)name2 << endl;

    const char *name3 = getName();
    const char *name4 = getName();

    cout << (uintptr_t)name3 << endl;
    cout << (uintptr_t)name4 << endl;

    return (0);
}