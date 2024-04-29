#include "Reading.h"


std::istream& operator>>(std::istream& is, Reading& r)
{
	char c;
	if (is >> c && c != '(')
	{
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
