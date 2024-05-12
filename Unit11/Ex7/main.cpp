#include <iostream>
#include <string>


int main()
{
	std::string s{ "" };
	std::string s1{ "can't" }, s2{ "don't" }, s1p{ "can not" }, s2p{ "do not" };
	std::getline(std::cin, s);


	if (s.find(s1) != s.npos)
	{
		s.replace(s.find(s1), s1.length(), s1p);
	}
	else if (s.find(s2) != s.npos)
	{
		s.replace(s.find(s2), s2.length(), s2p);
	}

	bool inside_quotes{ false };
	for (int i{}; i < s.size(); i++)
	{
		if (isalpha(s[i]) && s[i] == toupper(s[i]))
		{
			s[i] = tolower(s[i]);
		}

		if (inside_quotes && s[i] != '"')
		{
		}
		else if (inside_quotes && s[i] == '"')
		{
			inside_quotes = false;
		}
		else if (!inside_quotes && s[i] == '"')
		{
			inside_quotes = true;
		}
		else
		{
			if (ispunct(s[i]) && s[i] != '-')
			{
				s[i] = ' ';
			}
			else if (s[i] == '-')
			{ 
				if ( (i < s.size() - 1 && isspace(s[i + 1])) 
					|| (i > 0 && isspace(s[i - 1])) )
				{
					s[i] = ' ';
				}
			}
		}
	}
	std::cout << s;
	return 0;
}