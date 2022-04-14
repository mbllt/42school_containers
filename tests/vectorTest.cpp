#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "vector.hpp"

#define print_res(x) if (x)\
						std::cout << std::setw(35) << "\033[32m ok\033[0m" << std::endl;\
					else\
						std::cout << std::setw(35) << "\033[31m ko\033[0m" << std::endl;

#define DEBUG_MODE 0
#define X std::rand() % 12
#define Y std::rand() % 10
#define V std::vector<char>
#define MYV ft::vector<char>

template<typename T>
void displayVec(T vec) {

	(void)vec;
	typename T::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void test_constructors() {

	if (!DEBUG_MODE)
		std::cout << std::setw(25) << "test constructors ";

	V vec(X, Y);
	V::iterator it = vec.begin();
	V bis(vec);
	V tres;

//	----

	MYV myvec(X, Y);
	MYV::iterator myit = myvec.begin();
	MYV mybis(myvec);
	MYV mytres;

	if (!DEBUG_MODE){
		print_res(*it == *myit);}
}

void test_operator() {

	if (!DEBUG_MODE)
		std::cout << std::setw(25) << "test operator ";

	MYV vec(X, Y);
	MYV tmp = vec;

	if (!DEBUG_MODE){
		print_res(vec == tmp);}
}

void testVector(void) {

	std::cout << "\n\n------------------- TESTS VECTOR ------------------\n" << std::endl;

	srand (time(NULL));
	test_constructors();
	test_operator();

}