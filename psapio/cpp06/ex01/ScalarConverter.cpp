#include "ScalarConverter.hpp"
#include <cstdlib>

#include <limits.h>
#include <cfloat>
#include <math.h>

#include <cstdlib>      // strtof
#include <cmath>        // isnan, isinf
#include <limits>       // numeric_limits
#include <iomanip>      // setprecision, fixed

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return(*this);
}

Serializer::~Serializer()
{
}


