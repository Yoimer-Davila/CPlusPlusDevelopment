#ifndef __BASIC_BINARY_TREE_HPP__
#define __BASIC_BINARY_TREE_HPP__
#include "compares.hpp"
#include "nodes.hpp"
namespace datastruct {
	using datastruct::basic_bynode;
	
	/*struct for compares predicate in binary class*/
	using datastruct::compare;
	using datastruct::higher;
	using datastruct::lower;
	using datastruct::equals;
	using datastruct::higher_equal;
	using datastruct::lower_equal;


    template <typename Ty, typename HigherPredicate, typename EqualsPredicate>
    class BasicBinaryTree{
	protected:
		using _Node = basic_bynode<Ty>;
		using _HiPred = HigherPredicate;
		using _EqPred = EqualsPredicate;
		_Node* root;
		ull _size;
		_HiPred _lower;
		_EqPred _equals;

		ll _height, a_height;

		template<typename BoolFunction>
		void __cdecl _insert(_Node*& node, Ty& value, BoolFunction& _function, ull level = 0) {
			if (node != nullptr) {
				if (_function(node->value, value))
					this->_insert(node->left, value, _function, level + 1);
				else this->_insert(node->right, value, _function, level + 1);
			}
			else node = new _Node(value, level), ++this->_size;

			++this->a_height;
		}

		template<typename Function>
		Function __cdecl _in_order(_Node*& node, Function& _function) {
			if (node == nullptr) return _function;
			this->_in_order(node->left, _function);
			_function(node->value);
			this->_in_order(node->right, _function);
			return _function;
		}

		template<typename Function>
		Function __cdecl _rin_order(_Node*& node, Function _function) {
			if (node == nullptr)
				return _function;
			this->_rin_order(node->right, _function);
			_function(node->value);
			this->_rin_order(node->left, _function);

			return _function;
		}

		template<typename Function>
		Function __cdecl _pre_order(_Node*& node, Function& _function) {
			if (node == nullptr) return _function;
			_function(node->value);
			this->_pre_order(node->left, _function);
			this->_pre_order(node->right, _function);
			return _function;
		}

		template<typename Function>
		Function __cdecl _post_order(_Node*& node, Function& _function) {
			if (node == nullptr)return _function;
			this->_post_order(node->left, _function);
			this->_post_order(node->right, _function);
			_function(node->value);
			return _function;
		}

		template<typename Function>
		Function __cdecl _lefts(_Node*& node, Function& _function) {
			if (node != nullptr) {
				_function(node->value);
				this->_lefts(node->left, _function);
			}
			return _function;
		}

		template<typename Function>
		Function __cdecl _rights(_Node*& node, Function& _function) {
			if (node != nullptr) {
				_function(node->value);
				this->_rights(node->right, _function);
			}
			return _function;
		}

		template<typename Function>
		Function __cdecl _s_level(_Node*& node, Function& _function, const ull& level, ull _level = 0) {
			if (node != nullptr) {
				node->level = _level;
				if (node->level == level)
					_function(node->value);
				else if (node->level < level) {
					this->_s_level(node->left, _function, level, _level + 1);
					this->_s_level(node->right, _function, level, _level + 1);
				}
			}
			return _function;
		}

		template<typename HigherPred, typename EqualPred>
		_Node*& __cdecl _find(_Node*& node, Ty& value, HigherPred& _equals, EqualPred& _lower) {
			if (node == nullptr)
				return node;
			else if (_equals(node->value, value))
				return node;
			else if (_lower(node->value, value))
				return this->_find(node->left, value, _equals, _lower);
			else return this->_find(node->right, value, _equals, _lower);
		}

		Ty& __cdecl _min(_Node*& node) {
			if (node->left == nullptr)
				return node->value;

			return this->_min(node->left);
		}

		Ty& __cdecl _max(_Node*& node) {
			if (node->right == nullptr)
				return node->value;
			return this->_max(node->right);
		}

		bool __cdecl _e_side(_Node*& node) {
			if (node->left == nullptr && node->right == nullptr) {
				node = nullptr;
				delete node;
			}
			else if (node->left == nullptr) { node = node->right; }
			else if (node->right == nullptr) { node = node->left; }
			else {
				_Node*& aux = node->right;
				while (aux->left != nullptr)
					aux = aux->left;

				return true;
			}
			return false;
		}

		template<typename HigherPred, typename EqualPred>
		bool __cdecl _erase(_Node*& node, Ty& value, HigherPred& _equals, EqualPred& _lower) {
			if (node == nullptr)return false;

			if (_equals(node->value, value)) {
				if (this->_e_side(node))
					return this->_erase(node->right, node->value);
				else return true;
			}
			else {
				if (_lower(node->value, value))
					return this->_erase(node->left, value);
				else return this->_erase(node->right, value);
			}
		}

