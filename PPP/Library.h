#pragma once
#include "Book.h"
#include "Patron.h"
#include <vector>

class Library
{
public:
	void add_book(Book& book);
	void add_patron(Patron& patron);
	void checkout_book(Book& b, Patron& p, Chrono::Date& d);

	std::vector<Patron>& get_owers();
private:
	struct Transaction
	{
		Transaction(Book& b, Patron& p, Chrono::Date d);
		Book book;
		Patron patron;
		Chrono::Date date;
	};
	std::vector<Transaction> transactions;
	std::vector<Book> books;
	std::vector<Patron> patrons;
};

bool operator==(Patron& p1, Patron& p2);