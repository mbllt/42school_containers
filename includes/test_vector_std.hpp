#pragma once
#ifdef MINE
  #include "vector.hpp"
  using namespace ft;
#else
  #include <vector>
  using namespace std;
#endif
#include "tests.hpp"


// default(int) and specialisation string
// template<typename value>
// class TestVector {

// 	private:

// 		void displayVectors(ofstream& of, vector<value>& vec, ofstream& myof, vector<value>& myvec) {

// 			of << "{ ";
// 			for (typename vector<value>::iterator it = vec.begin(); it != vec.end(); ++it){
// 				of << *it << " ";
// 			}
// 			of << "}\n";
// 			myof << "{ ";
// 			for (typename vector<value>::iterator it = myvec.begin(); it != myvec.end(); ++it){
// 				myof << *it << " ";
// 			}
// 			myof << "}\n";
// 		}

// 		void fill_vec(vector<value>* vec, vector<value>* myvec) {

// 			typename vector<value>::iterator it =vec->begin();
// 			typename vector<value>::iterator myit = myvec->begin();

// 			for (size_t i = 0; i < vec->size(); ++i) {
// 				int val = rand() % 100;
// 				*it = val;
// 				*myit = val;
// 				++it;
// 				++myit;
// 			}
// 		}

// 		void test_it_arrow(ofstream& of, ofstream& myof) {(void)of;(void)myof;}

// 		void test_resize(ofstream& of, ofstream& myof) {
// 			print_str(of, myof, "-------- resize");
// 			vector<value> empty;
// 			vector<value> myempty;
// 			displayVectors(of, empty, myof, myempty);

// 			empty.resize(2);
// 			myempty.resize(2);
// 			print_str(of, myof, "empty.resize(value())");
// 			displayVectors(of, empty, myof, myempty);
// 			if (empty.size() == myempty.size())
// 				print_str(of, myof, "size change after resize : ok");
// 			else {
// 				of << "size change after resize : ok | l.300\n";
// 				myof << "size change after resize : koooo | l.300\n";
// 			}
// 			if (empty.capacity() == myempty.capacity())
// 				print_str(of, myof, "capacity change after resize : ok");
// 			else {
// 				of << "capacity change after resize : ok | l.300\n";
// 				myof << "capacity change after resize : koooo | l.300\n";
// 			}

// 			vector<value> vec(10, value());
// 			vector<value> myvec(10, value());
// 			fill_vec(&vec, &myvec);
// 			displayVectors(of, vec, myof, myvec);

// 			vec.resize(5, value());
// 			myvec.resize(5, value());
// 			print_str(of, myof, "vec.resize(10, value()) : smaller capacity");
// 			displayVectors(of, vec, myof, myvec);
// 			if (vec.size() == myvec.size())
// 				print_str(of, myof, "size change after resize : ok");
// 			else {
// 				of << "size change after resize : ok | l.300\n";
// 				myof << "size change after resize : koooo | l.300\n";
// 			}
// 			if (vec.capacity() == myvec.capacity())
// 				print_str(of, myof, "capacity change after resize : ok");
// 			else {
// 				of << "capacity change after resize : ok | l.300\n";
// 				myof << "capacity change after resize : koooo | l.300\n";
// 			}

// 			vec.resize(30, value());
// 			myvec.resize(30, value());
// 			print_str(of, myof, "vec.resize(30, value()) : bigger capacity");
// 			displayVectors(of, vec, myof, myvec);
// 			if (vec.size() == myvec.size())
// 				print_str(of, myof, "size change after resize : ok");
// 			else {
// 				of << "size change after resize : ok | l.300\n";
// 				myof << "size change after resize : koooo | l.300\n";
// 			}
// 			if (vec.capacity() == myvec.capacity())
// 				print_str(of, myof, "capacity change after resize : ok");
// 			else {
// 				of << "capacity change after resize : ok | l.300\n";
// 				myof << "capacity change after resize : koooo | l.300\n";
// 			}
// 		}

// 		void test_push_back(ofstream& of, ofstream& myof) {
// 			print_str(of, myof, "-------- push_back");
// 			vector<value> empty;
// 			vector<value> myempty;
// 			displayVectors(of, empty, myof, myempty);

// 			empty.push_back(value());
// 			myempty.push_back(value());
// 			print_str(of, myof, "empty.push_back(value())");
// 			displayVectors(of, empty, myof, myempty);
// 			if (empty.size() == myempty.size())
// 				print_str(of, myof, "size change after push_back : ok");
// 			else {
// 				of << "size change after push_back : ok | l.300\n";
// 				myof << "size change after push_back : koooo | l.300\n";
// 			}
// 			if (empty.capacity() == myempty.capacity())
// 				print_str(of, myof, "capacity change after push_back : ok");
// 			else {
// 				of << "capacity change after push_back : ok | l.300\n";
// 				myof << "capacity change after push_back : koooo | l.300\n";
// 			}
			
// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);
// 			displayVectors(of, vec, myof, myvec);

