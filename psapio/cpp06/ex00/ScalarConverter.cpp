#include "ScalarConverter.hpp"
#include <cstdlib>

#include <limits.h>
#include <cfloat>
#include <math.h>

#include <cstdlib>      // strtof
#include <cmath>        // isnan, isinf
#include <limits>       // numeric_limits
#include <iomanip>      // setprecision, fixed

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

int	get_new_state(int current_state, int token)
{
	int matrix[S___COUNT][T_COUNT] =
	{
		//***SIGN   |   DIGIT  |  DOT     |     F    |    OTHER   |    ESTADOS 
		{ S____SIGN, S_____INT, S_____DOT, S___ERROR, S___ERROR }, // S___START - 0
		{ S___ERROR, S_____INT, S_____DOT, S___ERROR, S___ERROR }, // S____SIGN - 1
		{ S___ERROR, S_____INT, S__DOUBLE, S_FLOAT_F, S___ERROR }, // S_____INT - 2
		{ S___ERROR, S__DOUBLE, S___ERROR, S___ERROR, S___ERROR }, // S_____DOT - 3
		{ S___ERROR, S__DOUBLE, S___ERROR, S_FLOAT_F, S___ERROR }, // S__DOUBLE - 4
		{ S___ERROR, S___ERROR, S___ERROR, S___ERROR, S___ERROR }, // S_FLOAT_F - 5
		{ S___ERROR, S___ERROR, S___ERROR, S___ERROR, S___ERROR }  // S___ERROR - 6
	};

	return (matrix[current_state][token]); //return el token que va a ser el nuevo estado
}

int tokenizer2(char c) //TOKEN
{
	if (c == '+' || c == '-')
		return (T__SIGN);

	if (std::isdigit(c))
		return (T_DIGIT);

	if (c == '.')
		return (T___DOT);

	if (c == 'f' || c == 'F')
		return (T_____F);

	return (T_OTHER);
}

void desaroChar(char c)
{
	std::cout << "char  : '" << c << "'\n";
	std::cout << "int   : " << static_cast<int>(c) << "\n"; // static cast
	std::cout << "float : " << static_cast<float>(c) << ".0f\n"; // static cast
	std::cout << "double: " << static_cast<double>(c) << ".0\n"; // static cast
}


