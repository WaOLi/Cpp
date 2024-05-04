#include "Year.h"
#include <random>
#include <fstream>
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
random (10, 23) int specifying the hours
for which the temperature readings
will be generated


For each temperature reading there will be a
random (-200, 200) double generated.


*/

//goal is to fill a file with generated a couple
//of years worth of readings, so as to populate
//another file with these readings


//const Day& po

const double generate_reading();

const Day& populate_day_with_readings(Day& d);

const Month& populate_month(Month& m);

const Year& populate_year(Year& y);

int main()
{

	std::random_device rd;
	std::mt19937 get(rd());


	std::uniform_int_distribution<> distr_year(1900, 2000);
	std::uniform_int_distribution<> distr_number_of_years(2, 4);

	unsigned short number_of_years{ unsigned short(distr_number_of_years(rd)) };


	std::uniform_int_distribution<> distr_days_in_a_month(15, 32);
	std::uniform_int_distribution<> distr_hours_in_a_day(4, 23);

	//first assignment: generate a bunch of unique years and put them into the vector
	std::vector<Year> year{};
	unsigned short curr_year{ unsigned short(distr_year(rd)) };
	bool is_copy{};
	for (int i{}; i < number_of_years; i++)
	{
		for (const Year& y : year)
		{
			if (y.year == curr_year)
			{
				is_copy = true;
				break;
			}
		}
		if (is_copy)
		{
			curr_year = unsigned short(distr_year(rd));
			i--;
			is_copy = false;
			continue;
		}
		year.push_back(Year{ curr_year });
	}

	//sort years
	for (int i{}; i < year.size() - 1; i++)
	{
		for (int j{ i }; j < year.size(); j++)
		{
			if (year[i].year > year[j].year)
			{
				unsigned short temp = year[i].year;
				year[i] = year[j];
				year[j] = temp;
			}
		}
	}


	//populating each year with random number of months
	std::uniform_int_distribution<> distr_number_of_months(5, 11);
	std::uniform_int_distribution<> distr_month_index(0, 11);
	unsigned short num_mon = distr_number_of_months(rd);
	for (Year& y : year)
	{
		unsigned short mon_ind = distr_month_index(rd);
		for (int i{}; i < num_mon; i++)
		{
			int& mon_ref = y.month[mon_ind].month;
			if (mon_ref == not_a_month)
			{
				mon_ref = mon_ind;
			}
			else
			{
				i--;
			}
			mon_ind = distr_month_index(rd);
		}
		num_mon = distr_number_of_months(rd);
	}

	//filling in the days for each month of each year
	for (Year& y : year)
	{
		populate_year(y);
	}

	{
		std::ofstream ofs{ "readings.txt" };
		for (Year& y : year)
		{
			ofs << y;
		}
	}
	std::ifstream ifs{ "readings.txt" };

	std::ofstream ofs{ "new_readings.txt" };

	Year temp_y{};

	for (int i{}; i< number_of_years;i++)
	{
		ifs >> temp_y;
		ofs << temp_y;
		temp_y = Year{};
	}
}



const double generate_reading()
{
	std::random_device r_d;
	std::mt19937 get(r_d());
	std::uniform_real_distribution<> distr_reading(-200, 200);

	return distr_reading(r_d);
}

const Day& populate_day_with_readings(Day& d)
{
	std::random_device r_d;
	std::mt19937 get(r_d());
	std::uniform_int_distribution<> distr_number_of_hours(11, 23);
	std::uniform_int_distribution<> distr_hour_ind(0, 23);

	unsigned short number_of_hours{ unsigned short(distr_number_of_hours(r_d)) };
	unsigned short hour_ind{ unsigned short(distr_hour_ind(r_d)) };
	for (unsigned short i{}; i < number_of_hours; i++)
	{
		double& reading_reference = d.hour[hour_ind];
		if (reading_reference == not_a_reading)
		{
			reading_reference = generate_reading();
		}
		else
		{
			--i;
		}
		hour_ind = distr_hour_ind(r_d);
	}
	return d;
}

const Month& populate_month(Month& m)
{
	std::random_device r_d;
	std::mt19937 get(r_d());
	std::uniform_int_distribution<> distr_number_of_days(15, 23);
	std::uniform_int_distribution<> distr_day_ind(0, 23);
	unsigned short number_of_days{ unsigned short(distr_number_of_days(r_d)) };
	unsigned short day_ind{ unsigned short(distr_day_ind(r_d)) };
	std::vector<unsigned short> used_days{ std::vector<unsigned short>(number_of_days) };

	for (int i{}; i < number_of_days; i++)
	{
		used_days[i] = 300;
	}

	for (int i{}; i < number_of_days; i++)
	{
		for (int j{}; j <= i; j++)
		{
			if (used_days[j] == day_ind)
			{
				j = -1;
				day_ind = distr_day_ind(r_d);
			}
		}
		used_days[i] = day_ind;
		populate_day_with_readings(m.day[day_ind]);
	}
	return m;
}

const Year& populate_year(Year& y)
{
	for (Month& mm : y.month)
	{
		if (mm.month != not_a_month)
		{
			populate_month(mm);
		}
	}
	return y;
}
