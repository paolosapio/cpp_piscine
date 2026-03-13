#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <stdlib.h>


template <typename T>
void swaPaolo(T &a, T &b)
{
	T aux;

	aux = a;
	a = b;
	b = aux;
}

template <typename T>
T maxaolo(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b); 
}

template <typename T>
T minaolo(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b); 
}


template <typename Q, typename M>
class Hola
{
	public:
	Q mafio;
	Q dana;
	M bebe;
	
	private:
};

template <typename T, typename S>
class Patata
{
public:
	Hola <T, S> h;
};

class algo
{
public:
	void hola(const std::string& mensaje)
	{
		std::cout << "algo: " << mensaje << std::endl;
	}
};

class something
{
public:
	void hola(const std::string& mensaje)
	{
		std::cout << "something: " << mensaje << std::endl;
	}
};

class general
{
public:

	~general()
	{
		free(this->instance);
	}
	
	template <typename T>
	void hola(const std::string& mensaje)
	{
		this->instance = reinterpret_cast<void*>(new T());
		reinterpret_cast<T*>(this->instance)->hola(mensaje);
	}

private:
	void* instance;

};

struct base
{
	virtual ~base()
	{}

	void b(const std::string str)
	{
		std::cout << str << std::endl;
	}
};

struct father : public base
{
	father() : fa("father")
	{}

	void f()
	{
		this->b(fa);
	}

private:
	std::string fa;

};

struct mother : public base
{
	mother() : mo("mother")
	{}

	void m()
	{
		this->b(*(&mo + 1));
	}

private:
	std::string mo;
};

struct child : public father
{

	child() : ch("child")
	{}

	void c()
	{
		this->b(ch);
	}

private:
	std::string ch;

};

#endif

/*

base - none
father - fa
child - fa - ch

mother - mo

*/


// LOS CASTEOS E CPP VAN SOBRE PUNTEROS
/* reintepret cast (mas parecido a C)

static cast (se interpreta la memoria tal cual con otro tipo)

dynamic cast () */