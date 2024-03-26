#include "Money.h"

Money::Money(double c, Currency cu)
	:cur{cu}
{
	double d = std::trunc(c);
	c - d < .5 ? cents = long(d) : cents = long(d + 1);
}

Money Money::operator*(double mul) const
{
	return Money(this->get_cents() * mul, this->get_currency());
}

Money Money::operator/(double div) const
{
	return Money(this->get_cents() / div, this->get_currency());
}

Money Money::operator+(const Money& other) const
{
	switch (this->get_currency())
	{
	case Money::Currency::TL:
		switch (other.get_currency())
		{
		case Money::Currency::TL:
			return Money(this->get_cents() + other.get_cents(), other.get_currency());
			break;
		case Money::Currency::USD:
			return Money(this->get_cents() + other.get_cents() * 32.38, other.get_currency());
			break;
		case Money::Currency::UAH:
			return Money(this->get_cents() + other.get_cents() * .83, other.get_currency());
			break;
		default:
			std::cerr << "invalid currency";
			return Money(0, Money::Currency(3));
		}
	case Money::Currency::USD:
		switch (other.get_currency())
		{
		case Money::Currency::TL:
			return Money(this->get_cents() + other.get_cents() / 32.38, other.get_currency());
			break;
		case Money::Currency::USD:
			return Money(this->get_cents() + other.get_cents(), other.get_currency());
			break;
		case Money::Currency::UAH:
			return Money(this->get_cents() + other.get_cents() / 39.1, other.get_currency());
			break;
		default:
			std::cerr << "invalid currency";
			return Money(0, Money::Currency(3));
		}
	case Money::Currency::UAH:
		switch (other.get_currency())
		{
		case Money::Currency::TL:
			return Money(this->get_cents() + other.get_cents() * 1.21, other.get_currency());
			break;
		case Money::Currency::USD:
			return Money(this->get_cents() + other.get_cents() * 39.1, other.get_currency());
			break;
		case Money::Currency::UAH:
			return Money(this->get_cents() + other.get_cents(), other.get_currency());
			break;
		default:
			std::cerr << "invalid currency";
			return Money(0, Money::Currency(3));
		}
	default:
		return Money(0, Money::Currency(3));
	}
}

Money Money::operator-(const Money& other) const
{
	Money temp(-other.get_cents(), other.get_currency());
	return Money(*this + temp);
}

Money operator*(double mul, const Money m)
{
	return Money(m.get_cents() * mul, m.get_currency());
}

std::ostream& operator<<(std::ostream& os, const Money& mon)
{
	std::string s;
	if (mon.get_cents() % 100 < 10)
	{
		s += '0';
		s += (char(mon.get_cents() % 100) + '0');
	}
	else
	{
		int temp = mon.get_cents() % 100;
		int temp2 = mon.get_cents() % 10;
		temp -= temp2;
		temp /= 10;
		s += temp + '0';
		s += temp2 + '0';
	}
	return os << mon.get_currency() << mon.get_cents() / 100 << '.' << s << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Money::Currency& cur)
{
	std::string s;
	switch (cur)
	{
	case Money::Currency::TL:
		s = "TL";
		break;
	case Money::Currency::USD:
		s = "USD";
		break;
	case Money::Currency::UAH:
		s = "UAH";
		break;
	default:
		s = "None";
	}
	return os << s;
}

Money& operator>>(std::istream& is, Money& mon)
{
	std::string s, _cur;
	bool passed_a_digit{};
	is >> s;
	long int i{};

	for(char c : s)
	{
		if(!isdigit(c) && !passed_a_digit)
		{
			_cur += c;
		}
		else
		{
			passed_a_digit = true;
			if()
		}
	}

	switch (_cur[0])
	{
	case 'T':
		if (_cur == "TL")
		{
			mon.set_cur(Money::Currency::TL);
		}
		else
		{
			std::cerr << "Unknown currency: \"" << _cur << "\"";
		}
		break;
	case 'U':
		if (_cur == "USD")
		{
			mon.set_cur(Money::Currency::USD);
		}
		else if (_cur == "UAH")
		{
			mon.set_cur(Money::Currency::UAH);
		}
		else
		{
			std::cerr << "Unknown currency: \"" << _cur << "\"";
		}
		break;
	default:
		std::cerr << "Unknown currency: \"" << _cur << "\"";
		break;
	}
	return mon;
}