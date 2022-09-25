#ifndef __BASIC_AVL_TREE_HPP__
#define __BASIC_AVL_TREE_HPP__

#include "basic_binary_tree.hpp"
namespace datastructures {
    template<typename Ty, typename HigherPredicate, typename EqualsPredicate>
    class BasicAvlTree : public BasicBinaryTree<Ty, HigherPredicate, EqualsPredicate> {
    protected:
        using _Node = basic_bynode<Ty>;
		using _HiPred = HigherPredicate;
		using _EqPred = EqualsPredicate;

		void __cdecl _right_rotation(_Node*& node) {
			_Node* father = node->left;
			node->left = father->right;
			father->right = node;
			node = father;
		}

		void __cdecl _left_rotation(_Node*& node) {
			_Node* father = node->right;
			node->right = father->left;
			father->left = node;
			node = father;
		}

		ll __cdecl _n_height(_Node*& node) {
			if (node == nullptr)
				return 0;
			return node->height;
		}

		void __cdecl swing(_Node*& node) {
			ll diference = this->_n_height(node->left) - this->_n_height(node->right);
			if (diference > 1) {
				--this->a_height;
				ll h_left = this->_n_height(node->left->left);
				ll h_right = this->_n_height(node->left->right);
				if (h_left < h_right)
					this->_left_rotation(node->left);
				this->_right_rotation(node);
			}
			else if (diference < -1) {
				--this->a_height;
				ll h_left = this->_n_height(node->right->left);
				ll h_right = this->_n_height(node->right->right);
				if (h_left > h_right)
					this->_right_rotation(node->right);
				this->_left_rotation(node);
			}
		}

		template<typename BoolFunction>
		void __cdecl _avl_insert(_Node*& node, Ty& value, BoolFunction& _function, ull level = 0, ull height = 0) {
			if (node != nullptr) {
				node->height = height;
				if (_function(node->value, value))
					this->_avl_insert(node->left, value, _function, level + 1, height - 1);
				else this->_avl_insert(node->right, value, _function, level + 1, height - 1);
				this->swing(node);
			}
			else {
				node = new _Node(value, level, height);
				++this->_size;
			}
			++this->a_height;
		}

	public:
		BasicAvlTree(const _HiPred& _lower, const _EqPred& _equals) 
            : 
			BasicBinaryTree<Ty, _HiPred, _EqPred>(_lower, _equals) {}
    };
}

#endif //__BASIC_AVL_TREE_HPP__