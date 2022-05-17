
#include "test_vector.hpp"

// void vec_it() {
void test() {

	vector<std::string> vec(20, std::string());
	fillVecString(&vec);
	std::cout << "vec :";
	displayVec(vec);

	vector<std::string>::iterator it = vec.begin();

	//	++(int)
	std::cout << "it :" << *it << "| ";
	it++;
	std::cout << "it++ :" << *it << "\n";

	//	--(int)
	std::cout << "it : " << *it << "| ";
	it--;
	std::cout << "it-- : " << *it << "\n";

	//	++()
	std::cout << "it :" << *it << "| ";
	++it;
	std::cout << "++it :" << *it << "\n";

	//	--()
	std::cout << "it : " << *it << " | ";
	--it;
	std::cout << "--it :" << *it << "\n";

	// +(int)
	it = it + 1;
	it = 1 + it;
			std::cout << "it = it + 1 :" << *it << "\n";


	// -(int)
	it = it - 1;
	std::cout << "it = it - 1 :" << *it << "\n";


	// +=(it)
	it += 2;
	std::cout << "it += 2 :" << *it << "\n";


	// -=(int)
	it -= 2;
	std::cout << "it -= 2 :" << *it << "\n";


	// []
	it = vec.begin();

	std::cout << "it[0] :" << it[0] << " | it[3] :" << it[3] << "\n";

	vector<std::string>::iterator itit = vec.begin();
	vector<std::string>::iterator tmp = itit + 3;

	// -(it)
	int i = itit - tmp;
	std::cout << "int i = itit - tmp :" << i << "\n";


	for (int i = 0; i < 5; ++i) {
			
		srand (time(NULL));
		size_t nbr = rand() % (vec.size() - 1);
		size_t nbrbis = rand() % (vec.size() - 1);
		vector<std::string>::iterator it1 = vec.begin();
		*it1 = vec[nbr];
		vector<std::string>::iterator it2 = vec.begin();
		*it2 = vec[nbrbis];

		if (*it1 == *it2)
			std::cout << "*it1 == *it2 : true\n";
		else
			std::cout << "*it1 == *it2 : false\n";
		if (*it1 != *it2)
			std::cout << "*it1 != *it2 : true\n";
		else
			std::cout << "*it1 != *it2 : false\n";
		if (*it1 < *it2)
			std::cout << "*it1 < *it2 : true\n";
		else
			std::cout << "*it1 < *it2 : false\n";
		if (*it1 <= *it2)
			std::cout << "*it1 <= *it2 : true\n";
		else
			std::cout << "*it1 <= *it2 : false\n";
		if (*it1 > *it2)
			std::cout << "*it1 > *it2 : true\n";
		else
			std::cout << "*it1 > *it2 : false\n";
		if (*it1 >= *it2)
			std::cout << "*it1 >= *it2 : true\n";
		else
			std::cout << "*it1 >= *it2 : false\n";
	}
}