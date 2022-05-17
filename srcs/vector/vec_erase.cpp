#include "test_vector.hpp"

void vec_erase() {

	vector<std::string> vec(10, std::string());
	fillVecString(&vec);
	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	
	vector<std::string>::iterator it = vec.begin();
	std::cout << "vec.erase(vec.begin())" << std::endl;
	vector<std::string>::iterator ret = vec.erase(it);

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	std::cout << "ret erase() :" << *ret << std::endl;

	std::cout << "vec.erase(vec.begin(), vec.begin() + 5)" << std::endl;
	ret = vec.erase(vec.begin(), vec.begin() + 5);

	std::cout << "vec :";
	displayVec(vec);
	std::cout << "vec.size() :" << vec.size() << " - vec.capacity() :" << vec.capacity() << std::endl;
	std::cout << "ret erase() :" << *ret << std::endl;
}