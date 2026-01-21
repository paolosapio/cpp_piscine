#include "Animal.hpp"

Animal::Animal() : _type("cucaracha")
{
	std::cout << "ANIMAL CONSTRUIDO\n";
}


Animal::Animal(const std::string name) : _type(name)
{
	std::cout << "ANIMAL CONSTRUIDO\n";
}


Animal::Animal(const Animal& other)
{
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}



Animal::~Animal()
{
	std::cout << "ANIMAL " << this->_type <<" DESTRUIDO\n";

}





std::string Animal::getType() const
{
	return (this->_type);
}




void Animal::makeSound() const
{
	std::cout << "ANIMAL DICE: GRUUUUUUGRUUUU GRU gr g\n";
}

