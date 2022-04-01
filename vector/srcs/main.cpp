#include <iostream>
#include <string>
#include "easyfind.hpp"
#include <vector>

template<typename T>
void	displayContainer(T container) {
	typename T::iterator iter;
	for (iter = container.begin(); iter != container.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

int	main(void) {

	int myInts[] = {16, 4, 54, 2, 74, 99};
	std::vector<int> vec(myInts, myInts + sizeof(myInts) / sizeof(int));
	int	ret = 0;

	try {
		std::cout << "test found int :" << std::endl;
		displayContainer(vec);
		ret = ::easyfind(vec, 54);
		std::cout << "ret : " << ret << std::endl;

		std::cout << "-----------------------" << std::endl;

		std::cout << "test int not found :" << std::endl;
		ret = ::easyfind(vec, 14);
		std::cout << "ret : " << ret << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}