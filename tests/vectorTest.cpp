#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "vector.hpp"
#include "tests.hpp"

#define print_res(x) if (x)\
						std::cout << std::setw(35) << "\033[32m ok\033[0m" << std::endl;\
					else\
						std::cout << std::setw(35) << "\033[31m ko\033[0m" << std::endl;

#define X std::rand() % 12
#define Y std::rand() % 10
#define V std::vector<int>
#define MYV ft::vector<int>

template<typename T>
void displayVec(T vec) {

	typename T::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void test_constructors() {

	if (!DEBUG_MODE)
		std::cout << std::setw(25) << "test constructors ";

	V vec;
	V bis(X, Y);
	V::iterator it = bis.begin();
	V::iterator itbis = bis.end();
	V tres(it, itbis);
	V quatre(bis);

	std::cout << "bis before : ";
	displayVec(bis);
	bis[0] = 19;
	std::cout << "bis after : ";
	displayVec(bis);

//	----
//	try change val in bis to check if tres changed or not
//	test constructor range

	MYV myvec;
	MYV mybis(X, Y);
	MYV::iterator myit = mybis.begin();
	MYV::iterator myitbis = mybis.end();
	// MYV mytres(myit, myitbis);
	// MYV::iterator myittres = mybis.end();
	MYV myquatre(mybis);

	std::cout << "mybis before : ";
	displayVec(mybis);
	mybis[0] = 19;
	std::cout << "mybis after : ";
	displayVec(mybis);

	if (!DEBUG_MODE){
		print_res(*it == *myit/* && *myitbis == *myittres*/);}
}

void test_operators() {

//	test == != <= >=

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
	test_operators();

}