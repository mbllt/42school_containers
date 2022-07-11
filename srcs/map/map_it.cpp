#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "iterators\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	typename map<int, std::string>::iterator it = mapp.begin();

	//	++(int)
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	it++;
	std::cout << "it++ : ";
	displayMapNode(it);
	std::cout << "\n";

	//	--(int)
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	it--;
	std::cout << "it-- : ";
	displayMapNode(it);
	std::cout << "\n";

	//	++()
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	++it;
	std::cout << "++it : ";
	displayMapNode(it);
	std::cout << "\n";

	//	--()
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	--it;
	std::cout << "--it : ";
	displayMapNode(it);
	std::cout << "\n";

	std::cout << "--(++it) == it : " << (--(++it) == it) << "\n";
}