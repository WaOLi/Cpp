#include <iostream>
#include "Utilities.h"

namespace Chrono
{
	enum class Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Date
	{
	public:
		Date(int d, int y, Month m);

		int get_day() const { return day; }
		int get_year() const { return day; }
		Month get_month() const { return month; }
	private:
		int day;
		int year;
		Month month;
	};
}

class Book
{
public:
	class Impropper {};
	enum class Genre
	{
		fiction = 1, nonfiction, periodical, biography, children
	};

	std::string get_title() const { return title; }
	std::string get_author() const { return author; }
	std::string get_isbn() const { return ISBN; }
	Chrono::Date get_date() const { return cpy_rght_date; }
	Book(std::string t, std::string a, std::string isbn, Chrono::Date d, Genre g);

	void check_in();
	void check_out();

	bool get_checked_in_status() const { return checked_in; }

	bool is_valid_book() const;

	bool check_isbn() const;
	Genre get_genre() const { return genre; }

	friend std::ostream& operator<<(std::ostream& os, const Book& d);
private:
	std::string title;
	std::string author;
	std::string ISBN;
	Chrono::Date cpy_rght_date;
	Genre genre;

	bool checked_in{};
};

bool operator==(const Book& b1, const Book& b2);

bool operator==(const Chrono::Date& d1, const Chrono::Date& d2);

std::ostream& operator<<(std::ostream& os, const Chrono::Date& d);

bool operator!=(const Book& b1, const Book& b2);