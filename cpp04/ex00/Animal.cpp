#include "Animal.hpp"

Animal::Animal() : _type("cucaracha")
{
	std::cout << "ANIMAL CONTRUIDO\n";
}


Animal::Animal(const std::string name) : _type(name)
{
	std::cout << "ANIMAL CONTRUIDO\n";
}


Animal::Animal(const Animal& other)
{
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	//! if (this != &other) verificar porque esta protecion es necesaria (Davida aviles te lo explica)
		_type = other._type;
	return (*this);
}



Animal::~Animal()
{
	std::cout << "ANIMAL DESTRUIDO\n";

}





std::string Animal::getType()
{
	return (_type);
}




void Animal::makeSound()
{
	std::cout << "ANIMAL DICE: GRUUUUUUGRUUUU GRU gr g\n";
}

