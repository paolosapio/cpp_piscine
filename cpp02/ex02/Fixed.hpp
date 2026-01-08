#ifndef EX02_FIXED_HPP
#define EX02_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fpn; //fied point number
	static const int _fractional = 8;
	
public:
	Fixed();                    //contructor por defecto
	Fixed(const Fixed &other);  //copy construccotr
	Fixed(const int nb_integer);
	Fixed(const float nb_float);

	Fixed &operator=(const Fixed &other); //copy assignemet operator

	bool operator>(const Fixed &other); //compare operator
	bool operator<(const Fixed &other); //compare operator
	bool operator>=(const Fixed &other); //compare operator
	bool operator<=(const Fixed &other); //compare operator
	bool operator==(const Fixed &other); //compare operator
	bool operator!=(const Fixed &other); //compare operator

	Fixed &operator+(const Fixed &other); //aritmeticos operator
	Fixed &operator-(const Fixed &other); //aritmeticos operator
	Fixed &operator*(const Fixed &other); //aritmeticos operator
	Fixed &operator/(const Fixed &other); //aritmeticos operator

	Fixed &operator++();    //SUMAR pre operator
	Fixed operator++(int);  //SUMAR post operator

	Fixed &operator--();    //RESTAR pre operator
	Fixed operator--(int);  //RESTAR post operator
    
	~Fixed();   //destructir por defecto

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);


#endif // EX02_FIXED_HPP
