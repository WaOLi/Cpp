#include "Book.h"
#include <sstream>

int main()
{
	std::string input;
	std::cin >> input;

	Book b{ "harry potter", "J.K.Rowling", input, Chrono::Date{23, 1997, Chrono::Month::jan}, Book::Genre::children };
	std::cout << b;

}