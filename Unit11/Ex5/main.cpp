#include <iostream>
#include <string>

int main()
{
	while (std::cin)
	{
		std::string temp;
		std::getline(std::cin, temp);
		for (int i{}; i < temp.size(); i++)
		{
			std::cout << temp[i] << "- is :\n";
			if (isspace(temp[i]))
			{
				std::cout << '\t' << "space\n";
			}
			if (isalpha(temp[i]))
			{
				std::cout << '\t' << "alphabetical\n";
			}
			if (isdigit(temp[i]))
			{
				std::cout << '\t' << "digit\n";
			}
			if (isupper(temp[i]))
			{
				std::cout << '\t' << "alphabetical uppercase\n";
			}
			if (islower(temp[i]))
			{
				std::cout << '\t' << "alphabetical lowercase\n";
			}
			if (isalnum(temp[i]))
			{
				std::cout << '\t' << "alphabetical or numerical\n";
			}
			if (iscntrl(temp[i]))
			{
				std::cout << '\t' << "control character\n";
			}
			if (ispunct(temp[i]))
			{
				std::cout << '\t' << "punctuation by locale\n";
			}
			if (isprint(temp[i]))
			{
				std::cout << '\t' << "printable\n";
			}
			if (isgraph(temp[i]))
			{
				std::cout << '\t' << "not space\n";
			}
		}
	}
}