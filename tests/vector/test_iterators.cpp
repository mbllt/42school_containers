#include "tests.hpp"

void test_iterators(std::ofstream& of, std::ofstream& myof) {

//	++() ++(int) != == * --() --(int) < > <= >= += -= []
// ->

	printof(of, myof, "\nTEST ITERATORS");

	V vec(X, Y);
	V::iterator it = vec.begin();
	V::iterator ite = vec.end();
	MYV myvec(X, Y);
	MYV::iterator myit = myvec.begin();
	MYV::iterator myite = myvec.end();

	printof(of, myof, "it ++()");
	for (int i = 1; it != ite; ++it) {
	// std::cout << "vec[0] : " << vec[0] << std::endl;
		*it = i;
	}
	displayVec(of, vec);
	for (size_t i = 1; myit != myite; ++myit) {
		*myit = i;
	}
	displayVec(myof, myvec);

	it = vec.begin(); // to avoid reading vec.end() -> undefined behavior
	myit = myvec.begin();

//	++(int)
	of << "it : " << *it << " | ";
	myof << "it : " << *myit << " | ";
	it++;
	myit++;
	of << "it++ : " << *it << "\n";
	myof << "it++ : " << *myit << "\n";

//	--(int)
	of << "it : " << *it << " | ";
	myof << "it : " << *myit << " | ";
	it--;
	myit--;
	of << "it-- : " << *it << "\n";
	myof << "it-- : " << *myit << "\n";

//	++()
	of << "it : " << *it << " | ";
	myof << "it : " << *myit << " | ";
	++it;
	++myit;
	of << "++it : " << *it << "\n";
	myof << "++it : " << *myit << "\n";

//	--()
	of << "it : " << *it << " | ";
	myof << "it : " << *myit << " | ";
	--it;
	--myit;
	of << "--it : " << *it << "\n";
	myof << "--it : " << *myit << "\n";

//	==
	if (*it == *myit) {
		printof(of, myof, "*it == *myit : true");
	}
	else {
		of << "*it == *myit : true\n";
		myof << "*it == *itmy : false\n";
	}

//	!=
	if (*it != *myit) {
		printof(of, myof, "*it != *myit : true");
	}
	else {
		of << "*it != *myit : true\n";
		myof << "*it != *itmy : false\n";
	}

	it = vec.begin();
	myit = myvec.begin();

//	<
	if (*it < *myit) {
		printof(of, myof, "*it < *myit : true");
	}
	else {
		of << "*it < *myit : true\n";
		myof << "*it < *itmy : false\n";
	}

//	<=
	if (*it <= *myit) {
		printof(of, myof, "*it <= *myit : true");
	}
	else {
		of << "*it <= *myit : true\n";
		myof << "*it <= *itmy : false\n";
	}

//	>
	if (*it > *myit) {
		printof(of, myof, "*it > *myit : true");
	}
	else {
		of << "*it > *myit : true\n";
		myof << "*it > *itmy : false\n";
	}

//	>=
	if (*it >= *myit) {
		printof(of, myof, "*it >= *myit : true");
	}
	else {
		of << "*it >= *myit : true\n";
		myof << "*it >= *itmy : false\n";
	}

// +(int)
	it = it + 1;
	it = 1 + it;
	of << "it = it + 1 = " << *it << "\n";

	myit = myit + 1;
	myit = 1 + myit;
	myof << "it = it + 1 = " << *myit << "\n";

// -(int)
	it = it - 1;
	of << "it = it + 1 = " << *it << "\n";

	myit = myit - 1;
	myof << "it = it + 1 = " << *myit << "\n";

	V::iterator itit = vec.begin();
	V::iterator tmp = itit + 3;
	MYV::iterator myitit = myvec.begin();
	MYV::iterator mytmp = myitit + 3;

	display(of, vec, myof, myvec);
	std::cout << "tmp : " << *tmp << std::endl;
	std::cout << "mytmp : " << *mytmp << std::endl;

// -(it)
	int i = itit - tmp;
	of << "int i = itit - tmp = " << i << "\n";

	int myi = myitit - mytmp;
	myof << "int i = itit - tmp = " << myi << "\n";

// +=(it)
	it += 2;
	of << "it += 2 = " << *it << "\n";

	myit += 2;
	myof << "it += 2 = " << *myit << "\n";

// -=(int)
	it -= 2;
	of << "it -= 2 = " << *it << "\n";

	myit -= 2;
	myof << "it -= 2 = " << *myit << "\n";

// [] do i need to test [] out of range ?
	display(of, vec, myof, myvec);
	of << "it[0] : " << it[0] << " | it[3] : " << it[3] << "\n";
	myof << "it[0] : " << myit[0] << " | it[3] : " << myit[3] << "\n";

// -> SEG FAULT
	// ft::vector<std::string> test(4, "pop");
	// ft::vector<std::string>::iterator ittest = test.begin();
	// std::cout << "ittest->c_str : " << ittest->c_str() << std::endl;
	// std::cout << "test here\n";

}