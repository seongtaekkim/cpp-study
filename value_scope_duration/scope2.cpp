#include <iostream>
#include "MyConstants.h"

// 초기화를 해주어야 메모리가 할당되고,
// 다른 파일에서 접근이 가능하다.
extern int e_a = 123;


void	doSomething()
{
	using namespace std;
	cout << "hello " << endl;
	cout << "in scope2.cpp "<< Constants::pi << " " <<  &Constants::pi << endl;
	cout << "in scope2.cpp "<< Constants2::gravity << " " <<  &Constants2::gravity << endl;
}
