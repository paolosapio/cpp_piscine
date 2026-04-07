
#pragma once

#include <stack>
#include <string>

class Rpn
{
private:
	std::stack<int> _contenedor;

	void moltiplicazione();
	void divisione();
	void somma();
	void sottrazione();

public:
	Rpn();
	Rpn(const Rpn& other);
	Rpn& operator=(const Rpn& other);
	~Rpn();
};

/* 
El algoritmo RPN

El algoritmo que utilizan las calculadoras RPN es relativamente simple:

	Si hay elementos en la bandeja de entrada:
		Leer el primer elemento de la bandeja de entrada.
		Si el elemento es un operando.
			Poner el operando en la pila.
		Si no, el elemento es una función (los operadores, como "+", no son más que funciones que toman dos argumentos).
			Se sabe que la función x toma n argumentos.
			Si hay menos de n argumentos en la pila
				(Error) El usuario no ha introducido suficientes argumentos en la expresión.
			Si no, tomar los últimos n operandos de la pila.
			Evaluar la función con respecto a los operandos.
			Introducir el resultado (si lo hubiere) en la pila.
	Si hay un solo elemento en la pila:
		El valor de ese elemento es el resultado del cálculo.
	Si hay más de un elemento en la pila:
		(Error) El usuario ha introducido demasiados elementos.

*/