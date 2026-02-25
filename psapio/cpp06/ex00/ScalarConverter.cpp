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
	std::cout << "float : " << static_cast<float>(c) << "\n"; // static cast
	std::cout << "double: " << static_cast<double>(c) << "\n"; // static cast

}

void desarolloInt(void)
{
	std::cout << "funcion desarolloInt\n";
}

void desarolloFloat(void)
{
	std::cout << "funcion desarolloFloat\n";
}

void desarolloDouble(void)
{
	std::cout << "funcion desarolloDouble\n";
}

void errorMessage()
{
	std::cerr << "Input ERRONEO!\n";
}

void activateFunction(int finalState)
{
	void (*arrayFunction[S___COUNT])(void);

	arrayFunction[S___START] = errorMessage;
	arrayFunction[S____SIGN] = errorMessage;
	arrayFunction[S_____INT] = desarolloInt;
	arrayFunction[S_____DOT] = errorMessage;
	arrayFunction[S_FLOAT_F] = desarolloFloat;
	arrayFunction[S__DOUBLE] = desarolloDouble;
	arrayFunction[S___ERROR] = errorMessage;

	arrayFunction[finalState]();
}

bool preAutomataCheck(const std::string &stringVal)
{
	
	if (stringVal.length() == 1 && !std::isdigit(stringVal[0]))
	{
		desaroChar(stringVal[0]);
		return (true);
	}
	return (false);
}

void ScalarConverter::convert(const std::string &stringVal)
{
	
	(void)stringVal;
	int newState = 0; 
	if (!preAutomataCheck(stringVal))
	{
		for (int i = 0; stringVal[i] && newState != S___ERROR; ++i)
		{
			newState = get_new_state(newState, tokenizer2(stringVal[i]));
		}
		activateFunction(newState);
	}
}
