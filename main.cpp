#include <iostream>
#include <string>
#include <vector>
#include "Vector.hpp"

template<typename T>
void	displayVector(Vector<T> const & container) {
	std::cout << "HERE !!!! size : " << container.size() << std::endl;
	for (unsigned int i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << "\n";
}

int	main(void) {

	std::cout << "\n\n\ntest: constructors" << "\n";
	Vector<int>	testLeaks;
	(void)testLeaks;

	Vector<int>	container(8, 10);
	std::cout << "container :";
	displayVector(container);

	std::cout << "change container:" ;
	for (size_t i = 1;i < container.size(); ++i)
		if (i > 0)
			container[i] += container[i - 1];
	displayVector(container);

	std::cout << "\n-----------------\n" << std::endl;
	std::cout << "test: error invalid index" << "\n";

	try {
		container[50] = 2;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------\n" << std::endl;
	std::cout << "test: iterators" << "\n";

	// std::vector<const int> bonjour(5, 0);
	Vector<int> bonjour(5, 0);
	// int i = 0;

	// Vector<const int>::iterator it = bonjour.begin();
	// while (it != bonjour.end()) {
	// 	++it;
	// 	*it = ++i;
	// }
	// displayVector(bonjour);

	std::cout << "rbegin : " << *(bonjour.rbegin()) << std::endl;
	return 0;
}
