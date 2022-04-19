#include "tests.hpp"

void test_operators(std::ofstream& of, std::ofstream& myof) {

	printof(of, myof, "\ntest-operators 👌");

	for (int i = 0;i < 10;++i) {

		srand (time(NULL));
		size_t nbr = rand() % 100;
		size_t val = rand() % 100;
		size_t nbr_tmp = rand() % 100;
		size_t val_tmp = rand() % 100;

		V vec(nbr, val);
		V tmp(nbr_tmp, val_tmp);
		MYV myvec(nbr, val);
		MYV mytmp(nbr_tmp, val_tmp);

	// !=
		if (myvec != mytmp) {
			printof(of, myof, "myvec != mytmp : true");
		}
		else if (vec != tmp) {
			of << "myvec != mytmp : true\n";
			myof << "myvec != mytmp : false\n";
		}

	// <
		if (myvec < mytmp) {
			printof(of, myof, "myvec < mytmp : true");
		}
		else if (vec < tmp) {
			of << "myvec < mytmp : true\n";
			myof << "myvec < mytmp : false\n";
		}

	// >
		if (myvec > mytmp) {
			printof(of, myof, "myvec > mytmp : true");
		}
		else if (vec > tmp) {
			of << "myvec > mytmp : true\n";
			myof << "myvec > mytmp : false\n";
		}
	}
}