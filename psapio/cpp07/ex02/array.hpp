#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class Array
{
private:

public:
	Array();
	Array(unsigned int nArray); //Creates an array of n elements initialized by default.
// • Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn’t affect the other array.

	

}
#endif

// Tip: Try to compile int *a = new int(); then display *a.

// • Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (al locating memory in advance) is forbidden. Your program must never access non allocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that con-
// tains your tests.
