#include "tests.hpp"

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