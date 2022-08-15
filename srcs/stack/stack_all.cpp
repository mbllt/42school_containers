#include "test_stack.hpp"
#include <deque>

stack<int> basic()
{
	stack<int> c;
	c.push(1);
	c.push(2);
	c.push(3);
	c.push(4);
	c.push(5);
   return c;
}

void test() {
	std::cout << "----------> default <----------" << std::endl;
	{
		typedef stack<int> Stack;
		Stack c;
		displayStack(c);
	}
	std::cout << "----------> container <----------" << std::endl;
	{
		typedef stack<int, vector<int> > Stack;
		vector<int> v(5, 5);
		Stack c(v);
		c.push(4);
		displayStack(c);
	}
	typedef stack<int> Stack;
   std::cout << "----------> empty <----------" << std::endl;
	{
		Stack s;
		std::cout << "empty: " << s.empty() << std::endl;
		s.push(1);
		std::cout << "empty: " << s.empty() << std::endl;
		s.pop();
		std::cout << "size: " << s.size() << std::endl;
	}
	std::cout << "----------> size <----------" << std::endl;
	{
		Stack s;
		std::cout << "size: " << s.size() << std::endl;
		s.push(1);
		std::cout << "size: " << s.size() << std::endl;
		s.push(2);
		std::cout << "size: " << s.size() << std::endl;
		s.pop();
		std::cout << "size: " << s.size() << std::endl;
		s.pop();
		std::cout << "size: " << s.size() << std::endl;
	}
	std::cout << "----------> top <----------" << std::endl;
	{
		Stack s;
		s.push(1);
		std::cout << "top: " << s.top() << std::endl;
		s.push(2);
		std::cout << "top: " << s.top() << std::endl;
		s.pop();
		std::cout << "top: " << s.top() << std::endl;
		s.pop();
	}
   std::cout << "----------> push & pop <----------" << std::endl;
	{
		Stack s;
		s.push(1);
		s.push(2);
		s.pop();
		displayStack(s);
	}

	typedef stack<int> Stack;
	Stack c1 = ::basic();
	Stack c2 = ::basic();
	Stack c3 = ::basic();
	c3.push(6);
	Stack c4;
	c4.push(1);
	c4.push(2);
	c4.push(3);
	c4.push(5);
	c4.push(6);
   std::cout << "----------> = <----------" << std::endl;
	{
		Stack c = c3;
		displayStack(c);
		c = c4;
		displayStack(c);
	}
   std::cout << "----------> == <----------" << std::endl;
	std::cout << "c1 == c2: " << (c1 == c2) << std::endl;
	std::cout << "c1 == c3: " << (c1 == c3) << std::endl;
	std::cout << "c1 == c4: " << (c1 == c4) << std::endl;
	std::cout << "----------> != <----------" << std::endl;
	std::cout << "c1 != c2: " << (c1 != c2) << std::endl;
	std::cout << "c1 != c3: " << (c1 != c3) << std::endl;
	std::cout << "c1 != c4: " << (c1 != c4) << std::endl;
	std::cout << "----------> < <----------" << std::endl;
	std::cout << "c1 < c2: " << (c1 < c2) << std::endl;
	std::cout << "c1 < c3: " << (c1 < c3) << std::endl;
	std::cout << "c1 < c4: " << (c1 < c4) << std::endl;
	std::cout << "----------> > <----------" << std::endl;
	std::cout << "c1 > c2: " << (c1 > c2) << std::endl;
	std::cout << "c1 > c3: " << (c1 > c3) << std::endl;
	std::cout << "c1 > c4: " << (c1 > c4) << std::endl;
	std::cout << "----------> <= <----------" << std::endl;
	std::cout << "c1 <= c2: " << (c1 <= c2) << std::endl;
	std::cout << "c1 <= c3: " << (c1 <= c3) << std::endl;
	std::cout << "c1 <= c4: " << (c1 <= c4) << std::endl;
	std::cout << "----------> >= <----------" << std::endl;
	std::cout << "c1 >= c2: " << (c1 >= c2) << std::endl;
	std::cout << "c1 >= c3: " << (c1 >= c3) << std::endl;
	std::cout << "c1 >= c4: " << (c1 >= c4) << std::endl;
}