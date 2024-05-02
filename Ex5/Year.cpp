#include "Year.h"

std::istream& operator>>(std::istream& is, Year& y)
{
    // TODO: insert return statement here
    //{year XXXX{month ???(n n d)(n n d)} }

    char c;
    if (is >> c && c != '{')
    {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    std::string year_maker;
    int yy;

    is >> year_maker >> yy;

    if (year_maker != "year")
    {
        std::cerr << "wrong beginning of the year";
        throw Error{};
    }
    y.year = yy;

    if (y.year < 1900 || y.year > 2000)
    {
        std::cerr << "year out of range\n" << y.year;

        throw Error{};
    }

    Month m;
    while (is >> m)
    {
        y.month[m.month] = m;
        m = Month{};
    }

    if(is.fail())
    {
        is.clear(std::ios_base::goodbit);
    }

    if (is >> c && c != '}')
    {
        std::cerr << "wrong end of year";
        throw Error{};
    }
    else
    {
        return is;
    }
}

std::ostream& operator<<(std::ostream& os, Year& y)
{
    // TODO: insert return statement here
    os << '{' << "year " << y.year << ' ';
    for (const Month& m : y.month)
    {
        if (m.month != not_a_month)
        {
            os << m;
        }
    }
    return os << '}';
}


//{year 1992 {month feb (1 2 3)}{month dec (5 1 23.41)(5 2 -12.43)}}

Year::Year(unsigned short y)
    :year{y}
{
}
