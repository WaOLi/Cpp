#include "Month.h"

unsigned short month_string_to_int(std::string& mon)
{
	std::vector<std::string> mon_names
	{
		"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"
	};

	for (int i{}; i < mon_names.size(); i++)
	{
		if (mon == mon_names[i])
		{
			return i;
		}
	}
	return not_a_month;
}

std::string month_int_to_string(unsigned short mon)
{
	switch (mon)
	{
	case 0:
		return "jan";
	case 1:
		return "feb";
	case 2:
		return "mar";
	case 3:
		return "apr";
	case 4:
		return "may";
	case 5:
		return "jun";
	case 6:
		return "jul";
	case 7:
		return "aug";
	case 8:
		return "sep";
	case 9:
		return "oct";
	case 10:
		return "nov";
	case 11:
		return "dec";
	default:
		std::cerr << "wrong month value";
		throw Error{};
	}
}

std::istream& operator>>(std::istream& is, Month& m)
{
	// TODO: insert return statement here
	char c;
	if (is >> c && c != '{')
	{
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	std::string month_key, mm;
	if (is >> month_key && month_key != "month")
	{
		std::cerr << "wrong beginning of month";
		throw Error{};
	}
	is >> mm;

	unsigned short month{ month_string_to_int(mm) };

	if (month == not_a_month)
	{
		std::cerr << "not a month";
		throw Error{};
	}

	m.month = month;

	unsigned int duplicates{}, invalids{};

	for (Reading r; is >> r;)
	{
		if (is_valid(r))
		{
			if (m.day[r.day].hour[r.hour] != not_a_reading)
			{
				++duplicates;
			}
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else
		{
			++invalids;
		}
	}

	if (duplicates)
	{
		std::cerr << "duplicates present";
		throw Error{};
	}

	if (invalids)
	{
		std::cerr << "duplicates or invalid readings present";
		throw Error{};
	}
	if (is.fail())
	{
		is.clear(std::ios_base::goodbit);
	}
	if (is >> c && c != '}')
	{
		std::cerr << "invalid ending of the month";
		throw Error{};
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Month& m)
{
	// TODO: insert return statement here
	os << '{' << "month " << month_int_to_string(m.month) << ' ';

	for (int i{ 1 }; i < m.day.size();i++)
	{
		for (int j{}; j < m.day[0].hour.size(); j++)
		{
			if (m.day[i].hour[j] != not_a_reading)
			{
				os << '(' << i << ' ' << j << ' ' << m.day[i].hour[j] << ')';
			}
		}
	}
	return os << '}';
}