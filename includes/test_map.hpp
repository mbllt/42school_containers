#ifndef TEST_MAP_HPP
#define TEST_MAP_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "tests.hpp"
#include "map.hpp"

template<typename value>
class TestMap {

	private:


	public:

		TestMap() {}
		~TestMap() {}

		void test_general(std::ofstream& of, std::ofstream& myof) {
			of << "\n\n\nTEST-GENERAL ✅\n\n";
			myof << "\n\n\nTEST-GENERAL ✅\n\n";

			print_str(of, myof, "-------- constructors");
			
			print_str(of, myof, "-------- get_alloc()");

			print_str(of, myof, "-------- assign()");
		}

};

#endif