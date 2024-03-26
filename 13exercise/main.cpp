#include "Money.h"
#include "Rational.h"
int main()
{
	Money m1(1225.451, Money::Currency::UAH);
	Money m2(34.162, Money::Currency::UAH);
	std::cout << m1 << std::endl << m2 << std::endl << m1 + m2 << std::endl;
	std::cout << m1 - m2;

	Money m3(0, Money::Currency::None);
	std::cin >> m3;
	std::cout << m3;
}