#ifndef __AVL_TREE_LIST_HPP__
#define __AVL_TREE_LIST_HPP__
#include "basic_avl_tree.hpp"
namespace datastructures {
    template<typename Ty, typename HigherPredicate, typename EqualsPredicate>
    class AvlTreeList : public BasicAvlTree<Ty, HigherPredicate, EqualsPredicate> {
    
	private:
        using _Node = basic_bynode<Ty>;
		using _HiPred = HigherPredicate;
		using _EqPred = EqualsPredicate;

        using _Inode = basic_bnode<_Node*>;

        _Inode* _start;
        _Inode* _end;

        void __cdecl _push_back(_Node*& node) {
			_Inode* aux = new _Inode(node);
			if (this->_size == 0)
				this->_start = this->_end = aux;
			else {
				this->_end->next = aux;
				aux->back = this->_end;
				this->_end = aux;
			}
		}

		void __cdecl _push_front(_Node*& node) {
			_Inode* aux = new _Inode(node);
			if (this->_size == 0)
				this->_start = this->_end = aux;
			else {
				aux->next = this->_start;
				this->_start->back = aux;
				this->_start = aux;
			}
		}

		template<typename BoolFunction>
		void __cdecl _avl_insert(_Node*& node, Ty& value, BoolFunction& _function,
			ull level, ull height, const bool& _front) {
			if (node != nullptr) {
				node->height = height;
				if (_function(node->value, value))
					this->_avl_insert(node->left, value, _function, level + 1, height - 1, true);
				else this->_avl_insert(node->right, value, _function, level + 1, height - 1, false);
				this->swing(node);
			}
			else {
				node = new _Node(value, level, height);
				if (_front) this->_push_front(node);
				else this->_push_back(node);
				++this->_size;
			}
			++this->a_height;
		}
		
    public:
		AvlTreeList(const _HiPred& _lower, const _EqPred& _equals)
			:
			BasicAvlTree<Ty, _HiPred, _EqPred>(_lower, _equals), _start(nullptr), _end(nullptr) {}

		~AvlTreeList() {
			delete this->root, this->_start, this->_end;
			this->root = nullptr;
			this->_start = this->_end = nullptr;
		}

		void __cdecl push_back(const Ty& value) { this->_avl_insert(this->root, const_cast<Ty&>(value), this->_lower, 0, this->_height + 1, false); this->_c_height(); }
		void __cdecl push_front(const Ty& value) { this->_avl_insert(this->root, const_cast<Ty&>(value), this->_lower, 0, this->_height + 1, true); this->_c_height(); }


		class iterator
		{
		private:
			_Inode* value;
			ll _index;

			using value_type = Ty;
			using pointer = Ty*;
			using reference = Ty&;

		public:
			iterator(ll _index, _Inode*& value) : _index(_index), value(value) {}

			iterator& __cdecl operator++() { ++this->_index; value = value->next; return *this; }
			iterator& __cdecl operator--() { --this->_index; value = value->back; return *this; }

			Ty& __cdecl operator*() { return this->value->value->value; }
			Ty* __cdecl operator->() { return &this->value->value->value; }

			bool __cdecl operator!=(const iterator& _iterator) const { return this->_index != _iterator._index; }

			
		};

		iterator __cdecl begin() { return iterator(0, this->_start); }
		iterator __cdecl end() { return iterator(this->_size, this->_end); }
    };
}
#endif //__AVL_TREE_LIST_HPP__