#include <iostream>
#include <cmath>
#include <limits>

int	main(void)
{
	using namespace std;
	
	short	s = 1;

	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;
	cout << std::numeric_limits<short>::max() << endl;
	cout << std::numeric_limits<short>::min() << endl;
	cout << std::numeric_limits<short>::lowest() << endl;

	s = 32767;
	s = s + 1;
	cout << s << endl;	

	s = std::numeric_limits<short>::min();

	s = s - 1;
	cout << s << endl;

	unsigned int i = -1;
	cout << i << endl;

	cout << 22 / 4 << endl;
	cout << 22 / (float)4 << endl;
	cout << (float)22 / 4 << endl;


	// 고정너비정수 (fixed-width integers)
	// c++는 컴파일러마다 데이터사이즈의 최소사이즈가 다를수 있어 불확실성이 있다.
	// c++ 11부터는 이 사이즈가 고정되어 있는 고정너비상수 개념이 등장한다.
	//
	std::int16_t ii(5);
	std::int8_t myint = 65; // 내부적으로 char타입으로 변경되는 타입이다.
							//
	std::int_fast8_t fi(5); // 8비트사이즈중에 가장빠른 타입.
	std::int_least64_t fl(5); // 적어도 8바이트를 갖는 타입
	
	/*
	 * 2.5 부동소수점 
	 * floating point numbers
	 */

	float f;
	double d;
	long double ld;

	cout << sizeof(float) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(ld) << endl;

	cout << numeric_limits<float>::max() << endl;
	cout << numeric_limits<float>::lowest() << endl;
	cout << numeric_limits<double>::max() << endl;
	cout << numeric_limits<double>::lowest() << endl;
	cout << numeric_limits<long double>::max() << endl;
	cout << numeric_limits<long double>::lowest() << endl;

	float f2(3.14); // 3.14 = 31.4 * 0.1
	cout << 3.14 << endl;
	cout << 31.4e-1 << endl;
	cout << 31.4e-2 << endl;
	cout << 31.4e+2 << endl;

	// mac에 해당 함수 정의가 안되어잇음
	// precision을 높히면 정확한 소수점 계산이 되지 않음.
	//cout << setprecision(16) << endl;
	//cout << 1.0 / 3.0 << endl;
	/*
	 * char type
	 */
	// c-style casting
	cout << (char)65 << endl;
	cout << (int)'A' << endl;
	
	// cpp style
	cout << char(65) << endl;
	cout << int('A') << endl;
	
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	cout << sizeof(unsigned char) << endl;
	cout << (int)std::numeric_limits<char>::max() << endl;
	cout << (int)std::numeric_limits<char>::lowest() << endl;
	
}
