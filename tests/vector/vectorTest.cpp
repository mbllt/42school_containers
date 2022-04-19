#include "tests.hpp"

void printof(std::ofstream& of, std::ofstream& myof, std::string str) {

	of << str << "\n";
	myof << str << "\n";
}

void testVector(void) {

//		tests perso

	std::vector<std::string> test(4, "pop");
	std::vector<std::string>::iterator ittest = test.begin();
	if (!strcmp(ittest->c_str(), "pop"))
		std::cout << "test operator -> ok \n";
	else
		std::cout << "test operator -> ko \n";

	// ft::vector<std::string> mytest(3, "pop");
	// ft::vector<std::string> mytest(4, "pop");
	// ft::vector<std::string>::iterator myittest = mytest.begin();
	// if (!strcmp(myittest->c_str(), "pop"))
	// 	std::cout << "test operator -> ok \n";
	// else
	// 	std::cout << "test operator -> ko \n";

	// std::ofstream of("res_vector.txt");
	// std::ofstream myof("res_myvector.txt");


	// srand (time(NULL));
	// try {
	// 	printof(of, myof, "------------------- TESTS VECTOR ------------------\n");
	// 	test_constructors(of, myof);
	// 	test_operators(of, myof);
	// 	test_iterators(of, myof);
	// } catch (const std::exception& e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// of.close();
	// myof.close();

}