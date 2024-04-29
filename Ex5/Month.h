#pragma once
#include "Day.h"

static constexpr int not_a_month{ -1 };

struct Month
{
	int month{ not_a_month };
	std::vector<Day> day{32};
};