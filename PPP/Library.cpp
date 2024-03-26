#include "Library.h"

void Library::add_book(Book& book)
{
	books.push_back(book);
}

void Library::add_patron(Patron& patron)
{
	patrons.push_back(patron);
}

void Library::checkout_book(Book& b, Patron& p, Chrono::Date& d)
{	
	if (p.owes_fees())
	{
		std::cerr << p << "\t-has fees";
	}
	for (Book b_ : this->books)
	{
		if (b_ == b)
		{
			for (Patron p_ : this->patrons)
			{
				if (p_ == p)
				{
					b_.check_out();
					Transaction t(b_, p_, Chrono::Date(12, 1996, Chrono::Month::feb));

					transactions.push_back(t);
				}
			}
		}
	}
	std::cerr << "cannot checkout " << b;
}

std::vector<Patron>& Library::get_owers()
{
	// TODO: insert return statement here
	std::vector<Patron> result;
	for (Patron p : patrons)
	{
		if (p.get_lib_fees() > 0)
		{
			result.push_back(p);
		}
	}
	return result;
}

bool operator==(Patron& p1, Patron& p2)
{
	if (p1.get_card_number() == p2.get_card_number())
	{
		return true;
	}
	return false;
}

Library::Transaction::Transaction(Book& b, Patron& p, Chrono::Date d)
	:book{ b }, patron{ p }, date{ d }
{
}
