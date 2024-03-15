#include "Book.h"


Chrono::Date::Date(int d, int y, Month m)
	:day{ d }, year{ y }, month{ m }
{
}

Book::Book(std::string t, std::string a, std::string isbn, Chrono::Date d, Genre g)
	:title{ t }, author{ a }, ISBN{ isbn }, cpy_rght_date{ d }, genre{ g }
{
	if (!is_valid_book())
	{
		throw Impropper();
	}
}

void Book::check_in()
{
	if (checked_in)
	{
		std::cerr << "book already checked in";
	}
	else
	{
		checked_in = true;
	}
}

void Book::check_out()
{
	if (!checked_in)
	{
		std::cerr << "book already checked out";
	}
	else
	{
		checked_in = false;
	}
}

bool Book::is_valid_book() const
{
	if (!this->title.length() && !this->author.length())
	{
		return false;
	}
	if (!check_isbn())
	{
		return false;
	}
	return true;
}

bool Book::check_isbn() const
{
	if (!count_dash(get_isbn()))
	{
		std::cout << "3";
		return false;
	}
	std::string temp[4]{};

	for (int j{}, i{}; i < get_isbn().length(); i++)
	{
		if (j < 3)
		{
			if (isdigit(get_isbn()[i]))
			{
				temp[j] += get_isbn()[i];
			}
			else if (get_isbn()[i] == '-')
			{
				j++;
			}
			else
			{
				std::cout << "a symbol in a digits-only place";
				return false;
			}
		}
		else
		{
			temp[j] += get_isbn()[i];
		}
	}
	for (std::string s : temp)
	{
		if (s.length() == 0)
		{
			std::cout << "1";
			return false;
		}
	}
	if (temp[3].length() != 1)
	{
		std::cout << "2";
		return false;
	}
	return true;


	if (temp[3].length() != 1)
	{
		return false;
	}
	for (std::string s : temp)
	{
		if (s.length() == 0)
		{
			return false;
		}
	}
	return true;
}

bool operator==(const Book& b1, const Book& b2)
{
	if (b1.get_author() == b2.get_author() && b1.get_title() == b2.get_title() && b1.get_date() == b2.get_date() && b1.get_checked_in_status() == b2.get_checked_in_status())
	{
		return true;
	}
	return false;
}

bool operator==(const Chrono::Date& d1, const Chrono::Date& d2)
{
	if (d1.get_day() == d2.get_day() && d1.get_month() == d2.get_month() && d1.get_year() == d2.get_year())
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Chrono::Date& d)
{
	std::string s;
	switch (d.get_month())
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
		std::cerr << "month is out";
	}

	return os << "Day: " << d.get_day() << "\nmonth: " << s << "\nyear" << d.get_year();
}

bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1 == b2);
}

std::ostream& operator<<(std::ostream& os, const Book& b)
{
	std::string s;
	switch (b.get_genre())
	{
	case Book::Genre::biography:
		s = "biography";
		break;
	case Book::Genre::children:
		s = "children";
		break;
	case Book::Genre::fiction:
		s = "fiction";
		break;
	case Book::Genre::nonfiction:
		s = "nonfiction";
		break;
	case Book::Genre::periodical:
		s = "periodical";
		break;
	default:
		std::cerr << "false genre";
	}
	return os << "Title: " << b.get_title() << "\nauthor: " << b.get_author() << "\nISBN: " << b.get_isbn() << "\ngenre: " << s;
}