#include "test_vector.hpp"

void test()
{
	vector<std::string> vec(20, std::string());
	fillVecString(&vec);
	std::cout << "vec :";
	displayVec(vec);

	vector<std::string>::reverse_iterator it = vec.rbegin();

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
	it = it + 2;
	std::cout << "it = it + 2 :" << *it << "\n";

// faut - au lieu de +
	it = 1 + it;
	std::cout << "it = 1 + it :" << *it << "\n";

	// // -(int)
	it = it - 1;
	std::cout << "it = it - 1 :" << *it << "\n";

	// +=(it)
	it += 2;
	std::cout << "it += 2 :" << *it << "\n";

	// -=(int)
	it -= 2;
	std::cout << "it -= 2 :" << *it << "\n";

	// []
	it = vec.rbegin();
	std::cout << "it[0] :" << it[0] << " | it[3] :" << it[3] << "\n";

	for (int i = 0; i < 5; ++i)
	{

		size_t nbr = rand() % (vec.size() - 1);
		size_t nbrbis = rand() % (vec.size() - 1);
		vector<std::string>::reverse_iterator it1 = vec.rbegin();
		*it1 = vec[nbr];
		vector<std::string>::reverse_iterator it2 = vec.rbegin();
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

	vector<int> vect;

	for (int i = 0; i < 10; ++i)
	  vect.push_back(i);
	typedef vector<int>::iterator m;
	reverse_iterator<m> rit(vect.begin());
	reverse_iterator<m> rite(vect.end());

	++rit;

	std::cout << "it(" << *rit << ") - ite(" << *rite << ") : " << (rit - rite) << ")" << "\n";
}