void desarolloInt(const std::string &number)
{
	//Ya he validado que es un int:  lógica previa,
	// aquí podemos asumir que strtol funciona bien.

	long tmp = std::strtol(number.c_str(), NULL, 10);
// convierte el strng pero comproba varias cosas con el puntero mandato tambien 
// el ultimo valor es la base en este caso decimal
// Por seguridad, comprobamos rango de int
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
	{
		std::cout << "char  : impossible\n";
		std::cout << "int   : impossible\n";
		std::cout << "float : impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	int n = static_cast<int>(tmp);

	// === CHAR ===
	std::cout << "char  : ";
	if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
	{
		std::cout << "impossible\n";
	}
	else if (static_cast<char>(n) < 32 || static_cast<char>(n) > 126)
	{
		std::cout << "Non displayable\n";
	}
	else
	{
		std::cout << "'" << static_cast<char>(n) << "'\n";
	}

	// === INT ===
	std::cout << "int   : " << n << "\n";

	// === FLOAT ===
	std::cout << "float : " << std::fixed << std::setprecision(1)
			  << static_cast<float>(n) << "f\n";

	// === DOUBLE ===
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>(n) << "\n";
}


int lenFromPoint(const std::string &number)
{
	int i;
	int j;

	for (i = 0; number[i] != '.'; ++i)
	{}

	for (j = 0; number[j + i] != '\0' && number[j + i] != 'f' && number[j + i] != 'F'; ++j)
	{}

	--j;
	return (j);
}

// https://www.h-schmidt.net/FloatConverter/IEEE754.html
void desarolloFloat(const std::string &number)
{
	float n = std::strtof(number.c_str(), NULL);

	// === CHAR ===
	std::cout << "char  : ";
	if (std::isnan(n) ||
		n < std::numeric_limits<char>::min() ||
		n > std::numeric_limits<char>::max())
	{
		std::cout << "impossible\n";
	}
	else if (static_cast<char>(n) < 32 || static_cast<char>(n) > 126)
	{
		std::cout << "Non displayable\n";
	}
	else
	{
		std::cout << "'" << static_cast<char>(n) << "'\n";
	}

	// === INT ===
	std::cout << "int   : ";
	if (std::isnan(n) ||
		n < std::numeric_limits<int>::min() ||
		n > std::numeric_limits<int>::max())
	{
		std::cout << "impossible\n";
	}
	else
	{
		std::cout << static_cast<int>(n) << "\n";
	}

	// === FLOAT ===
	std::cout << "float : ";
	if (std::isnan(n))
	{
		std::cout << "nanf\n";
	}
	else if (std::isinf(n))
	{
		std::cout << (n > 0 ? "+inff\n" : "-inff\n");
	}
	else
	{
		if (n == static_cast<int>(n))
			std::cout << std::fixed << std::setprecision(1) << n << "f\n";
		else
			std::cout << n << "f\n";
	}

	// === DOUBLE ===
	double d = static_cast<double>(n);
	std::cout << "double: ";
	if (std::isnan(d))
	{
		std::cout << "nan\n";
	}
	else if (std::isinf(d))
	{
		std::cout << (d > 0 ? "+inf\n" : "-inf\n");
	}
	else
	{
		if (d == static_cast<int>(d))
			std::cout << std::fixed << std::setprecision(1) << d << "\n";
		else
			std::cout << d << "\n";
	}
}

void desarolloDouble(const std::string &number)
{
	double n;
	int len = lenFromPoint(number);
	if (len == 0)
		++len;
	std::cout << std::fixed << std::setprecision(len);

	n = std::atof(number.c_str());

	if (n < 32 || n > 126)
		std::cout << "char  : Non displayable\n";
	else
		std::cout << "char  : '" << static_cast<char>(n) << "'\n";

	std::cout << "int   : " << static_cast<int>(n) << "\n"; // static cast
	std::cout << "float : " << static_cast<float>(n) << "f\n"; // static cast
	std::cout << "DOUBLE: " << n << "\n"; // static cast
}

void errorMessage(const std::string &stringVal)
{
	(void)stringVal;
	std::cerr << "Input ERRONEO!\n";
}



// -----------------ACTIVADOR DE FNCIONES--------------------------//

void activateFunction(int finalState, const std::string &stringVal)
{
	void (*arrayFunction[S___COUNT])(const std::string &stringVal);

	arrayFunction[S___START] = errorMessage;
	arrayFunction[S____SIGN] = errorMessage;
	arrayFunction[S_____INT] = desarolloInt;
	arrayFunction[S_____DOT] = errorMessage;
	arrayFunction[S_FLOAT_F] = desarolloFloat;
	arrayFunction[S__DOUBLE] = desarolloDouble;
	arrayFunction[S___ERROR] = errorMessage;

	arrayFunction[finalState](stringVal);
}

// -----------------------------------------------------------------//



void desarolloInff(const std::string &number)
{
	std::cout << "desarolloInff:\n";
	desarolloFloat(number);



	// float n;

	// n = std::atof(number.c_str());
	// std::cout << "char   : impossible\n";
	// std::cout << "int    : impossible\n";
	// std::cout << "float  : " << static_cast<float>(n) << "f\n"; // static cast
	// std::cout << "double : " << static_cast<double>(n) << "\n"; // static cast
}

void desarolloInf(const std::string &number)
{
	std::cout << "desarolloInf:\n";

	float n;
	
	n = std::atof(number.c_str());
	
	std::cout << "char   : impossible\n";
	std::cout << "int    : impossible\n";
	std::cout << "float  : " << static_cast<float>(n) << "f\n"; // static cast
	std::cout << "double : " << static_cast<double>(n) << "\n"; // static cast
}

void desarolloNegInff(const std::string &number)
{
	std::cout << "desarolloNegInff:\n";

	float n;

	n = std::atof(number.c_str());
	std::cout << "char   : impossible\n";
	std::cout << "int    : impossible\n";
	std::cout << "float  : " << static_cast<float>(n) << "f\n"; // static cast
	std::cout << "double : " << static_cast<double>(n) << "\n"; // static cast
}

void desarolloNegInf(const std::string &number)
{
	std::cout << "desarolloNegInf:\n";
	float n;

	n = std::atof(number.c_str());

	std::cout << "char   : impossible\n";
	std::cout << "int    : impossible\n";
	std::cout << "float  : " << static_cast<float>(n) << "f\n"; // static cast
	std::cout << "double : " << static_cast<double>(n) << "\n"; // static cast
}

/* void desarolloNanf(const std::string &number)
{
	std::cout << "desarolloNanf:\n";
	float n;

	n = std::atof(number.c_str());
	
	std::cout << "char   : impossible\n";
	std::cout << "int    : impossible\n";
	
	std::cout << "float  : " << static_cast<float>(n) << "f\n"; // static cast

	std::cout << "double : " << static_cast<double>(n) << "\n"; // static cast
} */

/* void desarolloNan(const std::string &number)
{
	std::cout << "desarolloNan:\n";
	float n;

	n = std::atof(number.c_str());
	
	
	std::cout << "char   : impossible\n";
	std::cout << "int    : impossible\n";
	std::cout << "float  : " << static_cast<float>(n) << "f\n"; // static cast
	std::cout << "double : " << static_cast<double>(n) << "\n"; // static cast
} */


bool CheckPseudoChar(const std::string &stringVal)
{
	float f = std::atof(stringVal.c_str());

	if (f != f)
	{
		desarolloFloat(stringVal);
	}

	if (f > FLT_MAX)
	{
		std::cout << "Number is +inf" << std::endl;
		desarolloFloat(stringVal);
	}

	if (f < FLT_MIN)
	{
		std::cout << "Number is -inf" << std::endl;
	}

	if (stringVal.length() == 1 && !std::isdigit(stringVal[0]))
	{
		desaroChar(stringVal[0]);
		return (true);
	}
	return (false);
}


/* bool CheckPseudoChar(const std::string &stringVal)
{
	if (stringVal.length() == 5 && stringVal.compare("-inff") == 0)
	{
		desarolloNegInff(stringVal);
		return (true);
	}

	else if (stringVal.length() == 5 && stringVal.compare("+inff") == 0)
	{
		desarolloInff(stringVal);
		return (true);
	}
	
	else if (stringVal.length() == 4 && stringVal.compare("nanf") == 0)
	{
		desarolloFloat(stringVal);

		// desarolloNanf(stringVal);
		return (true);
	}
	
	else if (stringVal.length() == 3 && stringVal.compare("nan") == 0)
	{
		desarolloFloat(stringVal);
		// desarolloNanf(stringVal);
		return (true);
	}

	if (stringVal.length() == 4 && stringVal.compare("-inf") == 0)
	{
		desarolloNegInff(stringVal);
		return (true);
	}

	else if (stringVal.length() == 4 && stringVal.compare("+inf") == 0)
	{
		desarolloInff(stringVal);
		return (true);
	}
	

	if (stringVal.length() == 1 && !std::isdigit(stringVal[0]))
	{
		desaroChar(stringVal[0]);
		return (true);
	}
	return (false);
} */

void ScalarConverter::convert(const std::string &stringVal)
{
	int newState = 0; 
	if (CheckPseudoChar(stringVal) == false)
	{
		for (int i = 0; stringVal[i] && newState != S___ERROR; ++i)
		{
			newState = get_new_state(newState, tokenizer2(stringVal[i]));
		}
		activateFunction(newState, stringVal);
	}
}
