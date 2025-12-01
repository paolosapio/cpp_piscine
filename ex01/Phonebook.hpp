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
		void add_contact();
		void search_contact();
		void ask_contact_detail();
};

#endif