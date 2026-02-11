#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int n_animals = 6;
	Animal *animals[n_animals];

	for (int i = 0; i < n_animals; ++i)
	{
		if (i <= 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;

		animals[i]->makeSound();
	}

	for (int i = 0; i < n_animals; i++)
		delete (animals[i]);
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


//INFO UTILES
/* 
Tienes que borrar cada objeto individualmente:

for (int i = 0; i < 6; ++i)
{
	delete animals[i];
}


Esto funciona solo si el destructor de Animal es virtual
(que en CPP04 ex01 DEBE SERLO).

📌 Regla de oro en C++
Cómo reservas	Cómo liberas
new	delete
new[]	delete[]

Nunca mezclar.

❓ ¿Cuándo se usa new[] entonces?

Ejemplo correcto:

Animal *animals = new Animal[6];
delete[] animals;


⚠️ PERO esto NO sirve para polimorfismo, porque:

Todos serían Animal

No puedes meter Dog y Cat distintos

Por eso en CPP04 SIEMPRE se usa:

Animal* animals[6];


y se borra uno a uno.
 */