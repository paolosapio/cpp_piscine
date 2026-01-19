#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[6];

	for (int i = 0; i < 6; ++i)
	{
		if (i <= 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
		animals[i]->makeSound();
	}
	delete[] *animals;
	// delete animals[1];
	// delete animals[2];
	// delete animals[3];
	// delete animals[4];
	// delete animals[5];
	return (0);
}

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }