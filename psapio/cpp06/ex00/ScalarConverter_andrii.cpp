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





void ScalarConverter::convert(const std::string &stringVal)
{
	double dNum = std::atof(stringVal.c_str()); //devuelve double

	
}