#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>


template <typename T>
void swaPaolo(T &a, T &b)
{
	T aux;

	aux = a;
	a = b;
	b = aux;
}

template <typename T>
T maxaolo(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b); 
}

template <typename T>
T minaolo(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b); 
}


template <typename T, typename S>
class Hola
{
	public:
	T mafio;
	T dana;
	S bebe;
	
	private:
};

template <typename T, typename S>
class Patata
{
public:
	Hola <T, S> h;
};

#endif