#include <iostream>
#include <bitset>

using namespace std;

int	main()
{

	/*
	 * bit flag
	 */

	bool item1_flag = false;
	bool item2_flag = false;
	bool item3_flag = false;
	bool item4_flag = false;

	const unsigned char	opt0 = 1 << 0;
	const unsigned char	opt1 = 1 << 1;
	const unsigned char	opt2 = 1 << 2;
	const unsigned char	opt3 = 1 << 3;
	
	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;
	unsigned char	items_flag = 0;

	cout << "No item " << bitset<8>(items_flag) << endl;	
	
	// item0 on
	items_flag |= opt0;

	// item3 on
	items_flag |= opt3;

	// item3 lost
	items_flag &= ~opt3;

	/// has item1
	if (items_flag & opt1)
		cout << "has item1 " << endl;
	else
		cout << "not has item1 " << endl;

	// has item0
	if (items_flag & opt0)
		cout << "has item0 " << endl;
	
	// optain item 2, 3
	items_flag |= (opt2 | opt3);

	cout << "optain item 2,3 : " << bitset<4>(items_flag) << endl;
	
	if ((items_flag & opt2) && (items_flag & opt3))
	{
		// 상태변경은 XOR을 사용함
		items_flag ^= (opt1 | opt2);
	}
	cout << "item xor : " << bitset<4>(items_flag) << endl;


	/*
	 * bit mask
	 * RGB color codes
	 */

	const unsigned int	red_mask = 0xFF0000;
	const unsigned int	green_mask = 0x00FF00;
	const unsigned int	blue_mask = 0x0000FF;

	unsigned int	pixel_color = 0xDAA520;

	cout << std::bitset<32>(pixel_color) << endl;

	unsigned char	blue = pixel_color & blue_mask;
	unsigned char	green = (pixel_color & green_mask) >> 8;
	unsigned char	red = (pixel_color & red_mask) >> 16;

	cout << "red " << bitset<8>(red) << " " << int(red) << endl;
	cout << "green " << bitset<8>(green) << " " << int(green) << endl;
	cout << "blue " << bitset<8>(blue) << " " << int(blue) << endl;
	

	return (0);
}
