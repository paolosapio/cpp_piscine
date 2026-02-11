#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm //ABSTRACT (de momento es UTILITARIA mas que abstracta porque tiene cosas publicas)
{
	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
	
	public:
	AForm();
	AForm(std::string name, const int _gradeToSign, const int _gradeToExec);
	AForm(AForm &other);
	virtual ~AForm();
	AForm& operator=(AForm &other);
	
//getterso

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


	class YaFirmadoException : public std::exception // ereda de std::exeption
	{
		private:
		//nada
		
		public:
		const char* what() const throw(); //throw es una promesa que esta funcion no va a lanzar una expecion
	};


	class NoFirmadoException : public std::exception // ereda de std::exeption
	{
		private:
		//nada
		
		public:
		const char* what() const throw(); //throw es una promesa que esta funcion no va a lanzar una expecion
	};



	class caca_exetion_test : public std::exception
	{
		private:
		//nada

		public:
						// const throw() == noexcept; PEROO EN CPP98 NO PODEMOS UTIILZAR NOEXEPT
		const char* what() const throw();
	//	const char* what() noexcept;
	};




	const std::string&	getName() const;
	bool 				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	
	void				beSigned(Bureaucrat& Bureaucrat); // mira solo si se puede firmar
	// void				beExecute(const Bureaucrat & Bureaucrat) const; // mira solo si se puede executar


	virtual void		execute(Bureaucrat const & executor) const = 0; // el hijo tendra quee desarollar su propria funcion execute!
};


std::ostream& operator<<(std::ostream &out, const AForm& right);

#endif