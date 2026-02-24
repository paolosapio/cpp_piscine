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

enum State
{
	S___START, // 0
	S____SIGN, // 1
	S_____INT, // 2
	S_____DOT, // 3
	S____FRAC, // 4
	S_FLOAT_F, // 5
	S___ERROR, // 6
	S___COUNT  // 7
};


enum Token
{
	T__SIGN,
	T_DIGIT,
	T___DOT,
	T_____F,
	T_OTHER,
	T_COUNT
};

#endif