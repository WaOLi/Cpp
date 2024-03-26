#include "Chrono.h"

namespace Chrono
{
	// member function definitions:
	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}
	const Date& default_date()
	{
		static Date dd{ 2001,Month::jan,1 }; // start of 21st century
		return dd;
	}
	Date::Date()
		:y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{
	}
	void Date::add_day(int n)
	{
		this->d += n;
		if (is_date(this->year(), this->month(), this->day()))
		{
			return;
		}
		else
		{
			for (int i{}; i < n; i++)
			{
				++this->d;
				if (!is_date(*this))
				{
					--this->d;
					switch (this->month())
					{
					case Month::dec:
						this->y++;
						this->d = 1;
						this->m = Month::jan;
						break;
					default:
						this->d = 1;
						int temp = int(this->month()) + 1;
						this->m = Month(temp);
						break;
					}
				}
			}
		}
	}

	void Date::add_month(int n)
	{
		// . . .
	}
	void Date::add_year(int n)
	{
		if (m == Month::feb && d == 29 && !leapyear(y + n))
		{ // beware of leap years!
			m = Month::mar; // use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}
	// helper functions:
	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid
		if (d <= 0) return false; // d must be positive
		if (m < Month::jan || Month::dec < m) return false;
		int days_in_month = 31; // most months have 31 days
		switch (m)
		{
		case Month::feb: // the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}
		if (days_in_month < d) return false;
		return true;
	}
	bool is_date(const Chrono::Date& d)
	{
		if (d.day() <= 0) return false; // d must be positive
		if (d.month() < Month::jan || Month::dec < d.month()) return false;
		int days_in_month = 31; // most months have 31 days
		switch (d.month())
		{
		case Month::feb: // the length of February varies
			days_in_month = (leapyear(d.year())) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}
		if (days_in_month < d.day()) return false;
		return true;

	}
	bool leapyear(int y)
	{
		if (!(y % 100))
		{
			return !(y % 400);
		}
		return !(y % 4);
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	
	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{ // oops: format error
			is.clear(std::ios_base::failbit); // set the fail bit
			return is;
		}
		dd = Date(y, Month(m), d); // update dd
		return is;
	}
	
	enum class Day
	{
		saturday = 0, sunday = 1, monday, tuesday, wednesday, thursday, friday,
	};

	Day day_of_week(const Date& d)
	{
		int temp = d.year() % 100;
		temp /= 4;
		temp += d.day();
		int index = int(d.month());
		std::string str2 = "144025036146";
		char c = str2[index - 1];
		int key = c - '0';
		temp += key;
		if (leapyear(d.year()) && (d.month() == Month::jan || d.month() == Month::feb))
		{
			temp--;
		}
		temp += 6;
		temp += d.year() % 100;
		Day result = Day(temp % 7);
		return result;
	}
	Date next_Sunday(const Date& d)
	{
		Date result = d;
		if (day_of_week(result) == Day::sunday)
		{
			result.add_day(1);
		}
		while (day_of_week(result) != Day::sunday)
		{
			result.add_day(1);
		}
		return result;
	}
	Date next_weekday(const Date& d)
	{
		Date result = d;
		switch (day_of_week(result))
		{
		case Day::friday:
			result.add_day(3);
			break;
		case Day::saturday:
			result.add_day(2);
			break;
		default:
			result.add_day(1);
			break;
		}
		return result;
	}
	int week_of_year(const Date& d)
	{
		int cntr{1};
		Date temp{ d.year(), Month::jan, 1 };
		while (temp != d)
		{
			temp.add_day(1);
			if (day_of_week(temp) == Day::sunday)
			{
				cntr++;
			}
		}
		return cntr;
	}

	std::ostream& operator<<(std::ostream& os, const Day& d)
	{
		// TODO: insert return statement here
		std::string s;
		switch (d)
		{
		case Day::sunday:
			s = "sunday";
			break;
		case Day::monday:
			s = "monday";
			break;
		case Day::tuesday:
			s = "tuesday";
			break;
		case Day::wednesday:
			s = "wednesday";
			break;
		case Day::thursday:
			s = "thursday";
			break;
		case Day::friday:
			s = "friday";
			break;
		case Day::saturday:
			s = "saturday";
			break;
		default:
			std::cerr << "no apropriate day" << int(d);
			break;
		}
		return os << s;
	}

	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		std::string s;
		switch (d.month())
		{
		case Chrono::Month::jan:
			s = "jan";
			break;
		case Chrono::Month::feb:
			s = "feb";
			break;
		case Chrono::Month::mar:
			s = "mar";
			break;
		case Chrono::Month::apr:
			s = "apr";
			break;
		case Chrono::Month::may:
			s = "may";
			break;
		case Chrono::Month::jun:
			s = "jun";
			break;
		case Chrono::Month::jul:
			s = "jul";
			break;
		case Chrono::Month::aug:
			s = "aug";
			break;
		case Chrono::Month::sep:
			s = "sep";
			break;
		case Chrono::Month::oct:
			s = "oct";
			break;
		case Chrono::Month::nov:
			s = "nov";
			break;
		case Chrono::Month::dec:
			s = "dec";
			break;
		default:
			std::cerr << "month is out of reach";
			break;
		}

		os << '(' << d.year();
		os << ',' << s;
		os << ',' << d.day();
		os << ')' << "\n";
		os << day_of_week(d) << std::endl;
		return os;
	}



	void Date::add_dz(long int n)
	{
		dz += n;
	}
} // Chrono