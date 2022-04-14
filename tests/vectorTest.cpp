#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "vector.hpp"

#define DEBUG_MODE 0
#define X 5
#define Y 2
#define V std::vector<int>
#define MYV ft::vector<int>

template<typename T>
void displayVec(T vec) {

	(void)vec;
	typename T::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool test_constructors() {

	if (!DEBUG_MODE)
		std::cout << std::setw(25) << "test constructors ";

//	vector
	V vec(X, Y);
	V::iterator it = vec.begin();

//	myvector
	MYV myvec(X, Y);
	MYV::iterator myit = myvec.begin();

	return (*it == *myit ? 1 : 0);
}

bool test_operator() {

	if (!DEBUG_MODE)
		std::cout << std::setw(25) << "test operator ";

	ft::vector<int> vec(X, Y);
	ft::vector<int> bis(vec);
	// ft::vector<int> tmp = bis;
	
	// displayVec(vec);
	// displayVec(bis);

	return (vec == bis ? 1 : 0);
}

void testVector(void) {

	std::cout << "\n\n------------------- TESTS VECTOR ------------------\n" << std::endl;



	if (!test_constructors() && !DEBUG_MODE)
		std::cout << std::setw(35) << "\033[31m ko\033[0m" << std::endl;
	else if (!DEBUG_MODE)
		std::cout << std::setw(35) << "\033[32m ok\033[0m" << std::endl;

	if (!test_operator() && !DEBUG_MODE)
		std::cout << std::setw(35) << "\033[31m ko\033[0m" << std::endl;
	else if (!DEBUG_MODE)
		std::cout << std::setw(35) << "\033[32m ok\033[0m" << std::endl;

}