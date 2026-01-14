#include "Fixed.hpp"


int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed c(Fixed(5.05f));
	c = c * Fixed(2);
	std::cout << c << std::endl;


	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;


	Fixed h(10.0f);
	std::cout << "h antes de dividir: "<< h << std::endl;

	h = h / Fixed(3.0f);
	std::cout << "h despues de dividir:"<< h << std::endl;


	Fixed x(19);
	std::cout << "x antes de multiplicar: "<< x << std::endl;
	x = x * Fixed(2.5f);
	std::cout << "x despues de multiplicar: "<< x << std::endl;
	x = x / Fixed(2);
	std::cout << "x despues de dividirlo por 2: "<< x << std::endl;

	
	return (0);
}