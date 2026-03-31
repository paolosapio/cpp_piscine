#include "mutantstack.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	// [...]

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	return (0);
}

/* MAIN POTENTE */
/* int main()
{
    MutantStack<int> m;


	const MutantStack<int> cm(m);

	MutantStack<int>::const_iterator cit = cm.begin();
	MutantStack<int>::const_iterator cite = cm.end();
	
	std::cout << "\nIterando const MutantStack:" << std::endl;
	
	while (cit != cite)
	{
	    std::cout << *cit << std::endl;
	    ++cit;
	}
    // 🔧 Meter datos
    m.push(5);
    m.push(17);

    std::cout << "Top: " << m.top() << std::endl;

    m.pop();

    std::cout << "Size: " << m.size() << std::endl;

    m.push(3);
    m.push(5);
    m.push(737);
    m.push(0);

    // 🔥 Iterar (LO IMPORTANTE DEL EJERCICIO)
    std::cout << "\nIterando MutantStack:" << std::endl;

    MutantStack<int>::iterator it = m.begin();
    MutantStack<int>::iterator ite = m.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // 🧠 Comprobación con stack normal
    std::stack<int> s(m);

    std::cout << "\nStack normal (top): " << s.top() << std::endl;

    return 0;
} */