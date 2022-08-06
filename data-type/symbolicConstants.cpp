#include <iostream>
//#define PRICE_PER_ITEM 30 // c에서는 매크로를 사용했지만 cpp에서는 그렇지 않음.
//#include "MY_CONSTANTS.h"

using namespace std;

int	main(void)
{
	constexpr int	my_const(123); // 컴파일 시 값이 결정되는 상수 (constexpr)
								   // mac c++12 에서는 사용 못하는듯

	int	number;
	cin >> number;

	const int special_number(number); // 런타임에 값이 결정되는 상수
	
	const int price_per_item = 30;
	int num_item = 123;
	//int price = num_item * PRICE_PER_ITEM;
	int price = num_item * price_per_item;

//	double radius;
//	cin >> radius;
//	double circumference = 2.0 * radius * constants::pi;

	return (0);

}
