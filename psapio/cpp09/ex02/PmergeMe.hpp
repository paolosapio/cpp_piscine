#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int>  _deque;

	// --- Helpers del algoritmo (los iremos llenando poco a poco) ---

	// Pairing para vector: construye mainChain, pending y straggler
	std::vector<int> pairingVector(const std::vector<int> &input,
								   std::vector<int> &pending,
								   bool &haySobrante,
								   int &sobrante);

	// Más adelante usaremos esto:
	// std::vector<size_t> generateJacobsthal(size_t n);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	// Mete el mismo valor en vector y deque
	void setContainers(const int value);

	// Impresoras
	void printVector() const;
	void printDeque() const;

	// Luego aquí implementaremos el algoritmo completo
	void sortVector();
	void sortDeque();

	std::vector<int> fordJohnson(const std::vector<int> &input);

	std::vector<size_t> generateJacobsthal(size_t n);

	void insertPending(	std::vector<int> &mainChain,
						const std::vector<int> &pending,
						const std::vector<size_t> &seq	);


};
