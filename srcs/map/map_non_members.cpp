#include "test_map.hpp"

void test() {

	std::cout << "_______\n";
	std::cout << "test op ==\n";
	map<int, std::string> src;
	fillMapIntString(&src);
	map<int, std::string> other(src);
	std::cout << "src ";
	displayMap(src);
	std::cout << "other ";
	displayMap(other);

	std::cout << "\nsrc == other :" << (src == other) << "\n";
	std::cout << "src != other :" << (src != other) << "\n";
	std::cout << "src > other :" << (src > other) << "\n";
	std::cout << "src >= other :" << (src >= other) << "\n";
	std::cout << "src < other :" << (src < other) << "\n";
	std::cout << "src <= other :" << (src <= other) << "\n\n";

	std::cout << "\nfilling other\n";
	fillMapIntString(&other);
	std::cout << "src ";
	displayMap(src);
	std::cout << "other ";
	displayMap(other);

	std::cout << "\nsrc == other :" << (src == other) << "\n";
	std::cout << "src != other :" << (src != other) << "\n";
	std::cout << "src > other :" << (src > other) << "\n";
	std::cout << "src >= other :" << (src >= other) << "\n";
	std::cout << "src < other :" << (src < other) << "\n";
	std::cout << "src <= other :" << (src <= other) << "\n\n";

	std::cout << "\nfilling src\n";
	fillMapIntString(&src);
	std::cout << "src ";
	displayMap(src);
	std::cout << "other ";
	displayMap(other);

	std::cout << "\nsrc == other :" << (src == other) << "\n";
	std::cout << "src != other :" << (src != other) << "\n";
	std::cout << "src > other :" << (src > other) << "\n";
	std::cout << "src >= other :" << (src >= other) << "\n";
	std::cout << "src < other :" << (src < other) << "\n";
	std::cout << "src <= other :" << (src <= other) << "\n\n";

	std::cout << "\nbefore swap\n";
	std::cout << "src ";
	displayMap(src);
	std::cout << "other ";
	displayMap(other);

	swap(src, other);

	std::cout << "\nafter swap\n";
	std::cout << "src ";
	displayMap(src);
	std::cout << "other ";
	displayMap(other);
}