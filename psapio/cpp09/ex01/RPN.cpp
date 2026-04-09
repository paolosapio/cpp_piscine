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



/* ********CHECK STACK******** */

void Rpn::checkStack()
{
	if (_contenedor.size() < 2)
	{
		std::cerr << "he! tiene que poner algun numerito mas?!\n";
		exit(1);
	}
}

/* ********OPERACIONES******** */

void Rpn::moltiplicazione()
{
	checkStack();

	int a = _contenedor.top();
			_contenedor.pop();

	int b = _contenedor.top();
			_contenedor.pop();
		
	_contenedor.push(b * a);
}

bool Rpn::divisione()
{
	checkStack();

	int a = _contenedor.top();
	if (a == 0)
		return (false);
	else
		_contenedor.pop();

	int b = _contenedor.top();
			_contenedor.pop();
	
	_contenedor.push(b / a);
	return (true);
}

void Rpn::somma()
{
	checkStack();
	int a = _contenedor.top();
			_contenedor.pop();

	int b = _contenedor.top();
			_contenedor.pop();
		
	_contenedor.push(b + a);
}

void Rpn::sottrazione()
{
	checkStack();
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
			moltiplicazione();
			
		else if (token == "/")
		{
			if(divisione() == false)
			{

				std::cout << "Division entre <0> IMPOSIBLE\n";
				return (false);
			}
		}

		else if (token == "+")
			somma();

		else if (token == "-")
			sottrazione();
		
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
