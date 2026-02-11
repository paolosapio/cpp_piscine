/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:48:09 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 14:48:10 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombies;

	zombies = new Zombie[N];

	int i = 0;
	while(i < N)
	{
		zombies[i].setZombieName(name);
		i++;
	}
	return (zombies);
}