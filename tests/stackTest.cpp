#include "tests.hpp"
#include "test_stack.hpp"
#include <stdlib.h>
#include <time.h>

void testStack(void) {

	std::ofstream of("bin/stack.txt");
	std::ofstream myof("bin/mystack.txt");

	std::deque<int> deq(10, 2);
	TestStack<int, std::deque<int> > test_stack(deq);

	srand (time(NULL));
	try {
		of << "\n\n\n------------------- TESTS STACK ------------------\n";
		myof << "\n\n\n------------------- TESTS STACK ------------------\n";
		test_stack.test_everything(of, myof);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	of.close();
	myof.close();
}
