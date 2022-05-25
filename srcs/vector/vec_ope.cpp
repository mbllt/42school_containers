#include "test_vector.hpp"
#include <cstring>

void test() {

	vector<std::string> vec(20, std::string());
	fillVecString(&vec);
	std::cout << "vec :";
	displayVec(vec);
	vector<std::string> bis(20, std::string());
	fillVecString(&bis);
	std::cout << "bis :";
	displayVec(bis);

	if (vec  == bis)
		std::cout << "vec == bis :" << (vec == bis) << "\n";

	bis.push_back(std::string());

	if (vec != bis)
		std::cout << "vec != bis :" << (vec != bis) << "\n";

	if (vec < bis)
		std::cout << "vec < bis :" << (vec < bis) << "\n";

	if (vec <= bis)
		std::cout << "vec <= bis :" << (vec <= bis) << "\n";

	vec.push_back(std::string());
	vec.push_back(std::string());

	if (vec > bis)
		std::cout << "vec > bis :" << (vec > bis) << "\n";

	if (vec >= bis)
		std::cout << "vec >= bis :" << (vec >= bis) << "\n";

	vector<std::string>::iterator it = vec.begin();
	*it = "pop";
	std::cout << "strcmp(it->c_str(), 'pop') :" << strcmp(it->c_str(), "pop") << std::endl;
}