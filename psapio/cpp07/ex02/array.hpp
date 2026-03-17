// - ex02 → Clase template Array<T>.

#pragma once

#include <stdexcept>


template <typename T>
class Array
{
private:
		T*				_array;
		unsigned int	_size;


public:
	Array();

	Array(unsigned int n);

	Array(const Array& other);

	~Array();

	Array& operator=(const Array& other);
	
	T& operator[](unsigned int i);
	
	
	const T& operator[](unsigned int i) const;
	
	unsigned int size() const;
	
};

#include "array.tpp"