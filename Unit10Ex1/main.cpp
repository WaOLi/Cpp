#include <iostream>
#include <fstream>
#include <random>

int main()
{
	std::ofstream ofs{ "numbers.txt" };
	std::random_device rd;
	std::mt19937 get(rd());
	std::uniform_int_distribution<> distr(1, 100);
	int how_many_numbers = distr(rd);

	if (!ofs)
	{
		std::cerr << "couldn't open file";
	}
	else
	{
		for (int i{}; i < how_many_numbers; i++)
		{
			ofs << int(distr(rd)) << " ";
		}
	}
	ofs.close();

	int result{};
	std::ifstream ifs{ "numbers.txt" };
	if (!ifs)
	{
		std::cerr << "couldn't open file";
	}
	else
	{
		for (int temp; ifs >> temp;)
		{
			std::cout << result << "+" << temp << "=";
			result += temp;
			std::cout << result << std::endl;
		}
	}
	std::cout << result;
}