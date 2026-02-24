#include "ScalarConverter.hpp"



// 123456789.123456789f


int main(int argn, char *argv[])
{
	std::stringstream stringConversor;

	int aInt;
	std::string stringo = "7";

	stringConversor << stringo;
	stringConversor >> aInt;
	std::cout << aInt << "\n";

	if (argn != 2)
	{
		std::cerr << "n args raro\n";
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
