#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream ifs{ "f1.txt" };
	if (!ifs)
	{
		std::cerr << "couldn't open file";
	}
	int counter{};

	std::string temp;
	while (ifs >> temp)
	{
		for (int i{}; i < temp.size(); ++i)
		{
			if (!isdigit(temp[i]))
			{
				break;
			}
			if (i == temp.size() - 1)
			{
				counter+=std::stoi(temp);
			}
		}
	}
	std::cout << counter;
}