#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <limits>
#include <cfloat>
#include <math.h>

// 123456789.123456789f


// conversor de tipos str a nbr
/* 	std::stringstream stringConversor;

	int aInt;
	std::string stringo = "7 89 7";

	stringConversor << stringo;
	stringConversor >> aInt;
	std::cout << aInt << "\n";
*/


int main(int argn, char *argv[])
{
	if (argn != 2)
	{
		std::cerr << "n args raro\n";
		return (1);
	}
	




	// float f = std::atof(argv[1]);

	// if (f != f)
	// {
	// 	std::cout << "Number is a nan" << std::endl;
	// }

	// if (f > FLT_MAX)
	// {
	// 	std::cout << "Number is +inf" << std::endl;
	// }

	// if (f < FLT_MIN)
	// {
	// 	std::cout << "Number is -inf" << std::endl;
	// }


	// std::cout << std::setprecision(10) << std::atof(argv[1]) << std::endl;
	ScalarConverter::convert(argv[1]);

	return (0);
}
