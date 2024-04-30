#include "Reading.h"


bool is_valid(const Reading& r)
{
	if (r.day > 31 || r.day < 0
		|| r.hour > 23 || r.hour < 0
		|| r.temperature > 200 || r.temperature < -200)
	{
		return false;
	}
	return true;
}

std::istream& operator>>(std::istream& is, Reading& r)
{
	char c;
	if (is >> c && c != '(')
	{
		is.unget();
		is.clear(std::ios_base::failbit);
		throw Error{};
	}

	int d, h;
	double t;

	is >> d >> h >> t >> c;

	if (!is || c != ')') throw Error{};

	r.day = d;
	r.hour = h;
	r.temperature = t;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Reading& r)
{
	return os << '(' << r.day << ' ' << r.hour << ' ' << r.temperature << ')';
}
