#include "test_vector.hpp"

void vec_capacity() {
			
	vector<int> vec;
	std::cout << "vec :";
	displayCont(vec);

	// empty
	std::cout << "vec.empty() :" << vec.empty() << std::endl;

	vec.resize(20, int());
	fillVecInt(&vec);
	std::cout << "vec :";
	displayCont(vec);

	// size
	std::cout << "vec.size() :" << vec.size() << std::endl;
	// max_size
	std::cout << "vec.max_size() :" << vec.max_size() << std::endl;
	// capacity
	std::cout << "vec.capacity() :" << vec.capacity() << std::endl;

	// reserve
	std::cout << "vec.reserve(25)" << std::endl;

	// size
	std::cout << "vec.size() :" << vec.size() << std::endl;
	// max_size
	std::cout << "vec.max_size() :" << vec.max_size() << std::endl;
	// capacity
	std::cout << "vec.capacity() :" << vec.capacity() << std::endl;
}