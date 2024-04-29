#pragma once
#include <iostream>

class Error {};

struct Reading
{
	int day, hour;
	double temperature;
};

std::istream& operator>>(std::istream& is, Reading& r);

std::ostream& operator<<(std::ostream& os, const Reading& r);

