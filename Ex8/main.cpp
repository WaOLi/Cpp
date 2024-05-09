#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream ifs1{ "doc1.txt" };
	std::ifstream ifs2{ "doc2.txt" };
	std::ofstream ofs{ "doc3.txt" };

	if (ifs1 && ifs2 && ofs)
	{
		std::string temp;
		while (std::getline(ifs1, temp))
		{
			ofs << temp << std::endl;
		}
		while (std::getline(ifs2, temp))
		{
			ofs << temp << std::endl;
		}
	}
}