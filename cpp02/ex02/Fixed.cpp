#include "Fixed.hpp"

/* ---------------------------contructor por defecto--------------------------- */
Fixed::Fixed() : _fpn(0)
{
	// std::cout << "Default constructor called\n";
}


/* ---------------------------copy construccotr--------------------------- */
Fixed::Fixed(const Fixed &other)  : _fpn(other._fpn)
{
	// std::cout << "Copy constructor called\n";
}


Fixed::Fixed(const int nb_integer) : _fpn(nb_integer << _fractional)
{
}


Fixed::Fixed(const float nb_float) : _fpn(roundf(nb_float * (1 << _fractional)))
{
}

/* ---------------------------copy assignemet operator---------------------------*/
Fixed& Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignemet operator called\n"; // y si no existe other?!?!
	this->_fpn = other._fpn;
	return (*this);
}


/* --------------------------Operadores de comparacion-------------------------- */
bool Fixed::operator>(const Fixed &other)
{
	return (this->_fpn > other._fpn);
}

bool Fixed::operator<(const Fixed &other)
{
	if (this->_fpn < other._fpn) 
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other)
{
	if (this->_fpn >= other._fpn) 
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other)
{
	if (this->_fpn <= other._fpn) 
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other)
{
	if (this->_fpn == other._fpn) 
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other)
{
	if (this->_fpn != other._fpn) 
		return (true);
	return (false);
}



/* ------------- (overloaded member function) ------------ */

// MAX VALUE
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

// MIN VALUE
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}



/* ---------------------------aritmeticos operator--------------------------- */
Fixed& Fixed::operator+(const Fixed &other)
{
	this->_fpn = this->_fpn + other._fpn;
	return (*this);
}

Fixed& Fixed::operator-(const Fixed &other)
{
	this->_fpn = this->_fpn - other._fpn;
	return (*this);
}

Fixed& Fixed::operator*(const Fixed &other)
{
	this->_fpn = (this->_fpn * other._fpn) / (1 << this->_fractional);
	return (*this);
}

Fixed& Fixed::operator/(const Fixed &other)
{
	if (other._fpn != 0)
	{
		this->_fpn = ((this->_fpn << this->_fractional) / other._fpn);
		return (*this);
	}

	return (*this);
}



/* --------------------------OPERADORES ITERATVOS--------------------------- */
// pre SUMAR
Fixed &Fixed::operator++()
{
	this->_fpn++;
	return (*this);
}

// post SUMAR
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fpn++;
	return (tmp);
}

// pre RESTAR
Fixed& Fixed::operator--()
{
	this->_fpn--;
	return (*this);
}

// post RESTAR
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fpn--;
	return (tmp);
}



// /* ---------------------------Getter - Setter--------------------------- */
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return (_fpn);
}

void Fixed::setRawBits(const int raw)
{
	_fpn = raw;
}



// /* ---------------------------CONVERT TYPE--------------------------- */
float Fixed::toFloat(void) const
{
	return (float(_fpn) / float(1 << _fractional));
}

int Fixed::toInt(void) const
{
	return (_fpn / 1 << _fractional);
}



// /* ---------------------------out stream--------------------------- */
std::ostream &operator<<(std::ostream &out, const Fixed &right)
{
	out << right.toFloat();
	return (out);
}



/* ------------------------Destructor por defecto----------------------- */
Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
}
