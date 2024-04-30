#include "Year.h"
#include <random>
/*
*****The program*****


a random int in range (1900, 2000) will state
the starting year


another randome (2, 4) will state for how many
years the readings will be generated


For each month the program will generate a
random number in the range (15, 32)that's
the number of days in the current month
for which there will be generated readings


For each day there will be generated a
random (4, 24) int specifying the hours 
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


	std::uniform_int<> distr_starting_year(1900, 2000);
	std::uniform_int<> distr_number_of_years(2, 4);


	unsigned short starting_year{ unsigned short(distr_starting_year(rd)) };
	unsigned short number_of_years{ unsigned short(distr_number_of_years(rd)) };

	Month m;
	std::cin >> m;
	std::cout << m;

	/*Reading r;
	std::cin >> r;
	std::cout << r;*/
}