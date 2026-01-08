#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);

#endif