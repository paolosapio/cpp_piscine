// - ex01 → iter + función template aplicada a arrays.

#pragma once

#include <iostream>

//imprime un elemento
template <typename T>
void print_array_element(T& elementos)
{
    std::cout << elementos << "\n";
}



template <typename T>
void iter(T *array, int length, void (*func)(T &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void iter(T *array, int length, void (*func)( const T &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}
