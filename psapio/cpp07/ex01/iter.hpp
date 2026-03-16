// - ex01 → iter + función template aplicada a arrays.

#pragma once

#include <iostream>
#include <string>


template <typename T>
void print_array_element(T &array);



template <typename T, typename S, typename F>
void iter(T &array, const S length_arr, F &func);

