#include "tests.hpp"

void test_iterators(std::ofstream& of, std::ofstream& myof) {

//	++() ++(int) != == * --() --(int) < > <= >= += -= []
// ->

	printof(of, myof, "\nTEST ITERATORS");

	V vec(X, Y);
	V::iterator it = vec.begin();
	V::iterator itbis = vec.end();
	MYV myvec(X, Y);
	MYV::iterator myit = myvec.begin();
	MYV::iterator myitbis = myvec.end();

	printof(of, myof, "it ++()");
	for (int i = 1; it != itbis; ++it) {
	// std::cout << "vec[0] : " << vec[0] << std::endl;
		vec[i] = 10 + vec[i - 1];
		++i;
	}
	displayVec(of, vec);
	for (size_t i = 1; myit != myitbis; ++myit) {
	// std::cout << "bis : " << vec[0] << std::endl;
		if (i && i < myvec.size())
			myvec[i] = 10 + myvec[i - 1];
		++i;
	}
	displayVec(myof, myvec);

//	--()
	of << "it : " << *it << " | ";
	myof << "it : " << *myit << " | ";
	--it;
	--myit;
	of << "--it : " << *it << "\n";
	myof << "--it : " << *myit << "\n";

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

//	==
	if (*it == *itbis && *myit == *myitbis) {
		printof(of, myof, "*it == *itbis : true");
	}
	else if (*it == *itbis) {
		of << "*it == *itbis : true\n";
		myof << "*it == *itbis : false\n";
	}

//	!=
	if (*it != *itbis && *myit != *myitbis) {
		printof(of, myof, "*it != *itbis : true");
	}
	else if (*it != *itbis) {
		of << "*it != *itbis : true\n";
		myof << "*it != *itbis : false\n";
	}

	it = vec.begin();
	myit = myvec.begin();

//	<
	if (*it < *itbis && *myit < *myitbis) {
		printof(of, myof, "*it < *itbis : true");
	}
	else if (*it < *itbis) {
		of << "*it < *itbis : true\n";
		myof << "*it < *itbis : false\n";
	}

//	<=
	if (*it <= *itbis && *myit <= *myitbis) {
		printof(of, myof, "*it <= *itbis : true");
	}
	else if (*it <= *itbis) {
		of << "*it <= *itbis : true\n";
		myof << "*it <= *itbis : false\n";
	}

//	>
	if (*it > *itbis && *myit > *myitbis) {
		printof(of, myof, "*it > *itbis : true");
	}
	else if (*it > *itbis) {
		of << "*it > *itbis : true\n";
		myof << "*it > *itbis : false\n";
	}

//	>=
	if (*it >= *itbis && *myit >= *myitbis) {
		printof(of, myof, "*it >= *itbis : true");
	}
	else if (*it >= *itbis) {
		of << "*it >= *itbis : true\n";
		myof << "*it >= *itbis : false\n";
	}

// +(int) +(it)
	*it = (*it + 1) + (*it + 2);
	of << "*it = (*it + 1) + (*it + 2) = " << *it << "\n";

	*myit = (*myit + 1) + (*myit + 2);
	myof << "*it = (*it + 1) + (*it + 2) = " << *myit << "\n";

// -(int) -(it)
	*it = (*it - 1) + (*it - 2);
	of << "*it = (*it - 1) + (*it - 2) = " << *it << "\n";

	*myit = (*myit - 1) + (*myit - 2);
	myof << "*it = (*it - 1) + (*it - 2) = " << *myit << "\n";

 // +=(it)
	*it += *itbis;
	of << "*it += *itbis = " << *it << "\n";

	*myit += *itbis;
	myof << "*it += *itbis = " << *myit << "\n";

// -=(int)
	*it -= 15;
	of << "*it -= 15 = " << *it << "\n";

	*myit -= 15;
	myof << "*it -= 15 = " << *myit << "\n";

// [] do i need to test [] out of range ?
	display(of, vec, myof, myvec);
	of << "it[0] : " << it[0] << " | it[3] : " << it[3] << " it[50] : " << it[50] << "\n";
	myof << "it[0] : " << myit[0] << " | it[3] : " << myit[3] << " it[50] : " << myit[50] << "\n";
}