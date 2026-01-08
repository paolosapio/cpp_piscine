#include "Fixed.hpp"

/* ---------------------------contructor por defecto--------------------------- */
Fixed::Fixed() : _fpn(0)
{
	std::cout << "Default constructor called\n";
}


/* ---------------------------copy construccotr--------------------------- */
Fixed::Fixed(const Fixed &other)  : _fpn(other._fpn)
{
	std::cout << "Copy constructor called\n";
}


Fixed::Fixed(const int nb_integer) : _fpn(nb_integer << _fractional)
{
}


Fixed::Fixed(const float nb_float) : _fpn(roundf(nb_float * (1 << _fractional)))
{
}

/* ---------------------------copy assignemet operator---------------------------*/
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignemet operator called\n"; // y si no existe other?!?!
	this->_fpn = other._fpn;
	return (*this);
}


/* ---------------------------compare operator--------------------------- */
bool Fixed::operator>(const Fixed &other)
{
	if (this->_fpn > other._fpn) 
		return (false);
	return (true);
}

bool Fixed::operator<(const Fixed &other)
{
	if (this->_fpn < other._fpn) 
		return (false);
	return (true);
}

Fixed &operator>=(const Fixed &other)
{

}

Fixed &operator<=(const Fixed &other)
{

}

Fixed &operator==(const Fixed &other)
{

}

Fixed &operator!=(const Fixed &other)
{

}



/* ---------------------------aritmeticos operator--------------------------- */
Fixed &operator+(const Fixed &other)
{

}

Fixed &operator-(const Fixed &other)
{

}

Fixed &operator*(const Fixed &other)
{

}

Fixed &operator/(const Fixed &other)
{

}




/* ---------------------------SUMAR pre operator--------------------------- */
Fixed &operator++()
{

}

/* ---------------------------SUMAR post operator--------------------------- */
Fixed operator++(int)
{

}

/* ---------------------------RESTAR pre operator--------------------------- */
Fixed &operator--()
{

}

/* ---------------------------RESTAR post operator--------------------------- */
Fixed operator--(int)
{

}



/* ---------------------------Destructir por defecto--------------------------- */
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";

}



int getRawBits(void) const
{

}

void setRawBits(int const raw)
{

}

float toFloat(void) const
{

}

int toInt(void) const
{

}

std::ostream &operator<<(std::ostream &out, const Fixed &right)
{

}


