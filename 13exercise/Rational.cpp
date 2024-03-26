#include "Rational.h"

Rational::Rational(int num, int den)
	:numerator{num},denominator{den}, decimal{double(num)/den}
{
}

bool Rational::operator==(const Rational& other) const
{
	if (other.get_decimal() == this->get_decimal())
	{
		return true;
	}
	return false;
}

bool Rational::operator!=(const Rational& other) const
{
	return !(this->get_decimal() == other.get_decimal());
}

Rational& Rational::operator=(const Rational& other)
{
	// TODO: insert return statement here
	this->denominator = other.get_denominator();
	this->numerator = other.get_numerator();
	return *this;
}

Rational Rational::operator+(const Rational& other)
{
	// TODO: insert return statement here
	int n = other.get_denominator() * this->get_numerator() + other.get_numerator() * this->get_denominator();
	int d = other.get_denominator() * this->get_denominator();
	Rational result(n, d);

	result.simplify();

	result.set_decimal();
	return result;
}

Rational Rational::operator-(const Rational& other)
{
	// TODO: insert return statement here
	Rational temp(-other.get_numerator(), other.get_denominator());

	return (*this + temp).simplify();
}

Rational Rational::operator*(const Rational& other)
{
	// TODO: insert return statement here
	Rational result(this->get_numerator() * other.get_numerator(), this->get_denominator() * other.get_denominator());
	result.set_decimal();
	return result;
}

Rational Rational::operator/(const Rational& other)
{
	// TODO: insert return statement here
	int temp = other.numerator;
	Rational& mutable_other = const_cast<Rational&>(other);
	mutable_other.numerator = other.get_denominator();
	mutable_other.denominator = temp;

	std::cout << "\n======================\n" << other << std::endl << mutable_other << "\n-------------------------------\n";
	return (*this) * other;
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	// TODO: insert return statement here

	return os << r.get_numerator() << '/' << r.get_denominator() << std::endl<< r.get_decimal() << std::endl;
}

Rational& Rational::simplify()
{
	// TODO: insert return statement here
	for (int i{ 2 }; i < (this->get_denominator() / 2); i++)
	{
		if (this->get_denominator() % i == 0 && this->get_numerator() % i == 0)
		{
			this->denominator /= i;
			this->numerator /= i;
			i = 1;
		}
	}
	return *this;
}

void Rational::set_decimal()
{
	this->decimal = double(this->get_numerator()) / this->get_denominator();
}
