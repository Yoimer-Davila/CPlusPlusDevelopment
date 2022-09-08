#include "utility/numbers.hpp"
#include "utility/ustrings.hpp"
#include "datastruct/binary_tree.hpp"
#include "datastruct/avl_tree_list.hpp"
#include "datastruct/avl_tree.hpp"
#include <iostream>
using utilities::Ustring;
using datastruct::BinaryTree;
using datastruct::AvlTreeList;
using datastruct::AvlTree;
using datastruct::comparevalues::higher;
using datastruct::comparevalues::equals;
using datastruct::comparevalues::lower;
using datastruct::ll;
using namespace datastruct::lambdavalues;


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