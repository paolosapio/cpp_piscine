#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(const float nb_float) : fpn(static_cast<int>(roundf(nb_float * (1 << fractional))))
{                                 // fpn(nb_float * float(1 << fractional) + (nb_float >= 0 ? 0.5 : -0.5))
	std::cout << "Float constructor called\n";
}



Fixed::Fixed(const int nb_integer) : fpn(nb_integer * int(1 << fractional))
{
	std::cout << "Int constructor called\n";
}



Fixed::Fixed() : fpn(0)
{
	std::cout << "Default constructor called\n";
}



Fixed::Fixed(const Fixed &other) : fpn(other.fpn)
{
	// Copy constructor implementation
	std::cout << "Copy constructor called\n";
}



Fixed &Fixed::operator=(const Fixed &other)
{
	// Copy assignment operator implementation
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
	return *this;
	this->setRawBits(other.getRawBits());
	return *this;
}



std::ostream &operator<<(std::ostream &out, const Fixed &right)
{
	out << right.toFloat();
	return (out);
}



Fixed::~Fixed()
{
	// Destructor implementation
	std::cout << "Destructor called\n";
}



void Fixed::setRawBits(const int raw)
{
	fpn = raw;
}



int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fpn);
}



float Fixed::toFloat(void) const
{
	return (float(fpn) / float(1 << fractional));
}



int Fixed::toInt(void) const
{
	return (int(fpn) / int(1 << fractional));
}
