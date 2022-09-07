#ifndef __AVL_TREE_HPP__
#define __AVL_TREE_HPP__
#include "basic_avl_tree.hpp"

namespace datastruct {

    template<typename Ty, typename HigherPredicate, typename EqualsPredicate>
    class AvlTree : public BasicAvlTree<Ty, HigherPredicate, EqualsPredicate>{
    private:
        using _HiPred = HigherPredicate;
        using _EqPred = EqualsPredicate;

    public:
        AvlTree(const _HiPred& _lower, const _EqPred& equals) 
            :
            BasicAvlTree<Ty, _HiPred, _EqPred>(_lower, equals) {}
        ~AvlTree() { delete this->root; this->root = nullptr; }

        void __cdecl insert(const Ty& value) {
            this->_avl_insert(this->root, const_cast<Ty&>(value), this->_lower, 0, this->_height + 1);
            this->_c_height();
        }

        template<typename BoolFunction>
        void __cdecl insert(const Ty& value, BoolFunction _function) {
            this->_avl_insert(this->root, const_cast<Ty&>(value), _function, 0, this->_height + 1);
            this->_c_height();
        }

    };
}

#endif //__AVL_TREE_HPP__