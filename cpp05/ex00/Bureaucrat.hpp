#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/*
NO OLVIDAR: Orthodox Canonical AForm
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

#include <iostream>
// #include <string>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &other);
	Bureaucrat& operator=(Bureaucrat &other);

	~Bureaucrat();

	// exeption class:
	// el primer const es referido al valor devuelto;
	// el conts del final implica que ninguna variable del objeto es monificable!
	class GradeTooLowException : public std::exception // ereda de std::exeption
	{
		private:
		//nada
		
		public:
		const char* what() const throw(); //throw es una promesa que esta funcion no va a lanzar una expecion
	};


	class GradeTooHighException : public std::exception // ereda de std::exeption
	{
		private:
		//nada
		
		public:
		const char* what() const throw(); //throw es una promesa que esta funcion no va a lanzar una expecion
	};

	const std::string& getName() const;
	int& getGrade();

	void increment();
	void decrement();
};

#endif