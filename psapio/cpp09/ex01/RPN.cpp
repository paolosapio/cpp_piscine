#include "RPN.hpp"
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <cstdlib>

/* ********CONTRUCTORES******** */

Rpn::Rpn() {}

Rpn::Rpn(const Rpn& o) : _contenedor(o._contenedor) {}

Rpn& Rpn::operator=(const Rpn& o)
{
	if (this != &o) _contenedor = o._contenedor;
	return *this;
}

Rpn::~Rpn() {}

int Rpn::getValueStack() const
{
	return (_contenedor.top());
}



/* ********OPERACIONES******** */

void Rpn::moltiplicazione()
{
	int a = _contenedor.top();
			_contenedor.pop();

	int b = _contenedor.top();
			_contenedor.pop();
		
	_contenedor.push(b * a);
}

void Rpn::divisione()
{
	int a = _contenedor.top();
			_contenedor.pop();

	int b = _contenedor.top();
			_contenedor.pop();
		
	_contenedor.push(b / a);
}

void Rpn::somma()
{
	int a = _contenedor.top();
			_contenedor.pop();

	int b = _contenedor.top();
			_contenedor.pop();
		
	_contenedor.push(b + a);
}

void Rpn::sottrazione()
{
	int a = _contenedor.top();
			_contenedor.pop();

	int b = _contenedor.top();
			_contenedor.pop();
		
	_contenedor.push(b - a);
}



/* ********PARSEO******** */

bool Rpn::StringStreaMeador(char *stringValues)
{
	std::istringstream iss(stringValues);
	std::string token;

	while (iss >> token)
	{
		if (token == "*")
			Rpn::moltiplicazione();
			
		else if (token == "/")
			Rpn::divisione();

		else if (token == "+")
			Rpn::somma();

		else if (token == "-")
			Rpn::sottrazione();
		
		else
		{
			char tokenChar = token.c_str()[0];
			if (token.length() == 1 && tokenChar >= '0' && tokenChar <= '9')
			{
				_contenedor.push(std::atoi(token.c_str()));
			}
			else
			{
				std::cout << "valor: " << token << " erroneo\n";
				return (false);
			}
		}
	}
	if (_contenedor.size() != 1)
	{
		std::cout << "No hay operaciones!\n";
		return (false);
	}

	return (true);
}
