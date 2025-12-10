/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:28 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 10:32:56 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP 
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include "Contact.hpp"

# define SIZE_BOOK 8

class PhoneBook
{
	private:
		Contact contacts[SIZE_BOOK];
		int page;
		void print_table();
		
		public:
		PhoneBook();
		
		void print_row(int page);
		void add_contact();
		void search_contact();
		void ask_contact_detail();
};

#endif