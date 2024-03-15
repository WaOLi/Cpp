#pragma once
#include <iostream>

class Patron
{
public:
	int get_card_number() const { return lib_card_num; }
	std::string get_usr_name() const { return usr_name; }
	int get_lib_fees() const { return lib_fees; }
	void set_user(std::string name) { usr_name = name; }
	void set_fees(int new_fees) { lib_fees = new_fees; }
	bool owes_fees() { return lib_fees > 0 ? true : false; }

private:
	int lib_card_num;
	std::string usr_name;
	int lib_fees;

};