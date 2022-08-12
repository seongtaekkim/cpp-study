#include <iostream>
#include "MyConstants.h"

using namespace std;

int	value = 123;

// 다른 cpp파일에서 접근할 수 없음
static int g_s_a = 1;
/*
 * os로부터 메모리를 받아 정적으로 선언
 * 초기화는 한번만 한다. (처음에 선언할 때 반드시 초기화 해야 함)
 */
/*
void	doSomething()
{
	static int	a = 1;
	
	++a;
	cout << a << endl;
}
*/

// global value도 extern으로 선언할 수 있는데, 초기화하면 안됨.
// 외부 파일에서는 초기화가 반드시 되어 있어야 한다.
extern int e_a;
// foward declaration
// extern은 생략이 가능함
extern void	doSomething();

int	main(void)
{
	cout << value << endl;
	int value = 1;

	cout << ::value << endl; // :: 으로 전역scope에서 변수를 찾음
	cout << value << endl;

	doSomething();	
	doSomething();	
	
	cout << e_a << endl;

	// 헤더에 정의한 const 변수 출력(호출한 파일마다 메모리 주소가 다름)
	cout << "in scope1.cpp " << Constants::pi << " " << &Constants::pi << endl;
	// 헤더에 정의 후 cpp에 초기화한 extern const 변수 출력 (메모리 주소가 같음)
	cout << "in scope1.cpp " << Constants2::gravity << " " << &Constants2::gravity << endl;

	return (0);
}
