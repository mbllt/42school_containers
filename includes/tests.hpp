#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "vector.hpp"


// class Myclass {
// 	private:
// 		void _delete() {delete test;}

// 	public:
// 		Myclass() {test = new int;*test = 0;}
// 		~Myclass() {_delete();}

// 		Myclass & operator=(int val) {
// 			*test = val;
// 			return *this;
// 		}
// 		int *test;
// };

// std::ostream& operator<<(std::ostream&o, Myclass const & src) {
// 	o << *(src.test);
// 	return o;
// }

void testVector(void);
void print_str(std::ofstream& of, std::ofstream& myof, std::string str);
void print_line(std::ofstream& of, std::ofstream& myof, unsigned int n);

#endif