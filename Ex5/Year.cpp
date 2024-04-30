#include "Year.h"

std::istream& operator>>(std::istream& is, Year& y)
{
    // TODO: insert return statement here
    //{year XXXX{month ???(n n d)(n n d)} }
    char c;
    if (is >> c && c != '{')
    {

    }
    if (y.year < 1900 || y.year > 2000)
    {
        std::cerr << "year out of range";
        throw Error{};
    }
}

std::ostream& operator<<(std::ostream& os, Year& y)
{
    // TODO: insert return statement here
}
