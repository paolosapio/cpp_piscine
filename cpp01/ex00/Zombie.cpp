#include "Zombie.hpp"

 // contructor:
Zombie::Zombie(std::string name)
{
    this->name = name;
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

//los metodos de las clases son las funciones internas al cuale se lega a llamar el nombre del objeto?