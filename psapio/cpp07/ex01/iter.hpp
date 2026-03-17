// - ex01 → iter + función template aplicada a arrays.

#pragma once

#include <iostream>

// imprime un elemento por const referencia
template <typename T>
void print_array_element(const T &elementos)
{
    std::cout << elementos << "\n";
}

template <typename T>
void iter(T *array, int length, void (*func)(T const &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}