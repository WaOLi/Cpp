#include "Chrono.h"

int main()
{
	Chrono::Date d1{ 2024, Chrono::Month::mar, 17 };
	//std::cout << next_Sunday(d1);
	//std::cout << next_weekday(d1);
	std::cout << std::endl << week_of_year(d1) << std::endl;
}