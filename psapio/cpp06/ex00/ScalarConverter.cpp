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



/********************************************************************** */
/********************************************************************** */
/********************* DESAROLLO FUNCIONES NUMEROS ******************** */
/********************************************************************** */
/********************************************************************** */

void desaroChar(char c)
{
	// std::cout << "DESDE CHAR:\n";

	std::cout << "CHAR  : '" << c << "'\n";
	std::cout << "int   : " << static_cast<int>(c) << "\n"; // static cast
	std::cout << "float : " << static_cast<float>(c) << ".0f\n"; // static cast
	std::cout << "double: " << static_cast<double>(c) << ".0\n"; // static cast
}


void desarolloInt(const std::string &number)
{
	// std::cout << "DESDE INT:\n";
	//Ya he validado que es un int:  lógica previa,
	// aquí podemos asumir que strtol funciona bien.

	char *end_str = NULL;
	long tmp = std::strtol(number.c_str(), &end_str, 10);
// convierte el strng pero comproba varias cosas con el puntero mandato tambien 
// el ultimo valor es la base en este caso decimal
// Por seguridad, comprobamos rango de int

	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
	{
		// std::cout << "ALERTA: OVERFLOW O UNDERFLOW \n";

		std::cout << "char  : impossible\n";
		std::cout << "INT   : impossible\n";
		std::cout << "float : impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	int n = static_cast<int>(tmp);

	// === CHAR ===
	std::cout << "char  : ";
	if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
	{
		// std::cout << "ALERTA: OVERFLOW O UNDERFLOW \n";
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
	std::cout << "INT   : " << n << "\n";

	// === FLOAT ===
	std::cout << "float : " << std::fixed << std::setprecision(1)
			  << static_cast<float>(n) << "f\n";

	// === DOUBLE ===
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>(n) << "\n";
}



/* 
int lenFromPoint(const std::string &number)
{
	int i;
	int j;
	
	for (i = 0; number[i] != '\0' && number[i] != '.'; ++i)
	{}
	if (number[i] == '\0')
		return (1);


	for (j = 0; number[j + i] != '\0' && number[j + i] != 'f' && number[j + i] != 'F'; ++j)
	{}

	--j;
	return (j);
}
 */




int lenFromPoint(const std::string &number)
{
	size_t dot = number.find('.');
	if (dot == std::string::npos)
		return 1;



	if ((number[dot + 1] == '\0') || number[dot + 1] == 'f' || number[dot + 1] == 'F')
		return (1);

	
	size_t end = number.find_first_of("fF", dot);
	if (end == std::string::npos)
		end = number.size();

	return end - dot - 1;
}


// https://www.h-schmidt.net/FloatConverter/IEEE754.html
void desarolloFloat(const std::string &number)
{
	// std::cout << "DESDE FLOAT:\n";

	float n = std::strtof(number.c_str(), NULL);

	// === CHAR ===
	std::cout << "char  : ";
	if (std::isnan(n) ||
		static_cast<int>(n) < std::numeric_limits<char>::min() ||
		static_cast<int>(n) > std::numeric_limits<char>::max() )
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
	std::cout << "FLOAT : ";
	
	if (std::isnan(n))
	{
		std::cout << "nanf\n";
	}
	else if (std::isinf(n))
	{
		std::cout << (n > 0 ? "+inff\n" : "-inff\n");
	}

	else
		std::cout << std::fixed << std::setprecision(lenFromPoint(number)) << n << "f\n";

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
		std::cout << std::fixed << std::setprecision(lenFromPoint(number)) << d << "\n";
	}
}




void desarolloDouble(const std::string &number)
{
	// std::cout << "DESDE DOUBLE:\n";

	double d = std::strtod(number.c_str(), NULL);

	// === CHAR ===
	std::cout << "char  : ";
	if (std::isnan(d) ||
		static_cast<int>(d) < std::numeric_limits<char>::min() ||
		static_cast<int>(d) > std::numeric_limits<char>::max() )
	{
		std::cout << "impossible\n";
	}
	else if (static_cast<char>(d) < 32 || static_cast<char>(d) > 126)
	{
		std::cout << "Non displayable\n";
	}
	else
	{
		std::cout << "'" << static_cast<char>(d) << "'\n";
	}

	// === INT ===
	std::cout << "int   : ";
	if (std::isnan(d) ||
		d < std::numeric_limits<int>::min() ||
		d > std::numeric_limits<int>::max())
	{
		std::cout << "impossible\n";
	}
	else
	{
		std::cout << static_cast<int>(d) << "\n";
	}

	// === FLOAT ===
	float f = static_cast<float>(d);
	std::cout << "float : ";
	
	if (std::isnan(f))
	{
		std::cout << "nanf\n";
	}
	else if (std::isinf(f))
	{
		std::cout << (f > 0 ? "+inff\n" : "-inff\n");
	}

	else
		std::cout << std::fixed << std::setprecision(lenFromPoint(number)) << f << "f\n";

	// === DOUBLE ===
	std::cout << "DOUBLE: ";

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
		std::cout << std::fixed << std::setprecision(lenFromPoint(number)) << d << "\n";
	}
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

bool CheckPseudoChar(const std::string &stringVal)
{
	// SI ES FLOAT
	if (stringVal.length() == 5 && stringVal.compare("-inff") == 0)
	{
		desarolloFloat(stringVal);
		return (true);
	}

	else if (stringVal.length() == 5 && stringVal.compare("+inff") == 0)
	{
		desarolloFloat(stringVal);
		return (true);
	}
	
	else if (stringVal.length() == 4 && stringVal.compare("nanf") == 0)
	{
		desarolloFloat(stringVal);
		return (true);
	}
	// SI ES DOUBLE
	else if (stringVal.length() == 3 && stringVal.compare("nan") == 0)
	{
		desarolloDouble(stringVal);
		return (true);
	}

	if (stringVal.length() == 4 && stringVal.compare("-inf") == 0)
	{
		desarolloDouble(stringVal);
		return (true);
	}

	else if (stringVal.length() == 4 && stringVal.compare("+inf") == 0)
	{
		desarolloDouble(stringVal);
		return (true);
	}
	
	// SI ES CHAR
	if (stringVal.length() == 1 && !std::isdigit(stringVal[0]))
	{
		desaroChar(stringVal[0]);
		return (true);
	}
	return (false);
}

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
