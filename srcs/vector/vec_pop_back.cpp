#include "test_vector.hpp"

void vec_pop_back() {

	vector<int> vec(10, int());
	fillVecInt(&vec);
	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;

	std::cout << "vec.pop_back()" << std::endl;
	vec.pop_back();

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;

	std::cout << "vec.pop_back() x 3" << std::endl;
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
}