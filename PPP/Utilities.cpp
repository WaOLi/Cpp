#include "Utilities.h"
#include <iostream>
#include <sstream>

int str_to_int(std::string num)
{
	std::istringstream iss{ num };
	int result{};
	int cur_len = int(num.length());

	for (char c : num)
	{
		int temp = c - '0';
		result += temp * raise_to_pow(10, cur_len - 1);
		cur_len--;
	}
	return result;
}

int raise_to_pow(int base, int power)
{
	if (power == 0)
	{
		return 1;
		std::cout << "power is " << power;
	}
	else if (power < 0)
	{
		std::cerr << "no can do right now\n";
		return -1;
	}
	else
	{
		int result = 1;
		while (power != 0)
		{
			power--;
			result *= base;
		}
		return result;
	}
}

bool count_dash(std::string str)
{
	int cntr{};
	for (char c : str)
	{
		if (c == '-')
		{
			cntr++;
		}
	}
	return cntr == 3 ? true : false;
}

int* break_isbn_into_numbers(std::string isbn)
{
	/*std::string str[4];
	int nums[4];
	int dashes{};

	for (int i{}; i < isbn.length(); i++)
	{
		
	}*/
	return nullptr;
}
