#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("cucaracha")
{
	std::cout << "ANIMAL CONTRUIDO\n";
}

AAnimal::AAnimal(const std::string name) : _type(name)
{
	std::cout << "ANIMAL CONTRUIDO\n";
}

AAnimal::AAnimal(const AAnimal& other)
{
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "ANIMAL DESTRUIDO\n";

}

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::makeSound() const
{
	std::cout << "ANIMAL DICE: GRUUUUUUGRUUUU GRU gr g\n";
}
