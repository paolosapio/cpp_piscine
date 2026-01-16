#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[6];
	for(int i = -1; i <= 6; ++i)
	{
		if (i <= 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
		}
	delete[] animals;
}