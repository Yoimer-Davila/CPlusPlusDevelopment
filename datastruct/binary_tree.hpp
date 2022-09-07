#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__
#include "basic_binary_tree.hpp"

namespace datastruct {

    template <typename Ty, typename HigherPredicate = higher<Ty>, typename EqualPredicate = equals<Ty>>
    class BinaryTree : public BasicBinaryTree<Ty, HigherPredicate, EqualPredicate> {

    private:
        using _HiPred = HigherPredicate;
        using _EqPred = EqualPredicate;
    public:
        BinaryTree(const _HiPred& _left, const _EqPred& _equals) :
		    BasicBinaryTree<Ty, _HiPred, _EqPred>(_left, _equals) {}
	    ~BinaryTree() { delete this->root; this->root = nullptr; }

	    void __cdecl insert(const Ty& value) { this->_insert(this->root, const_cast<Ty&>(value), this->_lower); this->_c_height(); }

	    template<typename BoolFunction>
	    void __cdecl insert(const Ty& value, BoolFunction _function) { this->_insert(this->root, const_cast<Ty&>(value), _function); this->_c_height(); }

    };

}

#endif //__BINARY_TREE_HPP__