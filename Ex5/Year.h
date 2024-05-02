#pragma once
#include "Month.h"

struct Year
{
	unsigned short year{};
	std::vector<Month> month{std::vector<Month>(12)};
};

std::istream& operator>>(std::istream& is, Year& y);

std::ostream& operator<<(std::ostream& os, Year& y);