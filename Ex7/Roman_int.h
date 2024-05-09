#pragma once
#include <iostream>

class Error {};

class Roman_int
{
public:
	int as_int() { return num_int; }
	Roman_int(std::string n_r);
	Roman_int(int n_i);
	Roman_int();

	std::string get_roman() const { return num_rom; }
	int get_int() const { return num_int; }

	std::string& get_r_ref() { return num_rom; }
	int& get_int_ref() { return num_int; }
private:
	int num_int;
	std::string num_rom;
};

std::string& concat_order_of_magnitude(int o_m, std::string& num, char current, char next, char after_next);
int& get_digit(int& out_o_m, std::string& num, char current, char next, char after_next);
std::ostream& operator<<(std::ostream& os, const Roman_int& r);
std::istream& operator>>(std::istream& is, Roman_int& r);