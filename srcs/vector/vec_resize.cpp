#include "test_vector.hpp"

void vec_resize() {

	vector<int> vec;
	std::cout << "vec :";
	displayVec(vec);

	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	// resize
	vec.resize(2);
	std::cout << "vec.resize(2)" << std::endl;
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;

	vector<int> bis(10, int());
	fillVecInt(&bis);
	std::cout << "bis :";
	displayVec(bis);

	std::cout << "bis.size() :" << bis.size() << " - bis.capacity() :" << bis.capacity() << std::endl;
	// resize
	bis.resize(5);
	std::cout << "bis.resize(5)" << std::endl;
	std::cout << "bis.size() :" << bis.size() << " - bis.capacity() :" << bis.capacity() << std::endl;
	// resize
	bis.resize(30);
	std::cout << "bis.resize(30)" << std::endl;
	std::cout << "bis.size() :" << bis.size() << " - bis.capacity() :" << bis.capacity() << std::endl;
}
