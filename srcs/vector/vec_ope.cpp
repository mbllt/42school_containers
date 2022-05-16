#include "test_vector.hpp"

template<typename Vec>
void fillVecString(Vec* cont) {

	typename Vec::iterator it = cont->begin();

	std::string str[10] = { "test", "pop", "essay", "beeze", "youhou",
								"orange", "blue", "black", "sun", "best" };
	for (size_t i = 0; i < cont->size(); ++i) {
		int val = rand() % 10;
		*it = str[val];
		++it;
	}
}

void vec_ope() {

	vector<std::string> vec(20, std::string());
	vector<std::string> bis(20, std::string());
	std::cout << "vec :";
	displayCont(vec);
	std::cout << "bis :";
	displayCont(bis);

// ==
	if (vec  == bis)
		std::cout << "vec == bis :" << (vec == bis) << "\n";

	bis.push_back(std::string());

// !=
	if (vec != bis)
		std::cout << "vec != bis :" << (vec != bis) << "\n";

// <
	if (vec < bis)
		std::cout << "vec < bis :" << (vec < bis) << "\n";

// <=
	if (vec <= bis)
		std::cout << "vec <= bis :" << (vec <= bis) << "\n";

	vec.push_back(std::string());
	vec.push_back(std::string());

// >
	if (vec > bis)
		std::cout << "vec > bis :" << (vec > bis) << "\n";

// >=
	if (vec >= bis)
		std::cout << "vec >= bis :" << (vec >= bis) << "\n";
}