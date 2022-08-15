#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "reverse iterators\n";
	map<int, std::string> mapp;
	fillMapIntString(&mapp);
	displayMap(mapp);

	map<int, std::string>::reverse_iterator it = mapp.rbegin();
	(void)it;

	//	it++
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	it++;
	std::cout << "it++ : ";
	displayMapNode(it);
	std::cout << "\n";

	//	it--
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	it--;
	std::cout << "it-- : ";
	displayMapNode(it);
	std::cout << "\n";

	//	++it
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	++it;
	std::cout << "++it : ";
	displayMapNode(it);
	std::cout << "\n";

	//	--it
	std::cout << "it : ";
	displayMapNode(it);
	std::cout << "| ";
	--it;
	std::cout << "--it : ";
	displayMapNode(it);
	std::cout << "\n";

	std::cout << "--(++it) == it : " << (--(++it) == it) << "\n";

	std::cout << "_______\n";
	std::cout << "const reverse iterators\n";
	map<int, std::string> bis;
	fillMapIntString(&bis);
	displayMap(bis);

	map<int, std::string>::reverse_iterator itbis = bis.rbegin();

	//	it++
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	itbis++;
	std::cout << "itbis++ : ";
	displayMapNode(itbis);
	std::cout << "\n";

	//	it--
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	itbis--;
	std::cout << "itbis-- : ";
	displayMapNode(itbis);
	std::cout << "\n";

	//	++it
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	++itbis;
	std::cout << "++itbis : ";
	displayMapNode(itbis);
	std::cout << "\n";

	//	--it
	std::cout << "itbis : ";
	displayMapNode(itbis);
	std::cout << "| ";
	--itbis;
	std::cout << "--itbis : ";
	displayMapNode(itbis);
	std::cout << "\n";
}