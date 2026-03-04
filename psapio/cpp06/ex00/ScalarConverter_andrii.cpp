#include <cstdlib>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return(*this);
}

ScalarConverter::~ScalarConverter()
{
}


void desarolloNegInff(void)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : -inff\n";
	std::cout << "double: -inf\n";
}

void desarolloInff(void)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : inff\n";
}

void desarolloNanf(void)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : nanf\n";
	std::cout << "double: nan\n";
}

void desarolloNegInf(void)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : -inff\n";
	std::cout << "double: -inf\n";
}

void desarolloInf(void)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : inff\n";
	std::cout << "double: inf\n";
}

void desarolloNan(void)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : nanf\n";
	std::cout << "double: nan\n";
}


void desaroChar(char c)
{
	std::cout << "char  : '" << c << "'\n";
	std::cout << "int   : " << static_cast<int>(c) << "\n"; // static cast
	std::cout << "float : " << static_cast<float>(c) << ".0f\n"; // static cast
	std::cout << "double: " << static_cast<double>(c) << ".0\n"; // static cast
}



bool CheckPseudoChar(const std::string &stringVal)
{
	if (stringVal.length() == 5 && stringVal.compare("-inff") == 0)
	{
		desarolloNegInff();
		return (true);
	}

	else if (stringVal.length() == 4 && stringVal.compare("inff") == 0)
	{
		desarolloInff();
		return (true);
	}

	else if (stringVal.length() == 4 && stringVal.compare("nanf") == 0)
	{
		desarolloNanf();
		return (true);
	}

	if (stringVal.length() == 4 && stringVal.compare("-inf") == 0)
	{
		desarolloNegInff();
		return (true);
	}

	else if (stringVal.length() == 3 && stringVal.compare("inf") == 0)
	{
		desarolloInff();
		return (true);
	}

	else if (stringVal.length() == 3 && stringVal.compare("nan") == 0)
	{

		std::cout << "caca\n";
		desarolloNanf();
		return (true);
	}

	return (false);
}



void ScalarConverter::convert(const std::string &stringVal)
{


	if (stringVal.length() == 1 && !std::isdigit(stringVal[0]))
	{
		desaroChar(stringVal[0]);
	}
	else
	{

		int i = std::atoi(stringVal.c_str());
		// double d = std::atof(stingVal.c_str());
		
		std::cout << "char  : '" << i << "'\n";
		std::cout << "int   : " << static_cast<int>(i) << "\n"; // static cast
		std::cout << "float : " << static_cast<float>(i) << ".0f\n"; // static cast
		std::cout << "double: " << static_cast<double>(i) << ".0\n"; // static cast
	}
}