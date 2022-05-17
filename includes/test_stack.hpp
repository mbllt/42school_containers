#pragma once
#include "tests.hpp"
#ifdef MINE
  #include "stack.hpp"
  using namespace ft;
#else
  #include <stack>
  using namespace std;
#endif

// #ifndef TEST_STACK_HPP
// #define TEST_STACK_HPP

// #include <iostream>
// #include <string>
// #include <stack>
// #include <vector>
// #include "tests.hpp"
// #include "stack.hpp"

// template<typename T, class Container>
// class TestStack {

// 	private:

// 		Container cont;

// 	public:

// 		TestStack(const Container & cont) : cont(cont) {}
// 		~TestStack() {}

// 		void test_everything(std::ofstream& of, std::ofstream& myof) {

// 			of << "\n\n\nTEST-GENERAL ✅ - TEST-ACCESS ✅\n\n";
// 			myof << "\n\n\nTEST-GENERAL ✅ - TEST-ACCESS ✅\n\n";

// 			std::stack<T> sta(cont);
// 			std::stack<T> bis(cont);
// 			ft::stack<T> mysta(cont);
// 			ft::stack<T> mybis(cont);

// 			bis.push(5);
// 			mybis.push(5);
			
// 			of << "sta top :" << sta.top() << "\n";
// 			myof << "sta top :" << mysta.top() << "\n";
// 			of << "bis top :" << bis.top() << "\n";
// 			myof << "bis top :" << mybis.top() << "\n";

// 			print_str(of, myof, "sta = bis");
// 			sta = bis;
// 			mysta = mybis;

// 			of << "sta top :" << sta.top() << "\n";
// 			myof << "sta top :" << mysta.top() << "\n";


// 			of << "\n\n\nTEST-CAPACITY ✅\n\n";
// 			myof << "\n\n\nTEST-CAPACITY ✅\n\n";

// 			of << "sta size :" << sta.size() << "\n";
// 			myof << "sta size :" << mysta.size() << "\n";

// 			of << "sta empty :" << sta.empty() << "\n";
// 			myof << "sta empty :" << mysta.empty() << "\n";


// 			of << "\n\n\nTEST-CAPACITY ✅\n\n";
// 			myof << "\n\n\nTEST-CAPACITY ✅\n\n";

// 			of << "sta top :" << sta.top() << "\n";
// 			myof << "sta top :" << mysta.top() << "\n";

// 			print_str(of, myof, "sta.push(6)");
// 			sta.push(6);
// 			mysta.push(6);

// 			of << "sta top :" << sta.top() << "\n";
// 			myof << "sta top :" << mysta.top() << "\n";

// 			of << "sta top :" << sta.top() << "\n";
// 			myof << "sta top :" << mysta.top() << "\n";

// 			print_str(of, myof, "sta.pop()");
// 			sta.pop();
// 			mysta.pop();

// 			of << "sta top :" << sta.top() << "\n";
// 			myof << "sta top :" << mysta.top() << "\n";


// 			of << "\n\n\nTEST-OPERATORS ✅\n\n";
// 			myof << "\n\n\nTEST-OPERATORS ✅\n\n";

// 			of << "sta == bis :" << (sta != bis) << "\n";
// 			myof << "sta == bis :" << (mysta != mybis) << "\n";

// 			of << "sta != bis :" << (sta != bis) << "\n";
// 			myof << "sta != bis :" << (mysta != mybis) << "\n";

// 			of << "sta < bis :" << (sta < bis) << "\n";
// 			myof << "sta < bis :" << (mysta < mybis) << "\n";

// 			of << "sta <= bis :" << (sta <= bis) << "\n";
// 			myof << "sta <= bis :" << (mysta <= mybis) << "\n";

// 			of << "sta > bis :" << (sta > bis) << "\n";
// 			myof << "sta > bis :" << (mysta > mybis) << "\n";

// 			of << "sta >= bis :" << (sta >= bis) << "\n";
// 			myof << "sta >= bis :" << (mysta >= mybis) << "\n";
// 		}

// };

// #endif