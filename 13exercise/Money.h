#pragma once
#include <iostream>

class Money
{
public:
	enum class Currency
	{
		UAH = 0, USD, TL, None
	};
	Money(double c, Currency cu);
	long int get_cents() const { return cents; }
	Currency get_currency() const { return cur; }

	Money operator*(double mul) const;
	friend Money operator*(double mul, const Money m);
	Money operator/(double div) const;
	Money operator+(const Money& other) const;
	Money operator-(const Money& other) const;
	void set_cur(const Money::Currency& c) { cur = c; }
	void set_cents(long int c) { cents = c; }
private:
	long int cents;
	Currency cur;
};

std::ostream& operator<<(std::ostream& os, const Money& mon);
std::ostream& operator<<(std::ostream& os, const Money::Currency& cur);
Money& operator>>(std::istream& is, Money& mon);
