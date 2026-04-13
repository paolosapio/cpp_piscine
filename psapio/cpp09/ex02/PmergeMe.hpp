#pragma once

#include <vector>
#include <stack>
#include <iostream>




class PmergeMe
{
private:
	std::vector<int> _vector;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void setVector(const int value);
	void printVector();
};


































/* class PmergeMe
{
private:

	PmergeMe();
	template<typename Container> static bool isSorted(Container & cont);
	
	template<typename Container> void mergeContainer(Container & cont);
	
	template<typename Container> void sortContainer(Container & cont, Container & left, Container & right);

	std::vector<int> vector_;
	std::deque<int> deque_;

public:
	void sort();
	
	
	explicit PmergeMe(std::vector<int> list);

	
	PmergeMe(const PmergeMe &other);

	
	PmergeMe &operator=(const PmergeMe &other);


	~PmergeMe();

	class duplicatedNumbers : public std::exception
	{
		const char *what() const throw();
	};
};

 */




/* >
./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After : 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After:
79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
 */




/* 3 7 2 105 66 8 10 54 92 13
3 7 2 105 8 66 10 54 13 92
 7   105   66    54    92
 7   105   45    66    92
  105         66       92
  66         105       92
		105            92
		92            105
			   105
 */