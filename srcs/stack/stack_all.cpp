#include "test_stack.hpp"
#include <deque>

// void stack_all() {
void test() {

	std::deque<int> deq(5, 42);
	stack<int> stack(deq);
	// stack<int> bis(deq);

	// std::cout << "bis.push(5)\n";
	// bis.push(5);

	// std::cout << "stack.top() :" << "stack.size() :" << stack.size() << " - stack.empty() :" << stack.empty() << std::endl;
	// std::cout << "bis.top() :" << "bis.size() :" << bis.size() << " - bis.empty() :" << bis.empty() << std::endl;

	// std::cout << "stack = bis";
	// stack = bis;

	// std::cout << "stack.top() :" << "stack.size() :" << stack.size() << " - stack.empty() :" << stack.empty() << std::endl;
	// std::cout << "bis.top() :" << "bis.size() :" << bis.size() << " - bis.empty() :" << bis.empty() << std::endl;

	// std::cout << "stack.push(74)\n";
	// stack.push(74);

	// std::cout << "stack.top() :" << "stack.size() :" << stack.size() << " - stack.empty() :" << stack.empty() << std::endl;

	// std::cout << "stack.pop()\n";
	// stack.pop();

	// std::cout << "stack.top() :" << "stack.size() :" << stack.size() << " - stack.empty() :" << stack.empty() << std::endl;

	// std::cout << "stack == bis :" << (stack == bis) << std::endl;
	// std::cout << "stack != bis :" << (stack == bis) << std::endl;
	// std::cout << "stack < bis :" << (stack == bis) << std::endl;
	// std::cout << "stack <= bis :" << (stack == bis) << std::endl;
	// std::cout << "stack > bis :" << (stack == bis) << std::endl;
	// std::cout << "stack >= bis :" << (stack == bis) << std::endl;
}