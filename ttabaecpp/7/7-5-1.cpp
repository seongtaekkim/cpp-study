#include <iostream>
#include <array>

using namespace std;

// return by address
int* getValue(int x)
{
    int value = x * 2;
    return (&value);
}


// return by reference
int& getValue2(int x)
{
    int value = x * 2;
    return (value);
}


// return by address
int* allocateMemory(int size)
{
    return new int[size];
}

// return by reference
int& get(array<int, 100>& my_array, int ix)
{
    return my_array[ix];
}

int main(void)
{
    /*
        return by value
    */
    //int value = getValue(3); // 리턴 후 할당하며 데이터 복사가 일어남. (return by value)

    
    /*
        return by address
    */
    int value = *getValue(3); // 사라질 변수의 값을 역참조하여 리턴하므로 위험함.
    cout << value << endl;
    int *value1 = getValue(3); // 변수는 사라졌는데 주소만 리턴한 것이라 위험함.
    cout << *value1 << endl;
    cout << *value1 << endl; // 레퍼런스가 사라졌기 때문에, 쓰레기 값이 출력됨.
    // int *arr = new int[10]; // 인스턴스 생성부분을 함수부로 리팩토링한다.
    // factory pattern
    int *arr = allocateMemory(1024);
    delete[] arr; // 인스턴스 생성 후 자원해제 부분을 따로 해줘야 하는 부담이 있음.


    /*
        return by reference
    */
    int value2 = getValue2(5);
    cout << value2 << endl;

    int &value3 = getValue2(5); // 이미 사라진 지역변수의 주소를 받으므로 문제가 발생함.
    cout << value3 << endl;
    cout << value3 << endl; // 레퍼런스가 사라졌기 때문에, 쓰레기 값이 출력됨.


    // 메모리가 이미 존재하기 때문에, 안전하게 함수에서 값을 갱산힐 수 있다.
    array<int, 100> my_array; 
    my_array[30] = 10;  

    get(my_array, 30) = 1024;
    cout << my_array[30] << endl;

    /*
        return by value : 값 복사가 일어나므로 비효율적일 수 잇다.
        return by address : 함수의 local value는 사라질 메모리기이기 때문에 위험이 있따.
        return by reference : return by address와 마찬가지 이다.
        
        -> return by address or reference 인 경우에
        동적할당한 주소를 리턴하거나, 호출한 area에 리턴한 데이터의 메모리가 존재해서 사라질 염려가 없는 경우
        사용 가능하다.
    */
    return (0);
}