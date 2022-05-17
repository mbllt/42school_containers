#include "test_vector.hpp"

void vec_general() {

	std::cout << "vec(n, int())" << std::endl;
	vector<int> vec(20, int());
	fillVecInt(&vec);
	std::cout << "vec :";
	displayVec(vec);

	std::cout << "vec default" << std::endl;
	vector<int> bis;

	bis.resize(10, int());
	fillVecInt(&bis);
	std::cout << "bis :";
	displayVec(bis);

	std::cout << "vec(copy)" << std::endl;
	vector<int> quatre(vec);
	std::cout << "quatre :";
	displayVec(quatre);
	
	std::cout << "vec range" << std::endl;
	vector<int> range(bis.begin(), bis.end());
	std::cout << "range :";
	displayVec(range);

	vector<int> rangebis(bis.begin(), bis.begin());
	std::cout << "rangebis :";
	displayVec(rangebis);

	vector<int> empty;
	vector<int> rangetres(empty.begin(), empty.end());
	std::cout << "rangetres :";
	displayVec(rangetres);

	vector<int> assign;
	fillVecInt(&assign);

	std::cout << "before assign(3, int()) :" << std::endl;
	displayVec(assign);
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	assign.assign(3, int());
	std::cout << "after assign(3, int()) :" << std::endl;
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	displayVec(assign);

	vector<int> assignbis(2, int());
	fillVecInt(&assign);

	std::cout << "before assign(assignbis.begin(), assignbis.end()) :" << std::endl;
	displayVec(assign);
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	assign.assign(assignbis.begin(), assignbis.end());
	std::cout << "after assign(assignbis.begin(), assignbis.end()) :" << std::endl;
	std::cout << "size :" << assign.size() << " - capacity :" << assign.capacity() << "\n";
	displayVec(assign);
}