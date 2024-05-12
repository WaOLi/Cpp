#include "../tester/std_lib_facilities.h"
//#include <algorithm>

enum class IntTypes
{
	dec = 0, oct, hex, not_a_type
};


IntTypes get_type(vector<int>& n, const std::string& s);
bool check_dec(vector<int>& n, const std::string& s);
bool check_oct(vector<int>& n, const std::string& s);
bool check_hex(vector<int>& n, const std::string& s);

vector<char> hexes;
vector<char> octs;

int main()
{
	for (int i{}; i < 10; i++)
	{
		hexes.push_back('0' + i);
		if (i < 9)
		{
			octs.push_back('0' + i);
		}
	}
	for (int i{}; i < 6; i++)
	{
		hexes.push_back('a' + i);
	}

	cout << "what number of integers you want?: ";
	int num_of_ints;
	cin >> num_of_ints;
	std::cout << "Enter " << num_of_ints << " numbers: ";
	vector<string> nums(num_of_ints);
	vector<int> nums_dec;

	for (string& s : nums)
	{
		cin >> s;
	}

	for (int i{}; i < nums.size(); i++)
	{
		get_type(nums_dec, nums[i]);
	}
	for (int i{}; i < nums.size(); i++)
	{
		switch (get_type(nums_dec, nums[i]))
		{
		case IntTypes::dec:
			std::cout << dec << right << setw(10) << nums[i]<< '\t' << left << setw(13) << "decimal" 
			<< setw(14) << "converts to" << right << setw(8) << dec << nums_dec[i] << setw(10) << "decimal" << endl;
			break;
		case IntTypes::hex:
			std::cout << hex << right << setw(10) << nums[i]<< '\t' << left << setw(13) << "hexadecimal"
			<< setw(14) << "converts to" << right << setw(8) << dec << nums_dec[i] << setw(10) << "decimal" << endl;
			break;
		case IntTypes::oct:
			std::cout << oct << right << setw(10) << nums[i]<< '\t' << left << setw(13) << "octal"
			<< setw(14) << "converts to" << right << setw(8) << dec << nums_dec[i] << setw(10) << "decimal" << endl;
			break;
		default:
			std::cerr << "bad type";
		}
	}

	//std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl;
}

IntTypes get_type(vector<int>& n, const std::string& s)
{
	if (s.size() < 1)
	{
		std::cerr << "string size 0";
		return IntTypes::not_a_type;
	}

	switch (s[0])
	{
	case '0':
		if (s.size() > 1 && s[1] == 'x')
		{
			return check_hex(n, s) ? IntTypes::hex : IntTypes::not_a_type;
		}
		else if (s.size() > 1)
		{
			return check_oct(n, s) ? IntTypes::oct : IntTypes::not_a_type;
		}
		else
		{
			return IntTypes::dec;
		}
	case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		return check_dec(n, s) ? IntTypes::dec : IntTypes::not_a_type;
	}
	default:
		return IntTypes::not_a_type;
	}
}

bool check_dec(vector<int>& n, const std::string& s)
{
	for (const char& c : s)
	{
		if (!isdigit(c))
		{
			return false;
		}
	}
	int tt;
	tt = stoi(s);
	n.push_back(tt);
	return true;
}

bool check_oct(vector<int>& n, const std::string& s)
{
	if (s.size() < 2)
	{
		return false;
	}

	string temp;
	for (int i{ 1 }; i < s.size(); ++i)
	{
		if (find(octs.begin(), octs.end(), s[i]) == octs.end())
		{
			return false;
		}
		temp += s[i];
	}
	int tt;
	istringstream iss{ temp };
	iss >> oct >> tt;
	n.push_back(tt);
	return true;
}

bool check_hex(vector<int>& n, const std::string& s)
{
	if (s.size() < 3)
	{
		return false;
	}
	string temp;
	for (int i{ 2 }; i < s.size(); i++)
	{
		if (find(hexes.begin(), hexes.end(), s[i]) == hexes.end())
		{
			return false;
		}
		temp += s[i];
	}
	int tt;
	istringstream iss{ temp };
	iss >> hex >> tt;
	n.push_back(tt);
	return true;
}