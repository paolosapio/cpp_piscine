#include "Base.hpp"

int main(void)
{

	Base *Ptr_Who_A_B_C = generate();
	Base &Ref_Who_A_B_C = *Ptr_Who_A_B_C;

	identify(Ptr_Who_A_B_C);

	identify(Ref_Who_A_B_C);

	delete(Ptr_Who_A_B_C);
	return (0);
}
