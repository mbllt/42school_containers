#include "test_vector.hpp"

void test() {

	vector<std::string> vec;
	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;

	std::cout << "vec.push_back()" << std::endl;
	vec.push_back("sunny");

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;

	std::cout << "vec.push_back() x 3" << std::endl;
	vec.push_back("try");
	vec.push_back("test");
	vec.push_back("ope");

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
}