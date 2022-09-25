#include "utility/numbers.hpp"
#include "utility/ustrings.hpp"
#include "datastructures/binary_tree.hpp"
#include "datastructures/avl_tree_list.hpp"
#include "datastructures/avl_tree.hpp"
#include <iostream>
using utilities::Ustring;
using datastructures::BinaryTree;
using datastructures::AvlTreeList;
using datastructures::AvlTree;
using datastructures::comparevalues::higher;
using datastructures::comparevalues::equals;
using datastructures::comparevalues::lower;
using datastructures::ll;
using namespace datastructures::lambdavalues;


using std::cout;
using std::endl;

struct test
{
	int value;
	test(int value) : value(value) {}
	const bool __cdecl operator>(const test& right) const { return this->value > right.value; }
	const bool __cdecl operator==(const test& right) const { return this->value == right.value; }
};


template<typename Ty>
void func(Ty function){}

int main() {
	srand(time(nullptr));
	AvlTree<test, lmbbool<test>, lmbbool<test>> tree(
		[](test& i, test& j) {return i.value > j.value; },
		[](test& i, test& j) {return i.value == j.value; });

	for (ll i = 0; i < 10; ++i)
		tree.insert(rand() % 1000);

	tree.in_order([](const test& i) {cout << i.value << " "; });

	cout << endl << Ustring::to_upper("hello");

	cout << std::endl;
	system("pause");
	return 0;
}