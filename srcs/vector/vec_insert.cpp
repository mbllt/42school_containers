#include "test_vector.hpp"

// void vec_insert() {
void test() {

	vector<std::string> vec;
	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;

	std::cout << "vec.insert(vec.begin(), 'quarante deux')" << std::endl;
	vector<std::string>::iterator ret = vec.insert(vec.begin(), "quarante deux");

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	std::cout << "ret :" << *ret << std::endl;

	std::cout << "vec.insert(vec.end(), 10, 'clavier')" << std::endl;
	ret = vec.insert(vec.end(), 10, "clavier");

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	std::cout << "ret :" << *ret << std::endl;

	vector<std::string> bis(10, "grass");
	std::cout << "bis :";
	displayVec(bis);

	std::cout << "vec.insert(vec.begin() + 3, bis.begin(), bis.begin() + 5)" << std::endl;
	ret = vec.insert(vec.begin() + 3, bis.begin(), bis.begin() + 5);

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	std::cout << "ret :" << *ret << std::endl;
}