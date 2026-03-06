#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <sstream>
#include <iostream>
#include <string>

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr); // acuerdate qeu static es que puedes llamar el metodo aunque no este instanciado el objeto
};

#endif