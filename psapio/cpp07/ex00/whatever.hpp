// - ex00 → Templates básicos (whatever.hpp, swap, min, max).
#pragma once

#include <iostream>
#include <stdlib.h>

template <typename T>
void swap(T &a, T &b)
{
	T aux;

	aux = a;
	a = b;
	b = aux;
}

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b); 
}

template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b); 
}
