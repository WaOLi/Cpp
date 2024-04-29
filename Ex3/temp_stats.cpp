//program name temp_stats.cpp

#include <vector>
#include <iostream>
#include <fstream>
#include <random>

struct Reading
{
	int hour;
	double temperature;
	char degree_type{ 'c' };
	Reading(int h, double t, char d)
		:temperature{ t }, hour{ h }, degree_type{ d }
	{
		if (d == 'c')
		{
			temperature = temperature* double(9 / 5) + 32;
			degree_type = 'f';
		}
	}
};

std::ostream& operator<<(std::ostream& os, const Reading& r)
{
	return os << r.hour << ' ' << r.temperature << r.degree_type;
}

std::istream& operator>>(std::istream& is, Reading& r)
{
	return is >> r.hour >> r.temperature;
}

int main()
{
	std::random_device rd;
	std::mt19937 get(rd());
	std::uniform_int_distribution<> distr(0, 1);

	std::ifstream ifs{ "raw_temps.txt" };

	if (!ifs)
	{
		std::cerr << "failed to load file";
	}

	std::vector<Reading> readings;

	double temp_temp{};
	char temp_degree_type{};
	for (int i{}; ifs >> i >> temp_temp >> temp_degree_type;)
	{
		int temp{int(distr(rd))};
		char temp_c{};
		temp ? temp_c = 'f' : temp_c = 'c';
		//std::cout << temp_c << '\n';
		readings.push_back(Reading(i, temp_temp, temp_c));
	}


	// calculating mean
	unsigned __int64 number_of_readings{ readings.size() };
	double mean{};

	for (const Reading& r : readings)
	{
		mean += r.temperature / number_of_readings;
	}
	std::cout << "mean: " << mean << 'c' << '\n';

	std::vector<Reading> sorted_readings{ readings };

	//sorting
	for (int i{}; i < number_of_readings-1; i++)
	{
		for (int j{i+1}; j < number_of_readings; j++)
		{
			if (sorted_readings[i].temperature > sorted_readings[j].temperature)
			{
				Reading temp{ sorted_readings[i]};
				sorted_readings[i] = sorted_readings[j];
				sorted_readings[j] = temp;
			}
		}
	}

	for (const Reading& r : sorted_readings)
	{
		std::cout << r << std::endl;
	}

	std::cout << "median is : " << sorted_readings[number_of_readings / 2];
}