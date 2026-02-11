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
	Fixed();	//contructor por defecto
	Fixed(const Fixed &other);	//copy construccotr

	Fixed(const int nb_integer);
	Fixed(const float nb_float);

	// static significa que este metodo se puede utilizar sin declar el objeto entrando atrave de namespace (en este caso Fixed::)
	// MAX VALUE
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &max( Fixed &a,  Fixed &b);

	// MIN VALUE
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);

	//copy assignemet operator
	Fixed &operator=(const Fixed &other);

	//compare operator
	bool operator>(const Fixed &other); 
	bool operator<(const Fixed &other); 
	bool operator>=(const Fixed &other); 
	bool operator<=(const Fixed &other); 
	bool operator==(const Fixed &other); 
	bool operator!=(const Fixed &other); 

	//aritmeticos operator
	Fixed &operator+(const Fixed &other);
	Fixed &operator-(const Fixed &other);
	Fixed &operator*(const Fixed &other);
	Fixed &operator/(const Fixed &other);

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
