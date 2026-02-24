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
¿Es un char?
¿Es un int?
¿Es un float?
¿Es un double?
¿Es un pseudo‑literal (nan, +inf, -inf, nanf)?

Si es int		→	int		n = std::stoi(stringVal);
Si es float		→	float	f = std::stof(stringVal);
Si es double	→	double	d = std::stod(stringVal);
Si es char		→	char	c = stringVal[0];
*/

bool intConversion(const std::string &stringVal);


void ScalarConverter::convert(const std::string &stringVal)
{
	char *str_states[] =
	{
		"0 - estado inicial",
		"2 - estado char - ACCEPT_STATE",
		"1 - estado int - ACCEPT_STATE",
		"2 - estado float - ACCEPT_STATE",
		"3 - estado double - ACCEPT_STATE",
		"4 - estado pseudo‑literal - ACCEPT_STATE",
		"5 - estado err - ERROR__STATE",
		NULL
	};
}


// antes verificar si es pseudo-literal o un caracter
//saber si es un int un float un double



//caso: +23.0f
//caso: .7
//caso: 7.
//caso: "a"

int	get_new_state(int current_state, int token)
{
	float test = 7.f;

	int matrix[S___COUNT][T_COUNT] =
	{
		//***SIGN   |   DIGIT  |  DOT     |     F    |    OTHER   |    ESTADOS 
		{ S____SIGN, S_____INT, S_____DOT, S___ERROR, S___ERROR }, // S___START - 0
		{ S___ERROR, S_____INT, S_____DOT, S___ERROR, S___ERROR }, // S____SIGN - 1
		{ S___ERROR, S_____INT, S_____DOT, S_FLOAT_F, S___ERROR }, // S_____INT - 2
		{ S___ERROR, S____FRAC, S___ERROR, S___ERROR, S___ERROR }, // S_____DOT - 3
		{ S___ERROR, S____FRAC, S___ERROR, S_FLOAT_F, S___ERROR }, // S____FRAC - 4
		{ S___ERROR, S___ERROR, S___ERROR, S___ERROR, S___ERROR }, // S_FLOAT_F - 5
		{ S___ERROR, S___ERROR, S___ERROR, S___ERROR, S___ERROR }  // S___ERROR - 6
	};

	return (matrix[current_state][token]); //return el token que va a ser el nuevo estado
}