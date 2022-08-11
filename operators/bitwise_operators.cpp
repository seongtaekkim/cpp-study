#include <iostream>
#include <bitset>

int	main()
{
	using namespace std;

	// << left shift
	// >> right shift
	// ~, &, |, ^
	//
	
	unsigned int	a = 3;

	cout << std::bitset<8>(a) << endl;

	unsigned int	b = a << 3;

	cout << std::bitset<8>(b) << " " << b << endl;

	/// << : bitwise left shift	
	cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
	cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
	cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
	cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl;

	unsigned int	c = 1024;

	// >> : bitwise right shift
	cout << std::bitset<16>(c >> 1) << " " << (c >> 1) << endl;
	cout << std::bitset<16>(c >> 2) << " " << (c >> 2) << endl;
	cout << std::bitset<16>(c >> 3) << " " << (c >> 3) << endl;
	cout << std::bitset<16>(c >> 4) << " " << (c >> 4) << endl;

	unsigned int	d = 1024;

	// ~ : bitwise NOT
	cout << std::bitset<16>(d) << endl;
	cout << std::bitset<16>(~d) << " " << (~d) << endl;
	
	// 이진수 앞에는 0b를 붙인다	
	unsigned int	e = 0b1100;
	unsigned int	f =	0b0110;

	/*
	 * & : bitwise AND
	 * | : bitwise OR
	 * ^ : bitwise XOR
	 */
	cout << std::bitset<4>(e & f) << endl;
	cout << std::bitset<4>(e | f) << endl;
	cout << std::bitset<4>(e ^ f) << endl;

	// example
	cout << (0b0110 >> 3) << " " << std::bitset<8>(0b0110 >> 3) << endl;
	cout << (5 | 12) << " " << std::bitset<4>(5|12) << endl;
	cout << (5 & 12) << " " << std::bitset<4>(5&12) << endl;
	cout << (5 ^ 12) << " " << std::bitset<4>(5^12) << endl;
	
	return (0);
}