// 			vec.push_back(value());
// 			myvec.push_back(value());
// 			vec.push_back(value());
// 			myvec.push_back(value());
// 			print_str(of, myof, "vec.push_back(value())");
// 			displayVectors(of, vec, myof, myvec);
// 			if (vec.size() == myvec.size())
// 				print_str(of, myof, "size change after push_back : ok");
// 			else {
// 				of << "size change after push_back : ok | l.300\n";
// 				myof << "size change after push_back : koooo | l.300\n";
// 			}
// 			if (vec.capacity() == myvec.capacity())
// 				print_str(of, myof, "capacity change after push_back : ok");
// 			else {
// 				of << "capacity change after push_back : ok | l.300\n";
// 				myof << "capacity change after push_back : koooo | l.300\n";
// 			}
// 		}

// 		void test_pop_back(ofstream& of, ofstream& myof) {
// 			print_str(of, myof, "-------- pop_back");
// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);
// 			displayVectors(of, vec, myof, myvec);

// 			vec.pop_back();
// 			myvec.pop_back();
// 			print_str(of, myof, "vec.pop_back())");
// 			displayVectors(of, vec, myof, myvec);
// 			if (vec.size() == myvec.size())
// 				print_str(of, myof, "size change after pop_back : ok");
// 			else {
// 				of << "size change after pop_back : ok | l.300\n";
// 				myof << "size change after pop_back : koooo | l.300\n";
// 			}
// 			if (vec.capacity() == myvec.capacity())
// 				print_str(of, myof, "capacity change after pop_back : ok");
// 			else {
// 				of << "capacity change after pop_back : ok | l.300\n";
// 				myof << "capacity change after pop_back : koooo | l.300\n";
// 			}
// 		}

// 		void test_swap(ofstream& of, ofstream& myof) {
// 			print_str(of, myof, "-------- swap");
// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);
// 			print_str(of, myof, "vec ");
// 			displayVectors(of, vec, myof, myvec);

// 			vector<value> other(24, value());
// 			vector<value> myother(24, value());
// 			fill_vec(&other, &myother);
// 			print_str(of, myof, "other ");
// 			displayVectors(of, other, myof, myother);

// 			typename vector<value>::iterator it_start_vec = vec.begin() + 3;
// 			typename vector<value>::iterator myit_start_vec = myvec.begin() + 3;
// 			typename vector<value>::iterator it_start_other = other.begin() + 3;
// 			typename vector<value>::iterator myit_start_other = myother.begin() + 3;

// 			of << "it de vec au debut :" << *it_start_vec << "\n" << "it de other au debut :" << *it_start_other << "\n";
// 			myof << "it de vec au debut :" << *myit_start_vec << "\n" << "it de other au debut :" << *myit_start_other << "\n";

// 			swap(vec, other);
// 			swap(myvec, myother);
// 			print_str(of, myof, "vec.swap(other) : vec smaller than other");
// 			print_str(of, myof, "vec ");
// 			displayVectors(of, vec, myof, myvec);
// 			print_str(of, myof, "other ");
// 			displayVectors(of, other, myof, myother);

// 			of << "it de vec a la fin :" << *it_start_vec << "\n" << "it de other a la fin :" << *it_start_other << "\n";
// 			myof << "it de vec a la fin :" << *myit_start_vec << "\n" << "it de other a la fin :" << *myit_start_other << "\n";

// 			vector<value> third(5, value());
// 			vector<value> mythird(5, value());
// 			fill_vec(&third, &mythird);
// 			print_str(of, myof, "third ");
// 			displayVectors(of, third, myof, mythird);

// 			other.swap(third);
// 			myother.swap(mythird);
// 			print_str(of, myof, "other.swap(third) : other bigger than third");
// 			print_str(of, myof, "other ");
// 			displayVectors(of, other, myof, myother);
// 			print_str(of, myof, "third ");
// 			displayVectors(of, third, myof, mythird);
// 		}

// 		void test_clear(ofstream& of, ofstream& myof) {
// 			print_str(of, myof, "-------- clear");
// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);

// 			print_str(of, myof, "before clear :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" <<  vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			vec.clear();
// 			myvec.clear();

// 			print_str(of, myof, "after clear : ");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			vec.push_back(value());
// 			myvec.push_back(value());
// 			print_str(of, myof, "after one pushback :");
// 			displayVectors(of, vec, myof, myvec);
// 		}

// 		void test_erase(ofstream& of, ofstream& myof) {
// 			print_str(of, myof, "-------- erase");
// 			vector<value> vec(10, value());
// 			vector<value> myvec(10, value());
// 			fill_vec(&vec, &myvec);
// 			typename vector<value>::iterator it = vec.begin();
// 			typename vector<value>::iterator myit = myvec.begin();

// 			print_str(of, myof, "before erase begin() :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			typename vector<value>::iterator ret = vec.erase(it);
// 			typename vector<value>::iterator myret = myvec.erase(myit);

// 			print_str(of, myof, "after erase begin() :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			print_str(of, myof, "ret erase :");
// 			of << *ret << "\n";
// 			myof << *myret << "\n";

// 			print_str(of, myof, "before erase(begin(), begin() + 5) :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			ret = vec.erase(it, it + 5);
// 			myret = myvec.erase(myit, myit + 5);

