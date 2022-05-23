#include "test_vector.hpp"

void test() {
			
	vector<int> vec;
	std::cout << "vec :";
	displayVec(vec);

	// empty
	std::cout << "vec.empty() :" << vec.empty() << std::endl;

	vec.resize(20, int());
	fillVecInt(&vec);
	std::cout << "vec :";
	displayVec(vec);

	// size max_size capacity
	std::cout << "vec.size() :" << vec.size() << 
		" - vec.max_size() :" << vec.max_size() << 
		" - vec.capacity() :" << vec.capacity() << std::endl;
	// reserve
	vec.reserve(25);
	std::cout << "vec.reserve(25)" << std::endl;
	std::cout << "vec.size() :" << vec.size() <<
		" - vec.max_size() :" << vec.max_size() <<
		" - vec.capacity() :" << vec.capacity() << std::endl;
}