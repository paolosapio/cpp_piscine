#include "Zombie.hpp"

 // contructor:
Zombie::Zombie(std::string str)
{
    this->name = str;
}

// destructor:
Zombie::~Zombie()
{
    std::cout << "DESTRUCTOR: " << this->name << " destruido" << std::endl;
}

// llamada fucion <announce> de la clase:
// <tipo_de_retorno> <Clase>::<nombre_función>(<parámetros>)
void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