// 			print_str(of, myof, "after erase(begin(), begin() + 5) :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			print_str(of, myof, "ret erase :");
// 			of << *ret << "\n";
// 			myof << *myret << "\n";
// 		}

// 		void test_insert(ofstream& of, ofstream& myof) {
// 			print_str(of, myof, "-------- insert");

// 			vector<value> empty;
// 			vector<value> myempty;
// 			displayVectors(of, empty, myof, myempty);

// 			empty.insert(empty.begin(), value());
// 			myempty.insert(myempty.begin(), value());
// 			print_str(of, myof, "empty.insert(value())");
// 			displayVectors(of, empty, myof, myempty);
// 			if (empty.size() == myempty.size())
// 				print_str(of, myof, "size change after insert : ok");
// 			else {
// 				of << "size change after insert : ok | l.300\n";
// 				myof << "size change after insert : koooo | l.300\n";
// 			}
// 			if (empty.capacity() == myempty.capacity())
// 				print_str(of, myof, "capacity change after insert : ok");
// 			else {
// 				of << "capacity change after insert : ok | l.300\n";
// 				myof << "capacity change after insert : koooo | l.300\n";
// 			}

// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);

// 			print_str(of, myof, "before insert(begin(), 3, value()) :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			typename vector<value>::iterator it = vec.begin();
// 			typename vector<value>::iterator myit = myvec.begin();
// 			++it;
// 			++myit;
// 			vec.insert(it, 3, value());
// 			myvec.insert(myit, 3, value());

// 			print_str(of, myof, "after insert(begin(), 3, value()) :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 			myof << "size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";

// 			typename vector<value>::iterator ret = vec.insert(vec.begin(), value());
// 			typename vector<value>::iterator myret = myvec.insert(myvec.begin(), value());

// 			if (*ret == *myret)
// 				print_str(of, myof, "ret de insert : ok");
// 			else {
// 				of << "ret de insert : ok | l.300\n";
// 				myof << "ret de insert : koooo | l.300\n";
// 			}

// 			print_str(of, myof, "before insert(empty.begin(), vec.begin(), vec.end()) :");
// 			displayVectors(of, empty, myof, myempty);
// 			of << "size :" << empty.size() << " - capacity :" << empty.capacity() << "\n";
// 			myof << "size :" << myempty.size() << " - capacity :" << myempty.capacity() << "\n";

// 			empty.insert(empty.begin(), vec.begin(), vec.end());
// 			myempty.insert(myempty.begin(), vec.begin(), vec.end());

// 			print_str(of, myof, "after insert(empty.begin(), vec.begin(), vec.end()) :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << empty.size() << " - capacity :" << empty.capacity() << "\n";
// 			myof << "size :" << myempty.size() << " - capacity :" << myempty.capacity() << "\n";

// 			vector<value> emptyRange;
// 			vector<value> myemptyRange;

// 			print_str(of, myof, "before after insert(begin(), 3, value()) :");
// 			displayVectors(of, emptyRange, myof, myemptyRange);
// 			of << "size :" << emptyRange.size() << " - capacity :" << emptyRange.capacity() << "\n";
// 			myof << "size :" << myemptyRange.size() << " - capacity :" << myemptyRange.capacity() << "\n";

// 			emptyRange.insert(emptyRange.begin(), 3, value());
// 			myemptyRange.insert(myemptyRange.begin(), 3, value());

// 			print_str(of, myof, "after insert(begin(), 3, value()) :");
// 			displayVectors(of, vec, myof, myvec);
// 			of << "size :" << emptyRange.size() << " - capacity :" << emptyRange.capacity() << "\n";
// 			myof << "size :" << myemptyRange.size() << " - capacity :" << myemptyRange.capacity() << "\n";
// 		}

// 	public:

// 		TestVector() {}
// 		~TestVector() {}

// 		void test_general(ofstream& of, ofstream& myof) {

// 			of << "\n\n\nTEST-GENERAL ✅\n\n";
// 			myof << "\n\n\nTEST-GENERAL ✅\n\n";

// 			print_str(of, myof, "-------- constructors");
// 			print_str(of, myof, "vec(n, value())");
// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			displayVectors(of, vec, myof, myvec);

// 			print_str(of, myof, "vec default");
// 			vector<value> bis;
// 			vector<value> mybis;

// 			bis.resize(10, value());
// 			mybis.resize(10, value());
// 			fill_vec(&bis, &mybis);
// 			displayVectors(of, bis, myof, mybis);

// 			print_str(of, myof, "vec(copy)");
// 			vector<value> quatre(vec);
// 			vector<value> myquatre(myvec);
// 			displayVectors(of, quatre, myof, myquatre);
	
// 			print_str(of, myof, "vec range");
// 			vector<value> range(bis.begin(), bis.end());
// 			vector<value> myrange(bis.begin(), bis.end());
// 			displayVectors(of, range, myof, myrange);

// 			vector<value> rangebis(bis.begin(), bis.begin());
// 			vector<value> myrangebis(bis.begin(), bis.begin());
// 			displayVectors(of, rangebis, myof, myrangebis);

