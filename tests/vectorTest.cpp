#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "vector.hpp"
#include "tests.hpp"

#define X 5
#define Y 10
#define V std::vector<int>
#define MYV ft::vector<int>

template<typename T>
void displayVec(std::ofstream& out, T& vec) {

	typename T::iterator it;
	out << "display container : ";
	for (it = vec.begin(); it != vec.end(); ++it){
		out << *it << " ";
	}
	out << "\n";
}

template<typename T>
void display(std::ofstream& of, V& vec, std::ofstream& myof, T& myvec) {

	displayVec(of, vec);
	displayVec(myof, myvec);
}

void printof(std::ofstream& of, std::ofstream& myof, std::string str) {

	of << str << "\n";
	myof << str << "\n";
}

void test_constructors(std::ofstream& of, std::ofstream& myof) {

	printof(of, myof, "TEST CONSTRUCTORS");

	V vec;
	V bis(X, Y);
	V quatre(bis);

//	----
//	test constructor range

	MYV myvec;
	MYV mybis(X, Y);
	MYV myquatre(mybis);

	display(of, bis, myof, mybis);
	display(of, quatre, myof, myquatre);
}

void test_operators(std::ofstream& of, std::ofstream& myof) {

//	test == != <= >=

	printof(of, myof, "\nTEST OPERATORS");

	V vec(X, Y);
	V tmp = vec;

//	----

	MYV myvec(X, Y);
	MYV mytmp = myvec;

	if (myvec == mytmp)
		printof(of, myof, "op ==");
}

void test_iterators(std::ofstream& of, std::ofstream& myof) {

//	++() ++(int) == * --() --(int)
// != = -> [] += -+ + -(int) -(iterator) < > <= >=

	printof(of, myof, "\nTEST ITERATORS");

	V vec(X, Y);
	V::iterator it = vec.begin();
	V::iterator itbis = vec.end();


	for (int i = 1; it != itbis; ++it) {
	std::cout << "vec[0] : " << vec[0] << std::endl;
		vec[i] = 10 + vec[i - 1];
		++i;
	}
	displayVec(of, vec);

//	----

	MYV myvec(X, Y);
	MYV::iterator myit = myvec.begin();
	MYV::iterator myitbis = myvec.end();

	for (size_t i = 1; myit != myitbis; ++myit) {
	std::cout << "bis : " << vec[0] << std::endl;
		if (i && i < myvec.size())
			myvec[i] = 10 + myvec[i - 1];
		++i;
	}
	displayVec(myof, myvec);
	printof(of, myof, "it ++()");

	--it;
	--myit;
	of << *it << "\n";
	myof << *myit << "\n";
	printof(of, myof, "it --()");
	printof(of, myof, "it *");

	it++;
	myit++;
	of << *it << "\n";
	myof << *myit << "\n";
	printof(of, myof, "it ++(int)");

	it--;
	myit--;
	of << *it << "\n";
	myof << *myit << "\n";
	printof(of, myof, "it --(int)");

	if (*myit == *myitbis) {
		printof(of, myof, "it ==");
	}
	else
		myof << "error iterators\n";

	if (*myit != *myitbis) {
		printof(of, myof, "it !=");
	}
	else
		myof << "error iterators\n";
}

void testVector(void) {

	std::ofstream of("res_vector.txt");
	std::ofstream myof("res_myvector.txt");

	printof(of, myof, "------------------- TESTS VECTOR ------------------\n");

	srand (time(NULL));
	try {
		test_constructors(of, myof);
		test_operators(of, myof);
		test_iterators(of, myof);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}