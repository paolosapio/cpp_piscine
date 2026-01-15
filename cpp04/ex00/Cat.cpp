#include "Cat.hpp"

Cat::Cat() : Animal("CAT")
{
	std::cout << "CAT CONTRUIDO\n";
}


Cat::Cat(const std::string name) : Animal(name)
{
	std::cout << "CAT CONTRUIDO\n";
}


Cat::Cat(const Cat& other)
{
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	//! if (this != &other) verificar porque esta protecion es necesaria (Davida aviles te lo explica)
		_type = other._type;
	return (*this);
}



Cat::~Cat()
{
	std::cout << "CAT DESTRUIDO\n";

}





std::string Cat::getType()
{
	return (_type);
}




void Cat::makeSound()
{
	std::cout << "CAT DICE: MIAOOOO\n";
}

