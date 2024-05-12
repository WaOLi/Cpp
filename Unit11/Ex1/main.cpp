#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream ifs{ "f1.txt" };
	std::ofstream ofs{ "f2.txt" };

	if (!ifs || !ofs)
	{
		std::cout << "file couldn't be opened";
	}

	std::string s;
	while (std::getline(ifs, s))
	{
		for (char& c : s)
		{
			if (isalpha(c) && isupper(c))
			{
				c = tolower(c);
			}
		}
		ofs << s << '\n';
	}
}