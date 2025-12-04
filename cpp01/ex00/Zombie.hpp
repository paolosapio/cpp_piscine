#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

	class Zombie
	{
		private:
			std::string name;

		public: // métodos de instancia, y announce() usa this->name para imprimir
			Zombie(std::string name); // Constructor
			~Zombie();                // Destructor
			void announce(); //imprime el "nombre": BraiiiiiiinnnzzzZ...
	};

	Zombie* newZombie(std::string name);
	void randomChump(std::string name);

#endif

/* 

Dentro de la clase pones:

La variable privada name

El constructor

El destructor ~

Cualquier función miembro como announce()

*/

