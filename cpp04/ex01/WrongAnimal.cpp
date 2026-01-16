#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("cucaracha")
{
	std::cout << "WRONG ANIMAL CONTRUIDO\n";
}


WrongAnimal::WrongAnimal(const std::string name) : _type(name)
{
	std::cout << "WRONG ANIMAL CONTRUIDO\n";
}


WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}



WrongAnimal::~WrongAnimal()
{
	std::cout << "WRONG ANIMAL DESTRUIDO\n";

}





std::string WrongAnimal::getType() const
{
	return (_type);
}




void WrongAnimal::makeSound() const
{
	std::cout << "WRONG ANIMAL DICE: GRUUUUUUGRUUUU GRU gr g\n";
}

