#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* s = new WrongCat();
	Cat cat1;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << cat1.getType() << "\n";

	std::cout << s->getType() << " " << std::endl;
	s->makeSound();
	//will output the WrongAnimal sound!
	//NO estamos utilizando la funcion de Wrong
	//cat porque la de wronganimal no es virtual!

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	delete s;
	return (0);
}