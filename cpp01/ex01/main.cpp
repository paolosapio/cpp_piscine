/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:48:07 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 14:48:08 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie;

	int N = 10;
	int i = 0;

	zombie = zombieHorde(N, "luca");
	while(i <  N)
	{
		zombie[i].announce();
		i++;
	}
	delete[] zombie;
	return (0);
}