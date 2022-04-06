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

	std::cout << "test Vector constructor empty no leaks" << "\n";
	Vector<int>	testLeaks;
	(void)testLeaks;

	Vector<int>	src(5, 10);
	std::cout << "src :" << "\n";
	displayVector(src);

	std::cout << "\n-----------------\n" << std::endl;

	std::cout << "dest copy of src :" << "\n";
	Vector<int>	dest(src);
	displayVector(dest);

	std::cout << "\n-----------------\n" << std::endl;

	std::cout << "change src[0]" << "\n";
	src[0] = 5;
	std::cout << "src :" << "\n";
	displayVector(src);

	std::cout << "\n-----------------\n" << std::endl;

	std::cout << "dest :" << "\n";
	displayVector(dest);

	std::cout << "\n-----------------\n" << std::endl;

	std::cout << "Incrementing src" << "\n";
	incrementVector(src);
	displayVector(src);

	std::cout << "\n-----------------\n" << std::endl;

	std::cout << "error invalid index test" << "\n";
	try {
		dest[50] = 2;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}