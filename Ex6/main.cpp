#include "Roman_int.h"

int main()
{
	/*for (int i{ 1 }; i < 3999; ++i)
	{
		Roman_int r1(i);
	}*/
	//char c1{ 'a' }, c2{ 'b' };
	//std::string s1{ c1 + c2 };
	//std::cout << r1;

	/*int i;
	std::string temp{ "IV" };
	std::cout << get_digit(i, temp, 'I', 'V', 'X');*/

	Roman_int r1{ "MMCCCLI" };
	Roman_int r2{ r1.as_int() };
}