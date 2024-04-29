#include <vector>
#include "Reading.h"

static constexpr int not_a_reading{ -7777 };

struct Day
{
	std::vector<double> hour{ std::vector<double>(24, not_a_reading) };
};