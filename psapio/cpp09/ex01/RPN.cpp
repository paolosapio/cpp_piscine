#include "RPN.hpp"


/* ********CONTRUCTORES******** */

Rpn::Rpn() {}

Rpn::Rpn(const Rpn& o) : _contenedor(o._contenedor) {}

Rpn& Rpn::operator=(const Rpn& o)
{
	if (this != &o) _contenedor = o._contenedor;
	return *this;
}

Rpn::~Rpn()
{}


/* ********OPERACIONES******** */


void Rpn::moltiplicazione()
{

}

void Rpn::divisione()
{

}

void Rpn::somma()
{

}

void Rpn::sottrazione()
{

}
