#include <random>
#include <iostream>
#include <fstream>

struct Reading
{
	int hour;
	double temperature;

	Reading(int h, double t)
		:temperature{ t }, hour{ h }
	{
	}
};

std::istream& operator>>(std::istream& is, Reading& r)
{
	return is >> r.hour >> r.temperature;
}

int main()
{
	std::random_device rd;
	std::mt19937 get(rd());
	std::uniform_real_distribution<> distr(-100, 100);

	int readings{ 50 };

	std::ofstream ofs{ "raw_temps.txt" };
	if (!ofs)
	{
		std::cerr << "failed to open the file";
	}

	for (int i{}; i < readings; i++)
	{
		ofs << i+1 << ' ' << double(distr(rd)) << 'c' << '\n';
	}

	ofs.close();

	std::ifstream ifs("raw_temps.txt");
	if (!ifs)
	{
		std::cerr << "failed to open file for inputing";
	}
	double tempd{};
	char degree_type{};
	for (int temp{}; ifs >> temp >> tempd >> degree_type;)
	{
		std::cout << temp << '\t' << tempd << degree_type << std::endl;
	}
}