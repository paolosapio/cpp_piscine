#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

template <typename T>
void easyfind(T container, int toBeFound);

class ValueNotFound : public std::exception
{
	virtual const char *what() const throw();
};


#include "easyfind.tpp"


/* 
//function has to find the first occurrence of the second parameter in the first parameter
template <typename T>
void easyfind(T container_of_integers, int compare)
{
	try 
	{
		T::iterator<int> x  = container_of_integers.begin();
		T::iterator<int> xx  = container_of_integers.end();
		T::iterator<int> result = std::find(x, xx, compare);
	}
	catch
	{
		
	}



}


class occurrence_is_NOT_found : public std::exception
{
private:

public:
	virtual const char *what() const throw()
	{
		return ("Occurrence is NOT found");
	}
};
 */


//---------
//DEMO
//---------