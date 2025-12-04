#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdlib>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

		void set_first_name();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();

	public:
		void create();
		void print_row(int page);
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_darkest_secret();

		void print();
};

#endif
