#include "Roman_int.h"
#include <string>
#include <vector>

//std::ostream& operator<<(std::ostream& os, const Roman_int& r)
//{
//	
//}
//
//std::istream& operator>>(std::istream& is, const Roman_int& r)
//{
//	
//}

Roman_int::Roman_int(std::string n_r)
	:num_rom{ n_r }
{
	int thousands, hundreds, tens, ones;
	std::string temp{ this->num_rom };
	ones = get_digit(ones, temp, 'I', 'V', 'X');
	tens = get_digit(tens, temp, 'X', 'L', 'C');
	hundreds = get_digit(hundreds, temp, 'C', 'D', 'M');
	thousands = get_digit(thousands, temp, 'M', '-', '-');
	num_int = thousands * 1000 + hundreds * 100 + tens * 10 + ones;
	std::cout << num_int;
}

Roman_int::Roman_int(int n_i)
	:num_int{ n_i }
{
	if (n_i > 3999 || n_i < 1)
	{
		std::cerr << "number must be between 1 and 3999\n";
		throw Error{};
	}

	int thousands{}, hundreds{}, tens{}, ones{};

	//getting thousands
	thousands = n_i / 1000;

	//getting hundreds
	if (!thousands)
	{
		hundreds = n_i / 100;
	}
	else
	{
		hundreds = (n_i % 1000) / 100;
	}

	//getting tens
	if (!thousands && !hundreds)
	{
		tens = n_i / 10;
	}
	else if (!thousands)
	{
		tens = (n_i % 100) / 10;
	}
	else if (!hundreds)
	{
		tens = (n_i % 1000) / 10;
	}
	else
	{
		tens = ((n_i % 1000) % 100) / 10;
	}

	//getting ones
	if (!thousands && !hundreds && !tens)
	{
		ones = n_i;
	}
	else
	{
		std::string temp{ std::to_string(n_i) };
		ones = temp[temp.size() - 1] - '0';
	}

	//populating the roman numeral string
	std::string temp{};
	concat_order_of_magnitude(thousands, temp, 'M', '/', '[');
	concat_order_of_magnitude(hundreds, temp, 'C', 'D', 'M');
	concat_order_of_magnitude(tens, temp, 'X', 'L', 'C');
	concat_order_of_magnitude(ones, temp, 'I', 'V', 'X');

	this->num_rom = temp;
	std::cout << this->num_rom << std::endl;
}



//utility functions:

//function that helps with stringifying orders of magnitude
std::string& concat_order_of_magnitude(int o_m, std::string& num, char current, char next, char after_next)
{
	switch (o_m)
	{
	case 0:
		return num;
	case 1:
	case 2:
	case 3:
		for (int i{}; i < o_m; i++)
		{
			num += current;

		}
		break;
	case 4:

		num += current;
		num += next;
		break;
	case 5:
		num += next;
		break;
	case 6:
	case 7:
	case 8:
		num += next;
		for (int i{}; i < o_m - 5; i++)
		{
			num += current;
		}
		break;
	case 9:
		num += current;
		num += after_next;
		break;
	default:
		std::cerr << "invalid order of magnitude";
	}
	return num;
}

int& get_digit(int& out_o_m, std::string& num, char current, char next, char after_next)
{
	if (num.size() < 1)
	{
		out_o_m = 0;
		return out_o_m;
	}
	std::vector<std::string> library
	{
		std::string(&current, 1),
		std::string(&current, 1) + std::string(&current ,1),
		std::string(&current,1) + std::string(&current,1) + std::string(&current,1),
		std::string(&current,1) + std::string(&next,1),
		std::string(&next,1),
		std::string(&next,1) + std::string(&current,1),
		std::string(&next,1) + std::string(&current,1) + std::string(&current,1),
		std::string(&next,1) + std::string(&current,1) + std::string(&current,1) + std::string(&current,1),
		std::string(&current,1) + std::string(&after_next,1)
	};

	std::string single_num{};
	for (int i{}; i < num.size() && (num[num.size() - 1 - i] == current
		|| num[num.size() - 1 - i] == next
		|| num[num.size() - 1 - i] == after_next); ++i)
	{
		if (num[num.size() - 1 - i] == after_next)
		{
			//check that if it's `after_next` the one after is not current or next
			if (i > 0 && (num[num.size() - i] == current || num[num.size() - i] == next))
			{
				break;
			}
			else if (i == 0 && num.size() > 1 && num[num.size() - 2] != current)
			{
				break;
			}
		}


		single_num.insert(0, 1, num[num.size() - 1 - i]);
	}

	if (single_num.size() < 1)
	{
		return out_o_m = 0;
	}

	for (int i{}; i < library.size(); ++i)
	{
		if (library[i] == single_num)
		{
			out_o_m = i + 1;
			for (int j{}; j < library[i].size(); ++j)
			{
				num.pop_back();
			}
			break;
		}
	}

	return out_o_m;
}
