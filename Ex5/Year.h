#pragma once
#include "Month.h"

struct Year
{
	unsigned int year{};
	std::vector<Month> month{ 12 };
};