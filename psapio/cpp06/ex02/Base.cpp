#include "Base.hpp"

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base()
{}


/* se generra de manera casual la isntancia de un objeto a, b, c */
Base *generate(void)
{
	Base *returnClass;
	std::srand(std::time(NULL));
	int rand_of_0_1_2 = std::rand() % 3;

	if (rand_of_0_1_2 == 0)
		returnClass = new(A);

	if (rand_of_0_1_2 == 1)
		returnClass = new(B);
	
	if (rand_of_0_1_2 == 2)
		returnClass = new(C);
	
	return (returnClass);
}

/* se se identoifica el puntero a objeto a, b, c */
void identify(Base* p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "object pointed to by p: A\n";
		return ;
	}

	b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "object pointed to by p: B\n";
		return ;
	}

	c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "object pointed to by p: C\n";
		return ;
	}
}

/* se se identoifica la referencia a objeto a, b, c */
void identify(Base& p)
{

	A a_new_ref;
	B b_new_ref;
	C c_new_ref;

	try
	{
		a_new_ref = dynamic_cast<A&>(p);
		std::cout << "objeto encontrado por referencia: A";
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		b_new_ref = dynamic_cast<B&>(p);
		std::cout << "objeto encontrado por referencia: B";
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		c_new_ref = dynamic_cast<C&>(p);
		std::cout << "objeto encontrado por referencia: C";
		return ;
	}
	catch(const std::exception& e)
	{}
}