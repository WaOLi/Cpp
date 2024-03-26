#pragma once
#include <iostream>

namespace Chrono
{
	enum class Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	class Date
	{
	public:
		class Invalid {}; // to throw as exception
		Date(int y, Month m, int d); // check for valid date and initialize
		Date(); // default constructor
		// the default copy operations are fine
		// nonmodifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
		// modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

		long int get_dayz() const { return dz; }
		void add_dz(long int n);
	private:
		int y;
		Month m;
		int d;
		long int dz;
	};
	bool is_date(int y, Month m, int d); // true for valid date
	bool is_date(const Date& d);
	bool leapyear(int y); // true if y is a leap year
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& dd);

	enum class Day;
	std::ostream& operator<<(std::ostream& os, const Day& d);
	Date next_Sunday(const Date& d);
	Date next_weekday(const Date& d);
	int week_of_year(const Date& d);
} // Chrono