// 			vector<value> empty;
// 			vector<value> rangetres(empty.begin(), empty.end());
// 			vector<value> myrangetres(empty.begin(), empty.end());
// 			displayVectors(of, rangetres, myof, myrangetres);
// // not supposed to work
// 			// vector<value> rangenotworking(bis.begin(), 32);
// 			// vector<value> myrangenotworking(bis.begin(), 1);

// 			print_str(of, myof, "-------- get_alloc()");
// 			if (vec.get_allocator() == myvec.get_allocator())
// 				print_str(of, myof, "vec.get_allocator() == myvec.get_allocator() : ok");
// 			else {
// 				of << "vec.get_allocator() == myvec.get_allocator() : ok | l.300\n";
// 				myof << "vec.get_allocator() == myvec.get_allocator() : koooo work | l.300\n";
// 			}

// 			print_str(of, myof, "-------- assign()");
// 			vector<value> assign;
// 			vector<value> myassign;
// 			fill_vec(&assign, &myassign);

// 			print_str(of, myof, "print bis :");
// 			displayVectors(of, bis, myof, mybis);
// 			print_str(of, myof, "before assign(bis.begin(), bis.end()) :");
// 			displayVectors(of, assign, myof, myassign);
// 			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
// 			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

// 			assign.assign(3, value());
// 			myassign.assign(3, value());

// 			print_str(of, myof, "after assign(bis.begin(), bis.end()) :");
// 			displayVectors(of, assign, myof, myassign);
// 			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
// 			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

// 			vector<value> assignbis(2, value());
// 			vector<value> myassignbis(2, value());
// 			fill_vec(&assign, &myassign);

// 			print_str(of, myof, "before assign(assignbis.begin(), assignbis.end()) :");
// 			displayVectors(of, assign, myof, myassign);
// 			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
// 			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

// 			assign.assign(assignbis.begin(), assignbis.end());
// 			myassign.assign(myassignbis.begin(), myassignbis.end());

// 			print_str(of, myof, "after assign(assignbis.begin(), assignbis.end()) :");
// 			displayVectors(of, assign, myof, myassign);
// 			of << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
// 			myof << "size :" << myassign.size() << " - capacity :" << myassign.capacity() << "\n";

// 		}

// 		void test_operators(ofstream& of, ofstream& myof) {

// 			of << "\n\n\nTEST-OPERATOS ✅\n\n";
// 			myof << "\n\n\nTEST-OPERATOS ✅\n\n";

// 			vector<value> equal(20,  value());
// 			vector<value> test(equal);
// 			vector<value> myequal(20,  value());
// 			vector<value> mytest(myequal);

// 		// ==
// 			if (equal  == test)
// 				of << "equal == test :" << (equal == test) << "\n";
// 			if (myequal == mytest)
// 				myof << "equal == test :" << (myequal == mytest) << "\n";

// 			test.push_back(value());
// 			mytest.push_back(value());

// 		// !=
// 			if (equal != test)
// 				of << "equal != test :" << (equal != test) << "\n";
// 			if (myequal != mytest)
// 				myof << "equal != test :" << (myequal != mytest) << "\n";

// 		// <
// 			if (equal < test)
// 				of << "equal < test :" << (equal < test) << "\n";
// 			if (myequal < mytest)
// 				myof << "equal < test :" << (myequal < mytest) << "\n";

// 		// <=
// 			if (equal <= test)
// 				of << "equal <= test :" << (equal <= test) << "\n";
// 			if (myequal <= mytest)
// 				myof << "equal <= test :" << (myequal <= mytest) << "\n";

// 			equal.push_back(value());
// 			myequal.push_back(value());
// 			equal.push_back(value());
// 			myequal.push_back(value());

// 		// >
// 			if (equal > test)
// 				of << "equal > test :" << (equal > test) << "\n";
// 			if (myequal > mytest)
// 				myof << "equal > test :" << (myequal > mytest) << "\n";

// 		// >=
// 			if (equal >= test)
// 				of << "equal >= test :" << (equal >= test) << "\n";
// 			if (myequal >= mytest)
// 				myof << "equal >= test :" << (myequal >= mytest) << "\n";

// 		}

// 		void test_reverse_iterators(ofstream& of, ofstream& myof) {

// 			of << "\n\n\nTEST-REVERSE-ITERATOS ✅\n\n";
// 			myof << "\n\n\nTEST-REVERSE-ITERATOS ✅\n\n";

// 			vector<value> vec(10, value());
// 			vector<value> myvec(10, value());
// 			fill_vec(&vec, &myvec);
// 			displayVectors(of, vec, myof, myvec);

// 			typename vector<value>::reverse_iterator it = vec.rbegin();
// 			typename vector<value>::reverse_iterator myit = myvec.rbegin();

// 			//	++(int)
// 			of << "it :" << *it << "| ";
// 			myof << "it :" << *myit << "| ";
// 			it++;
// 			myit++;
// 			of << "it++ :" << *it << "\n";
// 			myof << "it++ :" << *myit << "\n";

