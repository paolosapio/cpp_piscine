/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:48:11 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 14:48:12 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(); //constructor
		~Zombie();//destructor

		void announce(); //imprime el "nombre": BraiiiiiiinnnzzzZ...
		void setZombieName(std::string name);
	};

Zombie* zombieHorde(int N, std::string name);

#endif