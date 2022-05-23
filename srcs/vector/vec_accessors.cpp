#include "test_vector.hpp"

void test() {

	vector<std::string> vec(20, std::string());
	fillVecString(&vec);
	std::cout << "vec :";
	displayVec(vec);

	std::cout << "vec[0] :" << vec[0] << std::endl;
	std::cout << "vec.at(10) :" << vec.at(10) << std::endl;
	std::cout << "vec.front() :" << vec.front() << std::endl;
	std::cout << "vec.back() :" << vec.back() << std::endl;

	vector<std::string> bis(10, std::string());
	fillVecString(&bis);
	std::cout << "bis :";
	displayVec(bis);

	std::cout << "bis[5] :" << bis[5] << std::endl;
	std::cout << "bis.at(1) :" << bis.at(1) << std::endl;
	std::cout << "bis.front() :" << bis.front() << std::endl;
	std::cout << "bis.back() :" << bis.back() << std::endl;
}