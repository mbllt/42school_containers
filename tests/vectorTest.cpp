#include <iostream>
#include <string>
#include <vector>

void testVector(void) {

	std::cout << "\n\n\ntest: constructors" << "\n";
	std::vector<int>	testLeaks;
	(void)testLeaks;

	std::vector<int>	container(8, 10);
	std::cout << "container :";
	// displayVector(container);

	std::cout << "change container:" ;
	for (size_t i = 1;i < container.size(); ++i)
		if (i > 0)
			container[i] += container[i - 1];
	// displayVector(container);

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
	std::vector<const int> bonjour(5, 0);


	std::cout << "rbegin : " << *(bonjour.rbegin()) << std::endl;
}