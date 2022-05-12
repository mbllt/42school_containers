#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tests.hpp"
#include "vector.hpp"

// default(int) and specialisation std::string vector<int>
template<typename Value>
class TestVector {

	private:

		template<typename T>
		void printVector(std::ofstream& out, T& vec) {

			out << "{ ";
			for (typename T::iterator it = vec.begin(); it != vec.end(); ++it){
				out << *it << " ";
			}
			out << "}\n";
		}

		void displayVectors(std::ofstream& of, std::vector<Value>& vec, std::ofstream& myof, ft::vector<Value>& myvec) {

			printVector(of, vec);
			printVector(myof, myvec);
		}

		void fill_vec(std::vector<Value>* vec, ft::vector<Value>* myvec) {	//int

			typename std::vector<Value>::iterator it =vec->begin();
			typename ft::vector<Value>::iterator myit = myvec->begin();

			for (size_t i = 0; i < vec->size(); ++i) {
				int val = rand() % 100;
				*it = val;
				*myit = val;
				++it;
				++myit;
			}
		}

		void test_it_arrow(std::ofstream& of, std::ofstream& myof) {(void)of;(void)myof;}

		void test_resize(std::ofstream& of, std::ofstream& myof) {
			print_str(of, myof, "-------- resize");
			std::vector<Value> empty;
			ft::vector<Value> myempty;
			displayVectors(of, empty, myof, myempty);

			empty.resize(2);
			myempty.resize(2);
			print_str(of, myof, "empty.resize(Value())");
			displayVectors(of, empty, myof, myempty);
			if (empty.size() == myempty.size())
				print_str(of, myof, "size change after resize : ok");
			else {
				of << "size change after resize : ok | l.300\n";
				myof << "size change after resize : koooo | l.300\n";
			}
			if (empty.capacity() == myempty.capacity())
				print_str(of, myof, "capacity change after resize : ok");
			else {
				of << "capacity change after resize : ok | l.300\n";
				myof << "capacity change after resize : koooo | l.300\n";
			}

			std::vector<Value> vec(10, Value());
			ft::vector<Value> myvec(10, Value());
			fill_vec(&vec, &myvec);
			displayVectors(of, vec, myof, myvec);

			vec.resize(5, Value());
			myvec.resize(5, Value());
			print_str(of, myof, "vec.resize(10, Value()) : smaller capacity");
			displayVectors(of, vec, myof, myvec);
			if (vec.size() == myvec.size())
				print_str(of, myof, "size change after resize : ok");
			else {
				of << "size change after resize : ok | l.300\n";
				myof << "size change after resize : koooo | l.300\n";
			}
			if (vec.capacity() == myvec.capacity())
				print_str(of, myof, "capacity change after resize : ok");
			else {
				of << "capacity change after resize : ok | l.300\n";
				myof << "capacity change after resize : koooo | l.300\n";
			}

			vec.resize(30, Value());
			myvec.resize(30, Value());
			print_str(of, myof, "vec.resize(30, Value()) : bigger capacity");
			displayVectors(of, vec, myof, myvec);
			if (vec.size() == myvec.size())
				print_str(of, myof, "size change after resize : ok");
			else {
				of << "size change after resize : ok | l.300\n";
				myof << "size change after resize : koooo | l.300\n";
			}
			if (vec.capacity() == myvec.capacity())
				print_str(of, myof, "capacity change after resize : ok");
			else {
				of << "capacity change after resize : ok | l.300\n";
				myof << "capacity change after resize : koooo | l.300\n";
			}
		}

		void test_push_back(std::ofstream& of, std::ofstream& myof) {
			print_str(of, myof, "-------- push_back");
			std::vector<Value> empty;
			ft::vector<Value> myempty;
			displayVectors(of, empty, myof, myempty);

			empty.push_back(Value());
			myempty.push_back(Value());
			print_str(of, myof, "empty.push_back(Value())");
			displayVectors(of, empty, myof, myempty);
			if (empty.size() == myempty.size())
				print_str(of, myof, "size change after push_back : ok");
			else {
				of << "size change after push_back : ok | l.300\n";
				myof << "size change after push_back : koooo | l.300\n";
			}
			if (empty.capacity() == myempty.capacity())
				print_str(of, myof, "capacity change after push_back : ok");
			else {
				of << "capacity change after push_back : ok | l.300\n";
				myof << "capacity change after push_back : koooo | l.300\n";
			}
			
			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);
			displayVectors(of, vec, myof, myvec);

