#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <sstream>
#include <iostream>
#include <string>
#include <stdint.h>

typedef struct S_Data
{
	int		numero;
	std::string	string;
} Data;


class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr); // acuerdate qeu static es que puedes llamar el metodo aunque no este instanciado el objeto
	static Data* deserialize(uintptr_t raw);
};

#endif