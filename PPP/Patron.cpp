#include "Patron.h"

std::ostream& operator<<(std::ostream& os, Patron& p)
{
	// TODO: insert return statement here
	return os << "Card number: " << p.get_card_number() << "\nuser name: " << p.get_usr_name() << "\nfees: " << (p.owes_fees() ? p.get_lib_fees() : 0);
}

Patron::Patron(int ID, std::string name, int init_fees)
	:lib_card_num{ID}, usr_name{name}, lib_fees{init_fees}
{
}
