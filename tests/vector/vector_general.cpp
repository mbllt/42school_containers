#include "test_vector.hpp"

template<typename Cont>
void fillVecInt(Cont* cont) {
	typename Cont::iterator it =cont->begin();

		for (size_t i = 0; i < cont->size(); ++i) {
			int val = rand() % 100;
			*it = val;
			++it;
		}
	}

void test() {

	std::cout << "vec(n, int())" << std::endl;
	vector<int> vec(20, int());
	displayCont(vec);

	std::cout << "vec default" << std::endl;
	vector<int> bis;

	bis.resize(10, int());
	fillVecInt(&bis);
	displayCont(bis);

	std::cout << "vec(copy)" << std::endl;
	vector<int> quatre(vec);
	displayCont(quatre);
	
	std::cout << "vec range" << std::endl;
	vector<int> range(bis.begin(), bis.end());
	displayCont(range);

	vector<int> rangebis(bis.begin(), bis.begin());
	displayCont(rangebis);

	vector<int> empty;
	vector<int> rangetres(empty.begin(), empty.end());
	displayCont(rangetres);

	vector<int> assign;
	fillVecInt(&assign);

	std::cout << "before assign(3, int()) :" << std::endl;
	displayCont(assign);
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	assign.assign(3, int());
	std::cout << "after assign(3, int()) :" << std::endl;
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	displayCont(assign);

	vector<int> assignbis(2, int());
	fillVecInt(&assign);

	std::cout << "before assign(assignbis.begin(), assignbis.end()) :" << std::endl;
	displayCont(assign);
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	assign.assign(assignbis.begin(), assignbis.end());
	std::cout << "after assign(assignbis.begin(), assignbis.end()) :" << std::endl;
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	displayCont(assign);
}