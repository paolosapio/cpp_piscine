#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int _fpn; //fied point number	
	static const int _fractional = 8;
	
public:
	Fixed();                     //contructor por defecto
	Fixed(const Fixed &other);   //copy construccotr
	Fixed(const float nb_float); //CONSTRUCTOR de fixed desde FLOAT
	Fixed(const int nb_integer); //CONSTRUCTOR de fixed desde INT

	Fixed &operator=(const Fixed &other); //copy assignemet operator
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const; //CONVERSOR de fixed a float
	int toInt(void) const; //CONVERSOR de fixed a int
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);

#endif