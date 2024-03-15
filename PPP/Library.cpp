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
	
	for (Book b_temp : books)
	{
		if (b_temp == b)
		{
			static Book& _b = b_temp;
			b_temp.check_out();
		}
	}
}