		void __cdecl _e_rights(_Node*& node) {
			if (node != nullptr) {
				this->_e_rights(node->right);
				if (node != nullptr && node != this->root) {
					if (this->_e_side(node))
						this->_e_rights(node->right);
				}
			}
		}

		void __cdecl _e_lefts(_Node*& node) {
			if (node != nullptr) {
				this->_e_lefts(node->left);
				if (node != nullptr && node != this->root) {
					if (this->_e_side(node))
						this->_e_lefts(node->left);
				}
			}
		}

		void __cdecl _copy(_Node*& node) {
			if (node != nullptr) {
				this->_insert(this->root, node->value, this->_lower);
				this->_c_height();
				this->_copy(node->left);
				this->_copy(node->right);
			}
		}

		void __cdecl _c_height() {
			if (this->_height < this->a_height)this->_height = this->a_height;
			this->a_height = 0;
		}
    public:
		BasicBinaryTree(const _HiPred& _lower, const _EqPred& _equals) :
			root(nullptr), _size(0), _height(0), a_height(0),
			_lower(_lower), _equals(_equals)
		{}

		void __cdecl operator=(BasicBinaryTree& tree) {
			this->~BasicBinaryTree();
			this->_size = this->a_height = 0;
			this->_lower = tree._lower;
			this->_equals = tree._equals;
			this->_copy(tree.root);
		}
		void __cdecl operator=(BasicBinaryTree*& tree) {
			this->~BasicBinaryTree();
			this->_size = this->a_height = 0;
			this->_copy(tree->root);
		}

		using value_type = Ty;
		using pointer = Ty*;
		using reference = Ty&;

		//apply function to all elements in the tree in order
		template<typename Function>
		Function __cdecl in_order(Function _function) { return this->_in_order(this->root, _function); }
		//apply function to all elements in the tree in reverse order (contrary to in_order)
		template<typename Function>
		Function __cdecl rin_order(Function _function) { return this->_rin_order(this->root, _function); }
		//apply function to all elements in the tree in pre order
		template<typename Function>
		Function __cdecl pre_order(Function _function) { return this->_pre_order(this->root, _function); }
		//apply function to all elements in the tree in post order
		template<typename Function>
		Function __cdecl post_order(Function _function) { return this->_post_order(this->root, _function); }
		//apply function only to more left elements in the tree
		template<typename Function>
		Function __cdecl lefts(Function _function) { if (this->root != nullptr) return this->_lefts(this->root->left, _function); return _function; }
		//apply function only to more right elements in the tree
		template<typename Function>
		Function __cdecl rights(Function _function) { if (this->root != nullptr) return this->_rights(this->root, _function); return _function; }
		//apply function only to more left elements in the tree, incluing the root
		template<typename Function>
		Function __cdecl r_lefts(Function _function) { return this->_lefts(this->root, _function); }
		//apply function only to more right elements in the tree, incluing the root
		template<typename Function>
		Function __cdecl r_rights(Function _function) { return this->_rights(this->root, _function); }
		//return true if erase the first value equal to value in the tree, else false
		bool __cdecl erase(const Ty& value) {
			if (this->_erase(this->root, const_cast<Ty&>(value), this->_equals, this->_lower)) {
				--this->_size;
				return true;
			}

			return false;
		}
		//erase the more right elements in the tree
		void __cdecl e_rights() { this->_e_rights(this->root); }
		//erase the more left elements in the tree
		void __cdecl e_lefts() { this->_e_lefts(this->root); }
		//return true if any element is equal to value else false
		bool __cdecl find(const Ty& value) { return this->_find(this->root, const_cast<Ty&>(value), this->_equals, this->_lower) != nullptr; }
		//return the first element equal to value
		Ty& __cdecl v_find(const Ty& value) {
			_Node* aux = this->_find(this->root, const_cast<Ty&>(value), this->_equals, this->_lower);

			return aux != nullptr ? aux->value : const_cast<Ty&>(value);
		}
		//return the element more left
		Ty& __cdecl min() { return this->_min(this->root); }
		//return the element more right
		Ty& __cdecl max() { return this->_max(this->root); }
		//return size of the tree
		ull __cdecl size() const { return this->_size; }
		//return height of the tree
		ll __cdecl height() const { return this->_height; }
		//return true if tree is empty else false
		bool __cdecl empty() const { return this->_size == 0; }
	
		template<typename Function>
		Function __cdecl for_level(Function _function, const ull& level) { return this->_s_level(this->root, _function, level); }

		void __cdecl clear() {
			delete this->root;
			this->root = nullptr;
			this->_size = this->_height = this->a_height = 0;
		}

	};
}
#endif // !__BASIC_BINARY_TREE_HPP__
