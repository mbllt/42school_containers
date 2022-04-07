#include <iostream>
#include <string>
#include "Vector.hpp"

template<typename T>
void	displayVector(Vector<T> const & arr) {
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void	incrementVector(Vector<int> & arr) {
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i]++;
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

	// container::VectorIterator it_test;
	// VectorIterator test(container);
	// typename VectorIterator test(container);
	// VectorIterator until(container+5);
	// for (VectorIterator it=from; it!=until; it++)
	// 	std::cout << *it << ' ';

	std::cout << "\n\n" << std::endl;
	return 0;
}