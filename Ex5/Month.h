#pragma once
#include "Day.h"

static constexpr int not_a_month{ -1 };

struct Month
{
	int month{ not_a_month };
	std::vector<Day> day{ 32 };
};

unsigned short month_string_to_int(std::string& mon);

std::string month_int_to_string(unsigned short mon);

std::istream& operator>>(std::istream& is, Month& m);

std::ostream& operator<<(std::ostream& os, const Month& m);