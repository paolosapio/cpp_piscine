/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:35 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 12:33:36 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie_heap;
	
	//PUNTERO COJE VALOR DEL RESERVA DE ZOMBIE(CON VALOR DE NAME)
	zombie_heap = new Zombie(name);

	// ARRIBA ES COMO EN C: malloc(sizeof(Zombie));
	return (zombie_heap);
}