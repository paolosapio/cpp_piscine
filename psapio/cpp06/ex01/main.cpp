#include "Serializer.hpp"

int main(void)
{
	Data algo;

	algo.numero = 7;
	algo.string = "viva la vida";

	

	uintptr_t data_raw;
	data_raw = Serializer::serialize(&algo);

	Data* new_conversion;
	new_conversion = Serializer::deserialize(data_raw);

	std::cout << new_conversion->numero << "\n";
	std::cout << new_conversion->string << "\n";

	return (0);
}
