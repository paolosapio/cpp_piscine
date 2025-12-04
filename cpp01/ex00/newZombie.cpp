#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie_heap;
	
	//PUNTERO COJE VALOR DEL RESERVA DE ZOMBIE(CON VALOR DE NAME)
	zombie_heap = new Zombie(name);

	// ARRIBA ES COMO EN C: malloc(sizeof(Zombie));
	return (zombie_heap);
}