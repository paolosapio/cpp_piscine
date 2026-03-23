#include <string>
#include <iostream>

#include <unistd.h>

class Test
{
public:
	std::string p = "...";

	Test()
		: str("hola")
	{

	}

	~Test()
	{

	}

	void doAnything()
	{
		std::cout << "this -> " << this << std::endl;
		std::cout << this->str << std::endl;
	}

//private:
	std::string str;

};

struct Test1
{
	std::string str = "adios";
};

typedef void (*fn)(Test*);

// t {"...\n", "hola\n"}
// a {"adios\n"}
//


// 00
// 01
// 02


// fe {"hola"}
// ff {...}
// fd {"adios"}

//using funct = void (Test*);

int main()
{
	static char st;
	Test t;  //declaracion de clase
	Test1 z;  //declaracion de clase
	Test1 a;

	char *mem = (char*)malloc(1);

	printf("mem -> %p\n", mem);
	printf("st -> %p\n", &st);

	mem[500000] = 'j';

	fn func;  //declaracion de puntero que alberga una funcion

	t.doAnything(); //llamada al metodo de la funcion

	printf("Test::doAnything -> %p\n", (void*)&Test::doAnything);
	printf("Test::str -> %p\n", &Test::str);
	printf("Test::p   -> %p\n", &Test::p);
	printf("Test1::str -> %p\n", &Test1::str);
	printf("\n");
	
	printf("t -> %p\n", &t);
	printf("t.str -> %p\n", &t.str);
	printf("t.p -> %p\n", &t.p);
	printf("\n");


	printf("z -> %p\n", &z);
	printf("\n");

	printf("a -> %p\n", &a);
	printf("a.str -> %p\n", &a.str);


	
	//printf("Test::Test -> %p\n", &Test::Test);
	//printf("Test::~Test -> %p\n", &Test::~Test);


	
	func = (fn)&Test::doAnything;
	func((Test*)&a);

	return 0;
}