// 			//	--(int)
// 			of << "it : " << *it << "| ";
// 			myof << "it : " << *myit << "| ";
// 			it--;
// 			myit--;
// 			of << "it-- : " << *it << "\n";
// 			myof << "it-- : " << *myit << "\n";

// 			//	++()
// 			of << "it :" << *it << "| ";
// 			myof << "it :" << *myit << "| ";
// 			++it;
// 			++myit;
// 			of << "++it :" << *it << "\n";
// 			myof << "++it :" << *myit << "\n";

// 			//	--()
// 			of << "it : " << *it << " | ";
// 			myof << "it : " << *myit << " | ";
// 			--it;
// 			--myit;
// 			of << "--it :" << *it << "\n";
// 			myof << "--it :" << *myit << "\n";

// 			// +(int)
// 			it = it + 1;
// 			it = 1 + it;
// 			of << "it = it + 1 :" << *it << "\n";

// 			myit = myit + 1;
// 			myit = 1 + myit;
// 			myof << "it = it + 1 :" << *myit << "\n";

// 			// -(int)
// 			it = it - 1;
// 			of << "it = it - 1 :" << *it << "\n";

// 			myit = myit - 1;
// 			myof << "it = it - 1 :" << *myit << "\n";

// 			// +=(it)
// 			it += 2;
// 			of << "it += 2 :" << *it << "\n";

// 			myit += 2;
// 			myof << "it += 2 :" << *myit << "\n";

// 			// -=(int)
// 			it -= 2;
// 			of << "it -= 2 :" << *it << "\n";

// 			myit -= 2;
// 			myof << "it -= 2 :" << *myit << "\n";

// 			// []
// 			it = vec.rbegin();
// 			myit = myvec.rbegin();

// 			of << "it[0] :" << it[0] << " | it[3] :" << it[3] << "\n";
// 			myof << "it[0] :" << myit[0] << " | it[3] :" << myit[3] << "\n";

// 			for (int i = 0; i < 5; ++i) {
			
// 				srand (time(NULL));
// 				size_t nbr = rand() % (vec.size() - 1);
// 				size_t nbrbis = rand() % (vec.size() - 1);
// 				typename vector<value>::reverse_iterator ittest = vec.rbegin();
// 				*ittest = vec[nbr];
// 				typename vector<value>::reverse_iterator ittestbis = vec.rbegin();
// 				*ittestbis = vec[nbrbis];

// 				size_t mynbr = rand() % (myvec.size() - 1);
// 				size_t mynbrbis = rand() % (myvec.size() - 1);
// 				typename vector<value>::reverse_iterator myittest = myvec.rbegin();
// 				*myittest = myvec[mynbr];
// 				typename vector<value>::reverse_iterator myittestbis = myvec.rbegin();
// 				*myittestbis = myvec[mynbrbis];

// 				//	==
// 				if (*ittest == *ittestbis && *myittest == *myittestbis)
// 					print_str(of, myof, "*ittest == *ittestbis : ok");
// 				else if (*ittest == *ittestbis) {
// 					of << "*ittest == *ittestbis : ok\n";
// 			 		myof << "*ittest == *ittestbis : koooo\n";}

// 				//	!=
// 				if (*ittest != *ittestbis && *myittest != *myittestbis)
// 					print_str(of, myof, "*ittest != *ittestbis : ok");
// 				else if (*ittest != *ittestbis) {
// 					of << "*ittest != *ittestbis : ok\n";
// 			 		myof << "*ittest != *ittestbis : koooo\n";}

// 				//	<
// 				if (*ittest < *ittestbis && *myittest < *myittestbis)
// 					print_str(of, myof, "*ittest < *ittestbis : ok");
// 				else if (*ittest < *ittestbis) {
// 					of << "*ittest < *ittestbis : ok\n";
// 			 		myof << "*ittest < *ittestbis : koooo\n";}

// 				//	<=
// 				if (*ittest <= *ittestbis && *myittest <= *myittestbis)
// 					print_str(of, myof, "*ittest <= *ittestbis : ok");
// 				else if (*ittest <= *ittestbis) {
// 					of << "*ittest <= *ittestbis : ok\n";
// 			 		myof << "*ittest <= *ittestbis : koooo\n";}

// 				//	>
// 				if (*ittest > *ittestbis && *myittest > *myittestbis)
// 					print_str(of, myof, "*ittest > *ittestbis : ok");
// 				else if (*ittest > *ittestbis) {
// 					of << "*ittest > *ittestbis : ok\n";
// 			 		myof << "*ittest > *ittestbis : koooo\n";}

// 				//	>=
// 				if (*ittest >= *ittestbis && *myittest >= *myittestbis)
// 					print_str(of, myof, "*ittest >= *ittestbis : ok");
// 				else if (*ittest >= *ittestbis) {
// 					of << "*ittest >= *ittestbis : ok\n";
// 					myof << "*ittest >= *ittestbis : koooo\n";}
// 			}
// 			test_it_arrow(of, myof);
// 		}


// 		void test_iterators(ofstream& of, ofstream& myof) {
// 			of << "\n\n\nTEST-ITERATORS ✅\n\n";
// 			myof << "\n\n\nTEST-ITERATORS ✅\n\n";

// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);
// 			displayVectors(of, vec, myof, myvec);

// 			typename vector<value>::iterator it = vec.begin();
// 			typename vector<value>::iterator myit = myvec.begin();

// 			//	++(int)
// 			of << "it :" << *it << "| ";
// 			myof << "it :" << *myit << "| ";
// 			it++;
// 			myit++;
// 			of << "it++ :" << *it << "\n";
// 			myof << "it++ :" << *myit << "\n";

// 			//	--(int)
// 			of << "it : " << *it << "| ";
// 			myof << "it : " << *myit << "| ";
// 			it--;
// 			myit--;
// 			of << "it-- : " << *it << "\n";
// 			myof << "it-- : " << *myit << "\n";

// 			//	++()
// 			of << "it :" << *it << "| ";
// 			myof << "it :" << *myit << "| ";
// 			++it;
// 			++myit;
// 			of << "++it :" << *it << "\n";
// 			myof << "++it :" << *myit << "\n";

// 			//	--()
// 			of << "it : " << *it << " | ";
// 			myof << "it : " << *myit << " | ";
// 			--it;
// 			--myit;
// 			of << "--it :" << *it << "\n";
// 			myof << "--it :" << *myit << "\n";

// 			// +(int)
// 			it = it + 1;
// 			it = 1 + it;
// 			of << "it = it + 1 :" << *it << "\n";

// 			myit = myit + 1;
// 			myit = 1 + myit;
// 			myof << "it = it + 1 :" << *myit << "\n";

// 			// -(int)
// 			it = it - 1;
// 			of << "it = it - 1 :" << *it << "\n";

// 			myit = myit - 1;
// 			myof << "it = it - 1 :" << *myit << "\n";

// 			// +=(it)
// 			it += 2;
// 			of << "it += 2 :" << *it << "\n";

// 			myit += 2;
// 			myof << "it += 2 :" << *myit << "\n";

// 			// -=(int)
// 			it -= 2;
// 			of << "it -= 2 :" << *it << "\n";

// 			myit -= 2;
// 			myof << "it -= 2 :" << *myit << "\n";

// 			// []
// 			it = vec.begin();
// 			myit = myvec.begin();

// 			of << "it[0] :" << it[0] << " | it[3] :" << it[3] << "\n";
// 			myof << "it[0] :" << myit[0] << " | it[3] :" << myit[3] << "\n";

// 			typename vector<value>::iterator itit = vec.begin();
// 			typename vector<value>::iterator tmp = itit + 3;
// 			typename vector<value>::iterator myitit = myvec.begin();
// 			typename vector<value>::iterator mytmp = myitit + 3;

// 			// -(it)
// 			int i = itit - tmp;
// 			of << "int i = itit - tmp :" << i << "\n";

// 			int myi = myitit - mytmp;
// 			myof << "int i = itit - tmp :" << myi << "\n";

// 			for (int i = 0; i < 5; ++i) {
			
// 				srand (time(NULL));
// 				size_t nbr = rand() % (vec.size() - 1);
// 				size_t nbrbis = rand() % (vec.size() - 1);
// 				typename vector<value>::iterator ittest = vec.begin();
// 				*ittest = vec[nbr];
// 				typename vector<value>::iterator ittestbis = vec.begin();
// 				*ittestbis = vec[nbrbis];

// 				size_t mynbr = rand() % (myvec.size() - 1);
// 				size_t mynbrbis = rand() % (myvec.size() - 1);
// 				typename vector<value>::iterator myittest = myvec.begin();
// 				*myittest = myvec[mynbr];
// 				typename vector<value>::iterator myittestbis = myvec.begin();
// 				*myittestbis = myvec[mynbrbis];

// 				//	==
// 				if (*ittest == *ittestbis && *myittest == *myittestbis)
// 					print_str(of, myof, "*ittest == *ittestbis : ok");
// 				else if (*ittest == *ittestbis) {
// 					of << "*ittest == *ittestbis : ok\n";
// 			 		myof << "*ittest == *ittestbis : koooo\n";}

// 				//	!=
// 				if (*ittest != *ittestbis && *myittest != *myittestbis)
// 					print_str(of, myof, "*ittest != *ittestbis : ok");
// 				else if (*ittest != *ittestbis) {
// 					of << "*ittest != *ittestbis : ok\n";
// 			 		myof << "*ittest != *ittestbis : koooo\n";}

// 				//	<
// 				if (*ittest < *ittestbis && *myittest < *myittestbis)
// 					print_str(of, myof, "*ittest < *ittestbis : ok");
// 				else if (*ittest < *ittestbis) {
// 					of << "*ittest < *ittestbis : ok\n";
// 			 		myof << "*ittest < *ittestbis : koooo\n";}

// 				//	<=
// 				if (*ittest <= *ittestbis && *myittest <= *myittestbis)
// 					print_str(of, myof, "*ittest <= *ittestbis : ok");
// 				else if (*ittest <= *ittestbis) {
// 					of << "*ittest <= *ittestbis : ok\n";
// 			 		myof << "*ittest <= *ittestbis : koooo\n";}

