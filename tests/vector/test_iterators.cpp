#include "tests.hpp"

void test_iterators(std::ofstream& of, std::ofstream& myof) {

	printof(of, myof, "\ntest-iterators 👌");

	V vec(X, Y);
	V::iterator it = vec.begin();
	V::iterator ite = vec.end();
	MYV myvec(X, Y);
	MYV::iterator myit = myvec.begin();
	MYV::iterator myite = myvec.end();

	for (int i = 1; it != ite; ++it) {
		*it = i++;
	}
	displayVec(of, vec);
	for (int i = 1; myit != myite; ++myit) {
		*myit = i++;
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

// +(int)
	it = it + 1;
	it = 1 + it;
	of << "it = it + 1 : " << *it << "\n";

	myit = myit + 1;
	myit = 1 + myit;
	myof << "it = it + 1 : " << *myit << "\n";

// -(int)
	it = it - 1;
	of << "it = it + 1 : " << *it << "\n";

	myit = myit - 1;
	myof << "it = it + 1 : " << *myit << "\n";

// +=(it)
	it += 2;
	of << "it += 2 : " << *it << "\n";

	myit += 2;
	myof << "it += 2 : " << *myit << "\n";

// -=(int)
	it -= 2;
	of << "it -= 2 : " << *it << "\n";

	myit -= 2;
	myof << "it -= 2 : " << *myit << "\n";

// []
	it = vec.begin();
	myit = myvec.begin();
	display(of, vec, myof, myvec);

	of << "it[0] : " << it[0] << " | it[3] : " << it[3] << "\n";
	myof << "it[0] : " << myit[0] << " | it[3] : " << myit[3] << "\n";

	V::iterator itit = vec.begin();
	V::iterator tmp = itit + 3;
	MYV::iterator myitit = myvec.begin();
	MYV::iterator mytmp = myitit + 3;

// -(it)
	int i = itit - tmp;
	of << "int i = itit - tmp : " << i << "\n";

	int myi = myitit - mytmp;
	myof << "int i = itit - tmp : " << myi << "\n";

	for (int i = 0; i < 5; ++i) {

		srand (time(NULL));
		size_t nbr = rand() % (vec.size() - 1);
		size_t nbrbis = rand() % (vec.size() - 1);
		V::iterator ittest = vec.begin();
		*ittest = vec[nbr];
		V::iterator ittestbis = vec.begin();
		*ittestbis = vec[nbrbis];

		size_t mynbr = rand() % (myvec.size() - 1);
		size_t mynbrbis = rand() % (myvec.size() - 1);
		MYV::iterator myittest = myvec.begin();
		*myittest = myvec[mynbr];
		MYV::iterator myittestbis = myvec.begin();
		*myittestbis = myvec[mynbrbis];

//	==
		if (*ittest == *ittestbis && *myittest == *myittestbis)
			printof(of, myof, "*ittest == *ittestbis : true");
		else if (*ittest == *ittestbis) {
			of << "*ittest == *ittestbis : true\n";
	 		myof << "*ittest == *ittestbis : false\n";}

//	!=
		if (*ittest != *ittestbis && *myittest != *myittestbis)
			printof(of, myof, "*ittest != *ittestbis : true");
		else if (*ittest != *ittestbis) {
			of << "*ittest != *ittestbis : true\n";
	 		myof << "*ittest != *ittestbis : false\n";}

//	<
		if (*ittest < *ittestbis && *myittest < *myittestbis)
			printof(of, myof, "*ittest < *ittestbis : true");
		else if (*ittest < *ittestbis) {
			of << "*ittest < *ittestbis : true\n";
	 		myof << "*ittest < *ittestbis : false\n";}

//	<=
		if (*ittest <= *ittestbis && *myittest <= *myittestbis)
			printof(of, myof, "*ittest <= *ittestbis : true");
		else if (*ittest <= *ittestbis) {
			of << "*ittest <= *ittestbis : true\n";
	 		myof << "*ittest <= *ittestbis : false\n";}

//	>
		if (*ittest > *ittestbis && *myittest > *myittestbis)
			printof(of, myof, "*ittest > *ittestbis : true");
		else if (*ittest > *ittestbis) {
			of << "*ittest > *ittestbis : true\n";
	 		myof << "*ittest > *ittestbis : false\n";}

//	>=
		if (*ittest >= *ittestbis && *myittest >= *myittestbis)
			printof(of, myof, "*ittest >= *ittestbis : true");
		else if (*ittest >= *ittestbis) {
			of << "*ittest >= *ittestbis : true\n";
			myof << "*ittest >= *ittestbis : false\n";}
	}

// ->
	std::vector<std::string> test(4, "pop");
	std::vector<std::string>::iterator ittest = test.begin();
	if (!strcmp(ittest->c_str(), "pop"))
		of << "test operator -> ok \n";
	else
		of << "test operator -> ko \n";

	ft::vector<std::string> mytest(4, "pop");
	ft::vector<std::string>::iterator myittest = mytest.begin();
	if (!strcmp(myittest->c_str(), "pop"))
		myof << "test operator -> ok \n";
	else
		myof << "test operator -> ko \n";

}