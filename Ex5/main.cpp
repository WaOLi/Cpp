#include "Year.h"
#include <random>
/*
*****The program*****


a random int in range (1900, 2000) will state
the starting year


another randome (2, 4) will state for how many
years the readings will be generated


For each year the program will generate a
random in range (3, 11) to specify the number
of month to be populated with data


For each month the program will generate a
random number in the range (15, 32)that's
the number of days in the current month
for which there will be generated readings


For each day there will be generated a
random (4, 23) int specifying the hours 
for which the temperature readings
will be generated


For each temperature reading there will be a
random (-200, 200) double generated.


*/

//goal is to fill a file with generated a couple
//of years worth of readings, so as to populate
//another file with these readings

int main()
{
	std::random_device rd;
	std::mt19937 get(rd());


	std::uniform_int_distribution<> distr_year(1900, 2000);
	std::uniform_int<> distr_number_of_years(2, 4);

	unsigned short number_of_years{ unsigned short(distr_number_of_years(rd)) };


	std::uniform_int_distribution<> distr_days_in_a_month(15, 32);
	std::uniform_int_distribution<> distr_hours_in_a_day(4, 23);

	//first assignment: generate a bunch of unique years and put them into the vector

	unsigned short* used_years = new unsigned short[ number_of_years ];

	std::vector<Year> year{};
	unsigned short curr_year{ unsigned short(distr_year(rd)) };
	for (int i{}; i < number_of_years; i++)
	{
		for (const Year& y : year)
		{
			if (y.year == curr_year)
			{
				i--;
				curr_year = unsigned short(distr_year(rd));
				continue;
			}
		}
		used_years[i] = curr_year;
		year.push_back(Year{ curr_year });
	}

	for (Year& y : year)
	{
		std::cout << y;
	}
	


	/*Month m;
	m.day = std::vector<Day>(unsigned short(distr_days_in_a_month(rd)));
	
	unsigned short hours_in_a_day{ unsigned short(distr_hours_in_a_day(rd)) };*/
	
}