// 				//	>
// 				if (*ittest > *ittestbis && *myittest > *myittestbis)
// 					print_str(of, myof, "*ittest > *ittestbis : ok");
// 				else if (*ittest > *ittestbis) {
// 					of << "*ittest > *ittestbis : ok\n";
// 			 		myof << "*ittest > *ittestbis : koooo\n";}

// 				//	>=
// 				if (*ittest >= *ittestbis && *myittest >= *myittestbis)
// 					print_str(of, myof, "*ittest >= *ittestbis : ok");
// 				else if (*ittest >= *ittestbis) {
// 					of << "*ittest >= *ittestbis : ok\n";
// 					myof << "*ittest >= *ittestbis : koooo\n";}
// 			}
// 			test_it_arrow(of, myof);
// 		}

// 		void test_capacity(ofstream& of, ofstream& myof) {
			
// 			of << "\n\n\nTEST-CAPACITY ✅\n\n";
// 			myof << "\n\n\nTEST-CAPACITY ✅\n\n";

// 			vector<value> emptyvec;
// 			vector<value> myemptyvec;

// 			// empty
// 			if (emptyvec.empty() == myemptyvec.empty())
// 				print_str(of, myof, "emptyvec.empty() == myemptyvec.empty() : ok");
// 			else {
// 				of << "emptyvec.empty() == myemptyvec.empty() : ok | l.300\n";
// 				myof << "emptyvec.empty() == myemptyvec.empty() : koooo work | l.300\n";
// 			}

// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);

// 			// size
// 			if (vec.size() == myvec.size())
// 				print_str(of, myof, "vec.size() == myvec.size() : ok");
// 			else {
// 				of << "size :" << vec.size() << "\n";
// 				myof << "size :" << myvec.size() << "\n";
// 			}

// 			// max_size
// 			if (vec.max_size() == myvec.max_size())
// 				print_str(of, myof, "vec.max_size() == myvec.max_size() : ok");
// 			else {
// 				of << "vec.max_size() == myvec.max_size() : ok | l.300\n";
// 				myof << "vec.max_size() == myvec.max_size() : koooo work | l.300\n";
// 			}

// 			// capacity
// 			if (vec.capacity() == myvec.capacity())
// 				print_str(of, myof, "vec.capacity() == myvec.capacity() : ok");
// 			else {
// 				of << "capacity test - size : " << vec.size() << " - capacity : " << vec.capacity() << "\n";
// 				myof << "capacity test - size : " << myvec.size() << " - capacity : " << myvec.capacity() << "\n";
// 			}

// 			// reserve
// 			vec.reserve(25);
// 			myvec.reserve(25);
// 			if (vec.capacity() == myvec.capacity())
// 				print_str(of, myof, "vec.reserve : ok");
// 			else {
// 				of << "reserve test - size :" << vec.size() << " - capacity :" << vec.capacity() << "\n";
// 				myof << "reserve test - size :" << myvec.size() << " - capacity :" << myvec.capacity() << "\n";
// 			}
// 		}

// 		void test_accessors(ofstream& of, ofstream& myof) {
			
// 			of << "\n\n\nTEST-ACCESSORS ✅\n\n";
// 			myof << "\n\n\nTEST-ACCESSORS ✅\n\n";

// 			vector<value> vec(20, value());
// 			vector<value> myvec(20, value());
// 			fill_vec(&vec, &myvec);
// 			displayVectors(of, vec, myof, myvec);

// 			// []
// 			if (vec[0] == myvec[0])
// 				print_str(of, myof, "vec[0] == myvec[0] : ok");
// 			else {
// 				of << "vec[0] == myvec[0] : ok | l.300\n";
// 				myof << "vec[0] == myvec[0] : koooo | l.300\n";
// 			}
			
// 			// at
// 			if (vec.at(0) == myvec.at(0))
// 				print_str(of, myof, "vec.at() == myvec.at() : ok");
// 			else {
// 				of << "vec.at(0) == myvec.at(0) : ok | l.300\n";
// 				myof << "vec.at(0) == myvec.at(0) : koooo | l.300\n";
// 			}

// 			// front
// 			if (vec.front() == myvec.front())
// 				print_str(of, myof, "vec.front() == myvec.front() : ok");
// 			else {
// 				of << "vec.front() == myvec.front() : ok | l.300\n";
// 				myof << "vec.front() == myvec.front() : koooo | l.300\n";
// 			}

// 			// back
// 			if (vec.back() == myvec.back())
// 				print_str(of, myof, "vec.back() == myvec.back() : ok");
// 			else {
// 				of << "vec.back() == myvec.back() : ok | l.300\n";
// 				myof << "vec.back() == myvec.back() : koooo | l.300\n";
// 			}
// 		}

// 		void test_modifiers(ofstream& of, ofstream& myof) {
			
// 			of << "\n\n\nTEST-MODIFIERS ✅\n\n";
// 			myof << "\n\n\nTEST-MODIFIERS ✅\n\n";

// 			test_resize(of, myof);
// 			test_push_back(of, myof);
// 			test_pop_back(of, myof);
// 			test_swap(of, myof);
// 			test_clear(of, myof);
// 			test_erase(of, myof);
// 			test_insert(of, myof);
// 		}

