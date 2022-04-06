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

	std::cout << "\n\n\ntest constructors" << "\n";
	Vector<int>	testLeaks;
	(void)testLeaks;

	Vector<int>	test1(5, 10);
	std::cout << "test1 :" << "\n";
	displayVector(test1);

	std::cout << "\n" << std::endl;

	std::cout << "test2 copy of test1 :" << "\n";
	Vector<int>	test2(test1);
	displayVector(test2);

	std::cout << "\n-----------------\n" << std::endl;

	std::cout << "error invalid index test" << "\n";
	try {
		test2[50] = 2;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n\n" << std::endl;
	return 0;
}