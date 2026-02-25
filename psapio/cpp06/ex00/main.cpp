#include "ScalarConverter.hpp"



// 123456789.123456789f


// conversor de tipos str a nbr
/* 	std::stringstream stringConversor;

	int aInt;
	std::string stringo = "7";

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
	ScalarConverter::convert(argv[1]);

	return (0);
}
