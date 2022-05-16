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

void vec_general() {

	std::cout << "vec(n, int())" << std::endl;
	vector<int> vec(20, int());
	std::cout << "vec :";
	displayCont(vec);

	std::cout << "vec default" << std::endl;
	vector<int> bis;

	bis.resize(10, int());
	fillVecInt(&bis);
	std::cout << "bis :";
	displayCont(bis);

	std::cout << "vec(copy)" << std::endl;
	vector<int> quatre(vec);
	std::cout << "quatre :";
	displayCont(quatre);
	
	std::cout << "vec range" << std::endl;
	vector<int> range(bis.begin(), bis.end());
	std::cout << "range :";
	displayCont(range);

	vector<int> rangebis(bis.begin(), bis.begin());
	std::cout << "rangebis :";
	displayCont(rangebis);

	vector<int> empty;
	vector<int> rangetres(empty.begin(), empty.end());
	std::cout << "rangetres :";
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