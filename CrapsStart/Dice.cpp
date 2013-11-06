#include "Dice.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

Dice::Dice() :
				value( 1)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Dice::Dice( unsigned long aValue) :
				value( aValue)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	if (value == 0 || value > 6)
	{
		std::ostringstream os;
		os << "Dice::Dice( unsigned long aValue) argument out of range [1...6]: " << aValue;
		throw std::invalid_argument( os.str());
	}
}

Dice::Dice( const Dice& aDice) :
				value( aDice.value)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Dice::~Dice()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bool Dice::operator==( const Dice& aDice) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return value == aDice.value;
}

Dice& Dice::operator=( const Dice& aDice)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	// Prevent self-assignment, see http://www.parashift.com/c++-faq/self-assignment-what.html
	if (this != &aDice)
	{
		value = aDice.value;
	}
	return *this;
}

unsigned long Dice::getValue() const
{

	return value;
}

void Dice::setValue( unsigned long aValue)
{
	if (aValue == 0 || aValue > 6)
	{
		std::ostringstream os;
		os << "Dice::setValue argument out of range [1...6]: " << aValue;
		throw std::invalid_argument( os.str());
	}
	value = aValue;
}

std::ostream& operator<<( 	std::ostream& os,
							const Dice& aDice)
{
	return os << aDice.value;
}
