/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:48:14 by psapio            #+#    #+#             */
/*   Updated: 2025/12/13 21:06:26 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie()
{
	static int i = 1;

	std::cout << "ZOMBIE: " << i << " is alive" << std::endl;
	i++;
}



Zombie::~Zombie()
{
	static int i = 1;

	std::cout << "ZOMBIE: " << i << " is DEAD " << std::endl;
	i++;
}



void Zombie::setZombieName(std::string name)
{
	this->_name = name;
}



void Zombie::announce()
{
	std::cout << "SOY ZOMBIE: " << this->_name << std::endl;
}
