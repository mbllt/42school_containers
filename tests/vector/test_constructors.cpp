#include "tests.hpp"

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