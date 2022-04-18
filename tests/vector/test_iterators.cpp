#include "tests.hpp"

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