			vec.push_back(Value());
			myvec.push_back(Value());
			vec.push_back(Value());
			myvec.push_back(Value());
			print_str(of, myof, "vec.push_back(Value())");
			displayVectors(of, vec, myof, myvec);
			if (vec.size() == myvec.size())
				print_str(of, myof, "size change after push_back : ok");
			else {
				of << "size change after push_back : ok | l.300\n";
				myof << "size change after push_back : koooo | l.300\n";
			}
			if (vec.capacity() == myvec.capacity())
				print_str(of, myof, "capacity change after push_back : ok");
			else {
				of << "capacity change after push_back : ok | l.300\n";
				myof << "capacity change after push_back : koooo | l.300\n";
			}
		}

		void test_pop_back(std::ofstream& of, std::ofstream& myof) {
			print_str(of, myof, "-------- pop_back");
			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);
			displayVectors(of, vec, myof, myvec);

			vec.pop_back();
			myvec.pop_back();
			print_str(of, myof, "vec.pop_back())");
			displayVectors(of, vec, myof, myvec);
			if (vec.size() == myvec.size())
				print_str(of, myof, "size change after pop_back : ok");
			else {
				of << "size change after pop_back : ok | l.300\n";
				myof << "size change after pop_back : koooo | l.300\n";
			}
			if (vec.capacity() == myvec.capacity())
				print_str(of, myof, "capacity change after pop_back : ok");
			else {
				of << "capacity change after pop_back : ok | l.300\n";
				myof << "capacity change after pop_back : koooo | l.300\n";
			}
		}

		void test_swap(std::ofstream& of, std::ofstream& myof) {
			print_str(of, myof, "-------- swap");
			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);
			print_str(of, myof, "vec ");
			displayVectors(of, vec, myof, myvec);

			std::vector<Value> other(24, Value());
			ft::vector<Value> myother(24, Value());
			fill_vec(&other, &myother);
			print_str(of, myof, "other ");
			displayVectors(of, other, myof, myother);

			typename std::vector<Value>::iterator it_start_vec = vec.begin() + 3;
			typename ft::vector<Value>::iterator myit_start_vec = myvec.begin() + 3;
			typename std::vector<Value>::iterator it_start_other = other.begin() + 3;
			typename ft::vector<Value>::iterator myit_start_other = myother.begin() + 3;

			of << "it de vec au debut :" << *it_start_vec << "\n" << "it de other au debut :" << *it_start_other << "\n";
			myof << "it de vec au debut :" << *myit_start_vec << "\n" << "it de other au debut :" << *myit_start_other << "\n";

			std::swap(vec, other);
			ft::swap(myvec, myother);
			print_str(of, myof, "vec.swap(other) : vec smaller than other");
			print_str(of, myof, "vec ");
			displayVectors(of, vec, myof, myvec);
			print_str(of, myof, "other ");
			displayVectors(of, other, myof, myother);

			of << "it de vec a la fin :" << *it_start_vec << "\n" << "it de other a la fin :" << *it_start_other << "\n";
			myof << "it de vec a la fin :" << *myit_start_vec << "\n" << "it de other a la fin :" << *myit_start_other << "\n";

			std::vector<Value> third(5, Value());
			ft::vector<Value> mythird(5, Value());
			fill_vec(&third, &mythird);
			print_str(of, myof, "third ");
			displayVectors(of, third, myof, mythird);

			other.swap(third);
			myother.swap(mythird);
			print_str(of, myof, "other.swap(third) : other bigger than third");
			print_str(of, myof, "other ");
			displayVectors(of, other, myof, myother);
			print_str(of, myof, "third ");
			displayVectors(of, third, myof, mythird);
		}

		void test_clear(std::ofstream& of, std::ofstream& myof) {
			print_str(of, myof, "-------- clear");
			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);

			print_str(of, myof, "before clear :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" <<  vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			vec.clear();
			myvec.clear();

			print_str(of, myof, "after clear : ");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			vec.push_back(Value());
			myvec.push_back(Value());
			print_str(of, myof, "after one pushback :");
			displayVectors(of, vec, myof, myvec);
		}

		void test_erase(std::ofstream& of, std::ofstream& myof) {
			print_str(of, myof, "-------- erase");
			std::vector<Value> vec(10, Value());
			ft::vector<Value> myvec(10, Value());
			fill_vec(&vec, &myvec);
			typename std::vector<Value>::iterator it = vec.begin();
			typename ft::vector<Value>::iterator myit = myvec.begin();

			print_str(of, myof, "before erase begin() :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			typename std::vector<Value>::iterator ret = vec.erase(it);
			typename ft::vector<Value>::iterator myret = myvec.erase(myit);

			print_str(of, myof, "after erase begin() :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			print_str(of, myof, "ret erase :");
			of << *ret << "\n";
			myof << *myret << "\n";

			print_str(of, myof, "before erase(begin(), begin() + 5) :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			ret = vec.erase(it, it + 5);
			myret = myvec.erase(myit, myit + 5);

			print_str(of, myof, "after erase(begin(), begin() + 5) :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			print_str(of, myof, "ret erase :");
			of << *ret << "\n";
			myof << *myret << "\n";
		}

		void test_insert(std::ofstream& of, std::ofstream& myof) {
			print_str(of, myof, "-------- insert");

			std::vector<Value> empty;
			ft::vector<Value> myempty;
			displayVectors(of, empty, myof, myempty);

			empty.insert(empty.begin(), Value());
			myempty.insert(myempty.begin(), Value());
			print_str(of, myof, "empty.insert(Value())");
			displayVectors(of, empty, myof, myempty);
			if (empty.size() == myempty.size())
				print_str(of, myof, "size change after insert : ok");
			else {
				of << "size change after insert : ok | l.300\n";
				myof << "size change after insert : koooo | l.300\n";
			}
			if (empty.capacity() == myempty.capacity())
				print_str(of, myof, "capacity change after insert : ok");
			else {
				of << "capacity change after insert : ok | l.300\n";
				myof << "capacity change after insert : koooo | l.300\n";
			}

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);

			print_str(of, myof, "before insert(begin(), 3, Value()) :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			typename std::vector<Value>::iterator it = vec.begin();
			typename ft::vector<Value>::iterator myit = myvec.begin();
			++it;
			++myit;
			vec.insert(it, 3, Value());
			myvec.insert(myit, 3, Value());

			print_str(of, myof, "after insert(begin(), 3, Value()) :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

			typename std::vector<Value>::iterator ret = vec.insert(vec.begin(), Value());
			typename ft::vector<Value>::iterator myret = myvec.insert(myvec.begin(), Value());

			if (*ret == *myret)
				print_str(of, myof, "ret de insert : ok");
			else {
				of << "ret de insert : ok | l.300\n";
				myof << "ret de insert : koooo | l.300\n";
			}

			print_str(of, myof, "before insert(empty.begin(), vec.begin(), vec.end()) :");
			displayVectors(of, empty, myof, myempty);
			of << "size :" << empty.size() << " - capacity :" << empty.capacity() << "\n";
			myof << "size :" << myempty.size() << " - capacity :" << myempty.capacity() << "\n";

			empty.insert(empty.begin(), vec.begin(), vec.end());
			myempty.insert(myempty.begin(), vec.begin(), vec.end());

			print_str(of, myof, "after insert(empty.begin(), vec.begin(), vec.end()) :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << empty.size() << " - capacity :" << empty.capacity() << "\n";
			myof << "size :" << myempty.size() << " - capacity :" << myempty.capacity() << "\n";

			std::vector<Value> emptyRange;
			ft::vector<Value> myemptyRange;

			print_str(of, myof, "before after insert(begin(), 3, Value()) :");
			displayVectors(of, emptyRange, myof, myemptyRange);
			of << "size :" << emptyRange.size() << " - capacity :" << emptyRange.capacity() << "\n";
			myof << "size :" << myemptyRange.size() << " - capacity :" << myemptyRange.capacity() << "\n";

			emptyRange.insert(emptyRange.begin(), 3, Value());
			myemptyRange.insert(myemptyRange.begin(), 3, Value());

			print_str(of, myof, "after insert(begin(), 3, Value()) :");
			displayVectors(of, vec, myof, myvec);
			of << "size :" << emptyRange.size() << " - capacity :" << emptyRange.capacity() << "\n";
			myof << "size :" << myemptyRange.size() << " - capacity :" << myemptyRange.capacity() << "\n";
		}

	public:

		TestVector() {}
		~TestVector() {}

		void test_general(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-general ✅\n";
			myof << "\ntest-general ✅\n";

			print_str(of, myof, "-------- constructors");
			print_str(of, myof, "vec(n, value())");
			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			displayVectors(of, vec, myof, myvec);

			print_str(of, myof, "vec default");
			std::vector<Value> bis;
			ft::vector<Value> mybis;

			bis.resize(10, Value());
			mybis.resize(10, Value());
			fill_vec(&bis, &mybis);
			displayVectors(of, bis, myof, mybis);

			print_str(of, myof, "vec(copy)");
			std::vector<Value> quatre(vec);
			ft::vector<Value> myquatre(myvec);
			displayVectors(of, quatre, myof, myquatre);
	
			print_str(of, myof, "vec range");
			std::vector<Value> range(bis.begin(), bis.end());
			ft::vector<Value> myrange(bis.begin(), bis.end());
			displayVectors(of, range, myof, myrange);

			std::vector<Value> rangebis(bis.begin(), bis.begin());
			ft::vector<Value> myrangebis(bis.begin(), bis.begin());
			displayVectors(of, rangebis, myof, myrangebis);

			std::vector<Value> empty;
			std::vector<Value> rangetres(empty.begin(), empty.end());
			ft::vector<Value> myrangetres(empty.begin(), empty.end());
			displayVectors(of, rangetres, myof, myrangetres);
// not supposed to work
			// std::vector<Value> rangenotworking(bis.begin(), 32);
			// ft::vector<Value> myrangenotworking(bis.begin(), 1);

			print_str(of, myof, "-------- get_alloc()");
			if (vec.get_allocator() == myvec.get_allocator())
				print_str(of, myof, "vec.get_allocator() == myvec.get_allocator() : ok");
			else {
				of << "vec.get_allocator() == myvec.get_allocator() : ok | l.300\n";
				myof << "vec.get_allocator() == myvec.get_allocator() : koooo work | l.300\n";
			}

			print_str(of, myof, "-------- assign()");
			std::vector<Value> assign;
			ft::vector<Value> myassign;
			fill_vec(&assign, &myassign);

			print_str(of, myof, "print bis :");
			displayVectors(of, bis, myof, mybis);
			print_str(of, myof, "before assign(bis.begin(), bis.end()) :");
			displayVectors(of, assign, myof, myassign);
			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

			assign.assign(3, Value());
			myassign.assign(3, Value());

			print_str(of, myof, "after assign(bis.begin(), bis.end()) :");
			displayVectors(of, assign, myof, myassign);
			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

			std::vector<Value> assignbis(2, Value());
			ft::vector<Value> myassignbis(2, Value());
			fill_vec(&assign, &myassign);

			print_str(of, myof, "before assign(assignbis.begin(), assignbis.end()) :");
			displayVectors(of, assign, myof, myassign);
			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

			assign.assign(assignbis.begin(), assignbis.end());
			myassign.assign(myassignbis.begin(), myassignbis.end());

			print_str(of, myof, "after assign(assignbis.begin(), assignbis.end()) :");
			displayVectors(of, assign, myof, myassign);
			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

		}

		void test_operators(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-operators ✅\n";
			myof << "\ntest-operators ✅\n";

			std::vector<Value> equal(20,  Value());
			std::vector<Value> test(equal);
			ft::vector<Value> myequal(20,  Value());
			ft::vector<Value> mytest(myequal);

			if (equal  == test)
				of << "equal == test :" << (equal == test) << "\n";
			if (myequal == mytest)
				myof << "equal == test :" << (myequal == mytest) << "\n";

			if (equal == test)

		
			for (int i = 0;i < 10;++i) {
		
				std::vector<Value> vec(20,  Value());
				ft::vector<Value> myvec(20,  Value());
				fill_vec(&vec, &myvec);
				std::vector<Value> tmp(20,  Value());
				ft::vector<Value> mytmp(20,  Value());
				fill_vec(&tmp, &mytmp);
		
			// !=
				if (myvec != mytmp) {
					// print_str(of, myof, "op !=");
					print_str(of, myof, "myvec != mytmp : ok");
				}
				else if (vec != tmp) {
					of << "myvec != mytmp : ok\n";
					myof << "myvec != mytmp : koooo\n";
				}
		
			// <
				if (myvec < mytmp) {
					print_str(of, myof, "myvec < mytmp : ok");
				}
				else if (vec < tmp) {
					of << "myvec < mytmp : ok\n";
					myof << "myvec < mytmp : koooo\n";
				}
		
			// >
				if (myvec > mytmp) {
					print_str(of, myof, "myvec > mytmp : ok");
				}
				else if (vec > tmp) {
					of << "myvec > mytmp : ok\n";
					myof << "myvec > mytmp : koooo\n";
				}
			}
		}

		void test_reverse_iterators(std::ofstream& of, std::ofstream& myof) {

			of << "\ntest-reverse_iterators ✅\n";
			myof << "\ntest-reverse_iterators ✅\n";

			std::vector<Value> vec(10, Value());
			ft::vector<Value> myvec(10, Value());
			fill_vec(&vec, &myvec);
			displayVectors(of, vec, myof, myvec);

			typename std::vector<Value>::reverse_iterator it = vec.rbegin();
			typename ft::vector<Value>::reverse_iterator myit = myvec.rbegin();

			//	++(int)
			of << "it :" << *it << "| ";
			myof << "it :" << *myit << "| ";
			it++;
			myit++;
			of << "it++ :" << *it << "\n";
			myof << "it++ :" << *myit << "\n";

			//	--(int)
			of << "it : " << *it << "| ";
			myof << "it : " << *myit << "| ";
			it--;
			myit--;
			of << "it-- : " << *it << "\n";
			myof << "it-- : " << *myit << "\n";

			//	++()
			of << "it :" << *it << "| ";
			myof << "it :" << *myit << "| ";
			++it;
			++myit;
			of << "++it :" << *it << "\n";
			myof << "++it :" << *myit << "\n";

			//	--()
			of << "it : " << *it << " | ";
			myof << "it : " << *myit << " | ";
			--it;
			--myit;
			of << "--it :" << *it << "\n";
			myof << "--it :" << *myit << "\n";

			// +(int)
			it = it + 1;
			it = 1 + it;
			of << "it = it + 1 :" << *it << "\n";

			myit = myit + 1;
			myit = 1 + myit;
			myof << "it = it + 1 :" << *myit << "\n";

			// -(int)
			it = it - 1;
			of << "it = it - 1 :" << *it << "\n";

			myit = myit - 1;
			myof << "it = it - 1 :" << *myit << "\n";

			// +=(it)
			it += 2;
			of << "it += 2 :" << *it << "\n";

			myit += 2;
			myof << "it += 2 :" << *myit << "\n";

			// -=(int)
			it -= 2;
			of << "it -= 2 :" << *it << "\n";

			myit -= 2;
			myof << "it -= 2 :" << *myit << "\n";

			// []
			it = vec.rbegin();
			myit = myvec.rbegin();

			of << "it[0] :" << it[0] << " | it[3] :" << it[3] << "\n";
			myof << "it[0] :" << myit[0] << " | it[3] :" << myit[3] << "\n";

			typename std::vector<Value>::reverse_iterator itit = vec.rbegin();
			typename std::vector<Value>::reverse_iterator tmp = itit + 3;
			typename ft::vector<Value>::reverse_iterator myitit = myvec.rbegin();
			typename ft::vector<Value>::reverse_iterator mytmp = myitit + 3;

			// -(it)
			int i = *itit - *tmp;
			of << "int i = itit - tmp :" << i << "\n";

			int myi = *myitit - *mytmp;
			myof << "int i = itit - tmp :" << myi << "\n";

			for (int i = 0; i < 5; ++i) {
			
				srand (time(NULL));
				size_t nbr = rand() % (vec.size() - 1);
				size_t nbrbis = rand() % (vec.size() - 1);
				typename std::vector<Value>::reverse_iterator ittest = vec.rbegin();
				*ittest = vec[nbr];
				typename std::vector<Value>::reverse_iterator ittestbis = vec.rbegin();
				*ittestbis = vec[nbrbis];

				size_t mynbr = rand() % (myvec.size() - 1);
				size_t mynbrbis = rand() % (myvec.size() - 1);
				typename ft::vector<Value>::reverse_iterator myittest = myvec.rbegin();
				*myittest = myvec[mynbr];
				typename ft::vector<Value>::reverse_iterator myittestbis = myvec.rbegin();
				*myittestbis = myvec[mynbrbis];

				//	==
				if (*ittest == *ittestbis && *myittest == *myittestbis)
					print_str(of, myof, "*ittest == *ittestbis : ok");
				else if (*ittest == *ittestbis) {
					of << "*ittest == *ittestbis : ok\n";
			 		myof << "*ittest == *ittestbis : koooo\n";}

				//	!=
				if (*ittest != *ittestbis && *myittest != *myittestbis)
					print_str(of, myof, "*ittest != *ittestbis : ok");
				else if (*ittest != *ittestbis) {
					of << "*ittest != *ittestbis : ok\n";
			 		myof << "*ittest != *ittestbis : koooo\n";}

				//	<
				if (*ittest < *ittestbis && *myittest < *myittestbis)
					print_str(of, myof, "*ittest < *ittestbis : ok");
				else if (*ittest < *ittestbis) {
					of << "*ittest < *ittestbis : ok\n";
			 		myof << "*ittest < *ittestbis : koooo\n";}

				//	<=
				if (*ittest <= *ittestbis && *myittest <= *myittestbis)
					print_str(of, myof, "*ittest <= *ittestbis : ok");
				else if (*ittest <= *ittestbis) {
					of << "*ittest <= *ittestbis : ok\n";
			 		myof << "*ittest <= *ittestbis : koooo\n";}

				//	>
				if (*ittest > *ittestbis && *myittest > *myittestbis)
					print_str(of, myof, "*ittest > *ittestbis : ok");
				else if (*ittest > *ittestbis) {
					of << "*ittest > *ittestbis : ok\n";
			 		myof << "*ittest > *ittestbis : koooo\n";}

				//	>=
				if (*ittest >= *ittestbis && *myittest >= *myittestbis)
					print_str(of, myof, "*ittest >= *ittestbis : ok");
				else if (*ittest >= *ittestbis) {
					of << "*ittest >= *ittestbis : ok\n";
					myof << "*ittest >= *ittestbis : koooo\n";}
			}
			test_it_arrow(of, myof);
		}


		void test_iterators(std::ofstream& of, std::ofstream& myof) {
			of << "\ntest-iterators ✅\n";
			myof << "\ntest-iterators ✅\n";

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);
			displayVectors(of, vec, myof, myvec);

			typename std::vector<Value>::iterator it = vec.begin();
			typename ft::vector<Value>::iterator myit = myvec.begin();

			//	++(int)
			of << "it :" << *it << "| ";
			myof << "it :" << *myit << "| ";
			it++;
			myit++;
			of << "it++ :" << *it << "\n";
			myof << "it++ :" << *myit << "\n";

			//	--(int)
			of << "it : " << *it << "| ";
			myof << "it : " << *myit << "| ";
			it--;
			myit--;
			of << "it-- : " << *it << "\n";
			myof << "it-- : " << *myit << "\n";

			//	++()
			of << "it :" << *it << "| ";
			myof << "it :" << *myit << "| ";
			++it;
			++myit;
			of << "++it :" << *it << "\n";
			myof << "++it :" << *myit << "\n";

			//	--()
			of << "it : " << *it << " | ";
			myof << "it : " << *myit << " | ";
			--it;
			--myit;
			of << "--it :" << *it << "\n";
			myof << "--it :" << *myit << "\n";

			// +(int)
			it = it + 1;
			it = 1 + it;
			of << "it = it + 1 :" << *it << "\n";

			myit = myit + 1;
			myit = 1 + myit;
			myof << "it = it + 1 :" << *myit << "\n";

			// -(int)
			it = it - 1;
			of << "it = it - 1 :" << *it << "\n";

			myit = myit - 1;
			myof << "it = it - 1 :" << *myit << "\n";

			// +=(it)
			it += 2;
			of << "it += 2 :" << *it << "\n";

			myit += 2;
			myof << "it += 2 :" << *myit << "\n";

			// -=(int)
			it -= 2;
			of << "it -= 2 :" << *it << "\n";

			myit -= 2;
			myof << "it -= 2 :" << *myit << "\n";

			// []
			it = vec.begin();
			myit = myvec.begin();

			of << "it[0] :" << it[0] << " | it[3] :" << it[3] << "\n";
			myof << "it[0] :" << myit[0] << " | it[3] :" << myit[3] << "\n";

			typename std::vector<Value>::iterator itit = vec.begin();
			typename std::vector<Value>::iterator tmp = itit + 3;
			typename ft::vector<Value>::iterator myitit = myvec.begin();
			typename ft::vector<Value>::iterator mytmp = myitit + 3;

			// -(it)
			int i = itit - tmp;
			of << "int i = itit - tmp :" << i << "\n";

			int myi = myitit - mytmp;
			myof << "int i = itit - tmp :" << myi << "\n";

			for (int i = 0; i < 5; ++i) {
			
				srand (time(NULL));
				size_t nbr = rand() % (vec.size() - 1);
				size_t nbrbis = rand() % (vec.size() - 1);
				typename std::vector<Value>::iterator ittest = vec.begin();
				*ittest = vec[nbr];
				typename std::vector<Value>::iterator ittestbis = vec.begin();
				*ittestbis = vec[nbrbis];

				size_t mynbr = rand() % (myvec.size() - 1);
				size_t mynbrbis = rand() % (myvec.size() - 1);
				typename ft::vector<Value>::iterator myittest = myvec.begin();
				*myittest = myvec[mynbr];
				typename ft::vector<Value>::iterator myittestbis = myvec.begin();
				*myittestbis = myvec[mynbrbis];

				//	==
				if (*ittest == *ittestbis && *myittest == *myittestbis)
					print_str(of, myof, "*ittest == *ittestbis : ok");
				else if (*ittest == *ittestbis) {
					of << "*ittest == *ittestbis : ok\n";
			 		myof << "*ittest == *ittestbis : koooo\n";}

				//	!=
				if (*ittest != *ittestbis && *myittest != *myittestbis)
					print_str(of, myof, "*ittest != *ittestbis : ok");
				else if (*ittest != *ittestbis) {
					of << "*ittest != *ittestbis : ok\n";
			 		myof << "*ittest != *ittestbis : koooo\n";}

				//	<
				if (*ittest < *ittestbis && *myittest < *myittestbis)
					print_str(of, myof, "*ittest < *ittestbis : ok");
				else if (*ittest < *ittestbis) {
					of << "*ittest < *ittestbis : ok\n";
			 		myof << "*ittest < *ittestbis : koooo\n";}

				//	<=
				if (*ittest <= *ittestbis && *myittest <= *myittestbis)
					print_str(of, myof, "*ittest <= *ittestbis : ok");
				else if (*ittest <= *ittestbis) {
					of << "*ittest <= *ittestbis : ok\n";
			 		myof << "*ittest <= *ittestbis : koooo\n";}

				//	>
				if (*ittest > *ittestbis && *myittest > *myittestbis)
					print_str(of, myof, "*ittest > *ittestbis : ok");
				else if (*ittest > *ittestbis) {
					of << "*ittest > *ittestbis : ok\n";
			 		myof << "*ittest > *ittestbis : koooo\n";}

				//	>=
				if (*ittest >= *ittestbis && *myittest >= *myittestbis)
					print_str(of, myof, "*ittest >= *ittestbis : ok");
				else if (*ittest >= *ittestbis) {
					of << "*ittest >= *ittestbis : ok\n";
					myof << "*ittest >= *ittestbis : koooo\n";}
			}
			test_it_arrow(of, myof);
		}

		void test_capacity(std::ofstream& of, std::ofstream& myof) {
			
			of << "\ntest-capacity ✅\n";
			myof << "\ntest-capacity ✅\n";

			std::vector<Value> emptyvec;
			ft::vector<Value> myemptyvec;

			// empty
			if (emptyvec.empty() == myemptyvec.empty())
				print_str(of, myof, "emptyvec.empty() == myemptyvec.empty() : ok");
			else {
				of << "emptyvec.empty() == myemptyvec.empty() : ok | l.300\n";
				myof << "emptyvec.empty() == myemptyvec.empty() : koooo work | l.300\n";
			}

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);

			// size
			if (vec.size() == myvec.size())
				print_str(of, myof, "vec.size() == myvec.size() : ok");
			else {
				of << "size :" << vec.size() << "\n";
				myof << "size :" << myvec.size() << "\n";
			}

			// max_size
			if (vec.max_size() == myvec.max_size())
				print_str(of, myof, "vec.max_size() == myvec.max_size() : ok");
			else {
				of << "vec.max_size() == myvec.max_size() : ok | l.300\n";
				myof << "vec.max_size() == myvec.max_size() : koooo work | l.300\n";
			}

			// capacity
			if (vec.capacity() == myvec.capacity())
				print_str(of, myof, "vec.capacity() == myvec.capacity() : ok");
			else {
				of << "capacity test - size : " << vec.size() << " - capacity : " << vec.capacity() << "\n";
				myof << "capacity test - size : " << myvec.size() << " - capacity : " << myvec.capacity() << "\n";
			}

			// reserve
			vec.reserve(25);
			myvec.reserve(25);
			if (vec.capacity() == myvec.capacity())
				print_str(of, myof, "vec.reserve : ok");
			else {
				of << "reserve test - size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
				myof << "reserve test - size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";
			}
		}

		void test_accessors(std::ofstream& of, std::ofstream& myof) {
			
			of << "\ntest-accessors ✅\n";
			myof << "\ntest-accessors ✅\n";

			std::vector<Value> vec(20, Value());
			ft::vector<Value> myvec(20, Value());
			fill_vec(&vec, &myvec);
			displayVectors(of, vec, myof, myvec);

			// []
			if (vec[0] == myvec[0])
				print_str(of, myof, "vec[0] == myvec[0] : ok");
			else {
				of << "vec[0] == myvec[0] : ok | l.300\n";
				myof << "vec[0] == myvec[0] : koooo | l.300\n";
			}
			
			// at
			if (vec.at(0) == myvec.at(0))
				print_str(of, myof, "vec.at() == myvec.at() : ok");
			else {
				of << "vec.at(0) == myvec.at(0) : ok | l.300\n";
				myof << "vec.at(0) == myvec.at(0) : koooo | l.300\n";
			}

			// front
			if (vec.front() == myvec.front())
				print_str(of, myof, "vec.front() == myvec.front() : ok");
			else {
				of << "vec.front() == myvec.front() : ok | l.300\n";
				myof << "vec.front() == myvec.front() : koooo | l.300\n";
			}

			// back
			if (vec.back() == myvec.back())
				print_str(of, myof, "vec.back() == myvec.back() : ok");
			else {
				of << "vec.back() == myvec.back() : ok | l.300\n";
				myof << "vec.back() == myvec.back() : koooo | l.300\n";
			}
		}

		void test_modifiers(std::ofstream& of, std::ofstream& myof) {
			
			of << "\ntest-mofifiers ✅\n";
			myof << "\ntest-mofifiers ✅\n";

			test_resize(of, myof);
			test_push_back(of, myof);
			test_pop_back(of, myof);
			test_swap(of, myof);
			test_clear(of, myof);
			test_erase(of, myof);
			test_insert(of, myof);
		}

		void test_const(std::ofstream& of, std::ofstream& myof) {
			of << "\ntest-const ✅\n";
			myof << "\ntest-const ✅\n";

			const std::vector<Value> vec(20, Value());
			const ft::vector<Value> myvec(20, Value());

//should not compile
			// vec[0] = 1;
			// myvec[0] = 1;

//should not compile
			// typename std::vector<Value>::iterator it = vec.begin();
			// (void) it;
			// typename ft::vector<Value>::iterator myit = myvec.begin();
			// (void) myit;

			typename std::vector<const Value>::iterator it = vec.begin();
			typename ft::vector<const Value>::iterator myit = myvec.begin();

			typename std::vector<Value>::const_iterator itconst = vec.begin();
			typename ft::vector<Value>::const_iterator myitconst = myvec.begin();

			++it;
			++myit;
			++itconst;
			++myitconst;

//should not compile
			// it = Value();
			// myit = Value();
			// itconst = Value();
			// myitconst = Value();

//should not compile
			// vec.clear();
			// myvec.clear();
			// vec.reserve(10);
			// myvec.clear();

			of << "size of vec :" << vec.size() << "\n";
			myof << "size of vec :" << myvec.size() << "\n";
			of << "capacity of vec :" << vec.capacity() << "\n";
			myof << "capacity of vec :" << myvec.capacity() << "\n";
			of << "vec.at(10) :" << vec.at(10) << "\n";
			myof << "vec.at(10) :" << myvec.at(10) << "\n";
			if (vec.back() == myvec.back())
				print_str(of, myof, "operator == on back() compile");

			std::vector<Value> const vecconst(20, Value());
			ft::vector<Value> const myvecconst(20, Value());

			if (vec  == vecconst)
				of << "vec == vecconst :" << (vec.begin() == vecconst.begin()) << "\n";
			if (myvec == myvecconst)
				myof << "vec == vecconst :" << (myvec.begin() == myvecconst.begin()) << "\n";

			if (vec.begin() == vecconst.begin())
				of << "vec.begin() == vecconst.begin() :" << (vec.begin() == vecconst.begin()) << "\n";
			if (myvec.begin() == myvecconst.begin())
				myof << "vec.begin() == vecconst.begin() :" << (myvec.begin() == myvecconst.begin()) << "\n";

			typename std::vector<Value>::const_iterator cit = vecconst.begin();
			while (cit != vecconst.end())
				++cit;

			typename ft::vector<Value>::const_iterator mycit = myvecconst.begin();
			while (mycit != myvecconst.end())
				++mycit;
		}
};

template<>		//function specilization
void TestVector<std::string>::fill_vec(std::vector<std::string>* vec, ft::vector<std::string>* myvec) {

	std::vector<std::string>::iterator it = vec->begin();
	ft::vector<std::string>::iterator myit = myvec->begin();

	std::string str[10] = { "test", "pop", "essay", "beeze", "youhou",
								"orange", "blue", "black", "sun", "best" };
	for (size_t i = 0; i < vec->size(); ++i) {
		int val = rand() % 10;
		*it = str[val];
		*myit = str[val];
		++it;
		++myit;
	}
}

template<>
void TestVector<std::string>::test_it_arrow(std::ofstream& of, std::ofstream& myof) {

	// ->
	std::vector<std::string> test(4, "pop");
	std::vector<std::string>::iterator ittest = test.begin();
	if (!strcmp(ittest->c_str(), "pop"))
		of << "test -> ok \n";
	else
		of << "test -> koooo \n";

	ft::vector<std::string> mytest(4, "pop");
	ft::vector<std::string>::iterator myittest = mytest.begin();
	if (!strcmp(myittest->c_str(), "pop"))
		myof << "test -> ok \n";
	else
		myof << "test -> koooo \n";
}

template<typename T, class Alloc>
bool		operator==(const ft::vector<T, Alloc> & src, const std::vector<T, Alloc> & cmp) {
				if (src.size() != cmp.size())
					return false;
				typename ft::vector<T>::const_iterator it = src.begin();
				typename std::vector<T>::const_iterator itbis = cmp.begin();
				while(it != src.end()) {
					if (itbis == cmp.end() || *it != *itbis)
						return false;
					++it;
					++itbis;
				}
				return true;
			}

template<typename T, class Alloc>
bool		operator==(const std::vector<T, Alloc> & src, const ft::vector<T, Alloc> & cmp) {
				if (src.size() != cmp.size())
					return false;
				typename std::vector<T>::const_iterator it = src.begin();
				typename ft::vector<T>::const_iterator itbis = cmp.begin();
				while(it != src.end()) {
					if (itbis == cmp.end() || *it != *itbis)
						return false;
					++it;
					++itbis;
				}
				return true;
			}

#endif