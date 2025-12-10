/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:29 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 12:36:39 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

 // contructor:
Zombie::Zombie(std::string name)
{
    this->_name = name;
}















// destructor:
Zombie::~Zombie()
{
    std::cout << "DESTRUCTOR: " << this->_name << " destruido" << std::endl;
}












// llamada fucion <announce> de la clase:
// <tipo_de_retorno> <Clase>::<nombre_función>(<parámetros>)
void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//los metodos de las clases son las funciones internas al cuale se lega a llamar el nombre del objeto?