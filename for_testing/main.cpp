#include <iostream>

class A
{
public:
	std::string str;
	void print()
	{
		std::cout << str;
	}
};

std::istream& operator>>(std::istream& is, A& a)
{
	char temp;
	while (is >> temp)
	{
		if (temp == 'O' || temp == 'X')
		{
			a.str += temp;
		}
		else
		{
			break;
		}
	}
	return is;
}

int main()
{
	A v;
	std::cin >> v;
	v.print();
}