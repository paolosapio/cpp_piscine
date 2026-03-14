// - ex01 → iter + función template aplicada a arrays.

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void print_array_element(T &array)
{
	std::cout << array << "\n";
}

template <typename T>
void iter(T *array, const int length_arr, void (*func)(T &))
{
	for (int i = 0; i < length_arr; i++)
	{
		func(array[i]);
	}
}

#endif