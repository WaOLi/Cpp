#pragma once
#include <iostream>

class Error {};

class Roman_int
{
public:
	int as_int() { return num_int; }
	Roman_int(std::string n_r);
	Roman_int(int n_i);
private:
	int num_int;
	std::string num_rom;
};

std::string& concat_order_of_magnitude(int o_m, std::string& num, char current, char next, char after_next);
int& get_digit(int& out_o_m, std::string& num, char current, char next, char after_next);
//std::ostream& operator<<(std::ostream& os, const Roman_int& r);
//std::istream& operator>>(std::istream& is, const Roman_int& r);