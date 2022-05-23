#include "test_vector.hpp"

void test() {

	vector<std::string> vec(10, std::string());
	fillVecString(&vec);
	std::cout << "vec :";
	displayVec(vec);

	vector<std::string> bis(20, std::string());
	fillVecString(&bis);
	std::cout << "bis :";
	displayVec(bis);

	vector<std::string>::iterator it = vec.begin() + 3;
	vector<std::string>::iterator itbis = bis.begin() + 5;

	std::cout << "it[3] de vec au debut :" << *it << " - it[5] de bis au debut :" << *itbis << "\n";
	std::cout << "swap(vec, bis)" << std::endl;
	swap(vec, bis);
	std::cout << "vec :";
	displayVec(vec);
	std::cout << "bis :";
	displayVec(bis);
	std::cout << "it[3] de vec a la fin :" << *it << "it[5] de bis a la fin :" << *itbis << "\n";

	vector<std::string> tres(5, std::string());
	fillVecString(&tres);
	std::cout << "tres :";
	displayVec(tres);

	std::cout << "it[5] de bis au debut :" << *itbis << "\n";
	std::cout << "bis.swap(tres)" << std::endl;
	bis.swap(tres);
	std::cout << "vec :";
	displayVec(bis);
	std::cout << "bis :";
	displayVec(tres);
	std::cout << "it[5] de bis a la fin :" << *itbis << "\n";
}