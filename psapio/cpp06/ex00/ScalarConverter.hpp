// input    "string"
// output   char int float double pseudo-literals

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <sstream>
#include <iostream>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	static void convert(const std::string &stingVal);
};

#endif