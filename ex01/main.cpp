#include <iostream>
#include "Phonebook.hpp"

int main()
{
	Contact contacto;

	contacto.set_first_name();
	contacto.set_last_name();
	contacto.set_nickname();
	contacto.set_phone_number();
	contacto.set_darkest_secret();

	contacto.print();
	return (0);
}