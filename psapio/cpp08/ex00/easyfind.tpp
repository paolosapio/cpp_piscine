#include "easyfind.hpp"

template <typename T>
void easyfind(T container, int toBeFound)
{
	typename T::iterator iterador;
	iterador = std::find(container.begin(), container.end(), toBeFound);
	if (iterador == container.end())
		throw ValueNotFound();
	std::cout << "Found the value> " << toBeFound << " in the position > " << std::distance(container.begin(), iterador) << std::endl;
}

const char *ValueNotFound::what() const throw()
{
	return ("[Exception] The value was not found in the container");
}