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



/*
static bool isChar(const std::string &s);
static bool isInt(const std::string &s);
static bool isFloat(const std::string &s);
static bool isDouble(const std::string &s);
static bool isPseudoLiteral(const std::string &s);

¿Es un char?
¿Es un int?
¿Es un float?
¿Es un double?
¿Es un pseudo‑literal (nan, +inf, -inf, nanf, etc.)?

Si es int → int n = std::stoi(stringVal);
Si es float → float f = std::stof(stringVal);
Si es double → double d = std::stod(stringVal);
Si es char → char c = stringVal[0];
*/

void ScalarConverter::convert(const std::string &stingVal)
{
}
