#pragma once
#include "Month.h"

struct Year
{
	unsigned int year{};
	std::vector<Month> month{ 12 };
};

std::istream& operator>>(std::istream& is, Year& y);

std::ostream& operator<<(std::ostream& os, Year& y);