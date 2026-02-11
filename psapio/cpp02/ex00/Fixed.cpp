#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fpn(0)
{
    std::cout << "Default constructor called\n";
}


// Copy constructor implementation
Fixed::Fixed(const Fixed &other) : _fpn(other._fpn)
{
    std::cout << "Copy constructor called\n";
}


// Copy assignment operator implementation
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    this->setRawBits(other.getRawBits());
    return (*this);
}


// Destructor implementation
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (_fpn);
}


void Fixed::setRawBits(const int raw)
{
    _fpn = raw;
}
