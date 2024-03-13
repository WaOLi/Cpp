#include <iostream>

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

struct Date
{
	class Invalid {};
	int day{};
	int year{};
	Month month{};
	Date();
	Date(int d, int y, Month m);
	void add_day() { day++; }

	Date& operator=(const Date& d2)
	{
		if (this != &d2)
		{
			this->day = d2.day;
			this->month = d2.month;
			this->year = d2.year;
		}
	}
};

bool operator==(const Date& d1, const Date& d2)
{
	return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}

bool operator!=(const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}
bool is_date(const Date& d);
//Date constructor
Date::Date(int d, int y, Month m)
	:day{d}, year{y}, month{m}
{
	if (!is_date(*this))
	{
		throw Date::Invalid{};
	}
}

//check if date is valid
bool is_date(const Date& d)
{
	if (d.month < Month::jan || d.month > Month::dec)
	{
		return false;
	}
	else if (d.day > 31 || d.day < 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


std::ostream& operator<<(std::ostream& os, const Date& d)
{
	std::string mon;
	switch (d.month)
	{
	case Month::jan:
		mon = "January";
		break;
	case Month::feb:
		mon = "February";
		break;
	case Month::mar:
		mon = "March";
		break;
	case Month::apr:
		mon = "April";
		break;
	case Month::may:
		mon = "May";
		break;
	case Month::jun:
		mon = "June";
		break;
	case Month::jul:
		mon = "July";
	case Month::aug:
		mon = "August";
	case Month::sep:
		mon = "September";
		break;
	case Month::oct:
		mon = "October";
		break;
	case Month::nov:
		mon = "November";
		break;
	case Month::dec:
		mon = "December";
		break;
	default:
		throw Date::Invalid{};
	}
	return os << "day: " << d.day << ", month: " << mon << ", year: " << d.year;
}

int main()
{
	Date today{ 25, 1978, Month::jun };

	Date tomorrow = today;
	tomorrow.add_day();
	std::cout << tomorrow << std::endl << today;
	try
	{
		Date test{ -1, 1978, Month::apr };
	}
	catch (Date::Invalid e)
	{
		std::cerr << "\ncaught; error code: `Invalid`";
	}
}