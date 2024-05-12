#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::getline(std::cin, s);

	bool inside_quotes{ false };
	for (char& c : s)
	{
		if (inside_quotes && c != '"')
		{}
		else if (inside_quotes && c == '"')
		{
			inside_quotes = false;
		}
		else if (!inside_quotes && c == '"')
		{
			inside_quotes = true;
		}
		else
		{
			if (ispunct(c))
			{
				c = ' ';
			}
		}
	}
	std::cout << s;
}