// 		void test_const(ofstream& of, ofstream& myof) {
// 			of << "\n\n\nTEST-CONST ✅\n\n";
// 			myof << "\n\n\nTEST-CONST ✅\n\n";

// 			const vector<value> vec(20, value());
// 			const vector<value> myvec(20, value());

// //should not compile
// 			// vec[0] = 1;
// 			// myvec[0] = 1;

// //should not compile
// 			// typename vector<value>::iterator it = vec.begin();
// 			// (void) it;
// 			// typename vector<value>::iterator myit = myvec.begin();
// 			// (void) myit;

// 			typename vector<const value>::iterator it = vec.begin();
// 			typename vector<const value>::iterator myit = myvec.begin();

// 			typename vector<value>::const_iterator itconst = vec.begin();
// 			typename vector<value>::const_iterator myitconst = myvec.begin();

// 			++it;
// 			++myit;
// 			++itconst;
// 			++myitconst;

// //should not compile
// 			// it = value();
// 			// myit = value();
// 			// itconst = value();
// 			// myitconst = value();

// //should not compile
// 			// vec.clear();
// 			// myvec.clear();
// 			// vec.reserve(10);
// 			// myvec.clear();

// 			of << "size of vec :" << vec.size() << "\n";
// 			myof << "size of vec :" << myvec.size() << "\n";
// 			of << "capacity of vec :" << vec.capacity() << "\n";
// 			myof << "capacity of vec :" << myvec.capacity() << "\n";
// 			of << "vec.at(10) :" << vec.at(10) << "\n";
// 			myof << "vec.at(10) :" << myvec.at(10) << "\n";
// 			if (vec.back() == myvec.back())
// 				print_str(of, myof, "operator == on back() compile");

// 			vector<value> const vecconst(20, value());
// 			vector<value> const myvecconst(20, value());

// 			if (vec  == vecconst)
// 				of << "vec == vecconst :" << (vec.begin() == vecconst.begin()) << "\n";
// 			if (myvec == myvecconst)
// 				myof << "vec == vecconst :" << (myvec.begin() == myvecconst.begin()) << "\n";

// 			if (vec.begin() == vecconst.begin())
// 				of << "vec.begin() == vecconst.begin() :" << (vec.begin() == vecconst.begin()) << "\n";
// 			if (myvec.begin() == myvecconst.begin())
// 				myof << "vec.begin() == vecconst.begin() :" << (myvec.begin() == myvecconst.begin()) << "\n";

// 			typename vector<value>::const_iterator cit = vecconst.begin();
// 			while (cit != vecconst.end())
// 				++cit;

// 			typename vector<value>::const_iterator mycit = myvecconst.begin();
// 			while (mycit != myvecconst.end())
// 				++mycit;
// 		}
// };

// template<>		//function specilization
// void TestVector<string>::fill_vec(vector<string>* vec, vector<string>* myvec) {

// 	vector<string>::iterator it = vec->begin();
// 	vector<string>::iterator myit = myvec->begin();

// 	string str[10] = { "test", "pop", "essay", "beeze", "youhou",
// 								"orange", "blue", "black", "sun", "best" };
// 	for (size_t i = 0; i < vec->size(); ++i) {
// 		int val = rand() % 10;
// 		*it = str[val];
// 		*myit = str[val];
// 		++it;
// 		++myit;
// 	}
// }

// template<>
// void TestVector<string>::test_it_arrow(ofstream& of, ofstream& myof) {

// 	// ->
// 	vector<string> test(4, "pop");
// 	vector<string>::iterator ittest = test.begin();
// 	if (!strcmp(ittest->c_str(), "pop"))
// 		of << "test -> ok \n";
// 	else
// 		of << "test -> koooo \n";

// 	vector<string> mytest(4, "pop");
// 	vector<string>::iterator myittest = mytest.begin();
// 	if (!strcmp(myittest->c_str(), "pop"))
// 		myof << "test -> ok \n";
// 	else
// 		myof << "test -> koooo \n";
// }

// template<typename T, class Alloc>
// bool		operator==(const vector<T, Alloc> & src, const vector<T, Alloc> & cmp) {
// 				if (src.size() != cmp.size())
// 					return false;
// 				typename vector<T>::const_iterator it = src.begin();
// 				typename vector<T>::const_iterator itbis = cmp.begin();
// 				while(it != src.end()) {
// 					if (itbis == cmp.end() || *it != *itbis)
// 						return false;
// 					++it;
// 					++itbis;
// 				}
// 				return true;
// 			}

// template<typename T, class Alloc>
// bool		operator==(const vector<T, Alloc> & src, const vector<T, Alloc> & cmp) {
// 				if (src.size() != cmp.size())
// 					return false;
// 				typename vector<T>::const_iterator it = src.begin();
// 				typename vector<T>::const_iterator itbis = cmp.begin();
// 				while(it != src.end()) {
// 					if (itbis == cmp.end() || *it != *itbis)
// 						return false;
// 					++it;
// 					++itbis;
// 				}
// 				return true;
// 			}