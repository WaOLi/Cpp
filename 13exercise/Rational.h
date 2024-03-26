#pragma once
#include <iostream>

class Rational
{
public:
	Rational(int num, int den);
	double get_decimal() const { return decimal; }
	int get_numerator() const { return numerator; }
	int get_denominator() const { return denominator; }

	bool operator==(const Rational& other) const;
	bool operator!=(const Rational& other) const;
	Rational& operator=(const Rational& other);
	Rational operator+(const Rational& other);
	Rational operator-(const Rational& other);
	Rational operator*(const Rational& other);
	Rational operator/(const Rational& other);

	Rational& simplify();
	void set_decimal();
private:
	int numerator;
	int denominator;
	double decimal;
};

std::ostream& operator<<(std::ostream& os, const Rational& r);