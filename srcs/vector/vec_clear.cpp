#include "test_vector.hpp"

void vec_clear() {

	vector<int> vec(10, int());
	fillVecInt(&vec);
	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	
	std::cout << "vec.clear()" << std::endl;
	vec.clear();

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;

	std::cout << "vec.push_back(7)" << std::endl;
	vec.push_back(7);

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
}