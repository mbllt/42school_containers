#include "test_vector.hpp"

void vec_resize() {

	vector<std::string> vec;
	std::cout << "vec :";
	displayCont(vec);

	std::cout << "vec.size() :" << vec.size() << std::endl;
	std::cout << "vec.capacity() :" << vec.capacity() << std::endl;
	// resize
	std::cout << "vec.resize(2) :";
	std::cout << "vec.size() :" << vec.size() << std::endl;
	std::cout << "vec.capacity() :" << vec.capacity() << std::endl;

	vector<std::string> bis(10, std::string());
	fillVecString(&bis);
	std::cout << "bis :";
	displayCont(bis);

	std::cout << "bis.size() :" << bis.size() << std::endl;
	std::cout << "bis.capacity() :" << bis.capacity() << std::endl;
	// resize
	std::cout << "bis.resize(5) :";
	std::cout << "bis.size() :" << bis.size() << std::endl;
	std::cout << "bis.capacity() :" << bis.capacity() << std::endl;
	// resize
	std::cout << "bis.resize(30) :";
	std::cout << "bis.size() :" << bis.size() << std::endl;
	std::cout << "bis.capacity() :" << bis.capacity() << std::endl;
}
