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
}
