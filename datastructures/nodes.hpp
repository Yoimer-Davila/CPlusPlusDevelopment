#ifndef __NODES_HPP__
#define __NODES_HPP__

namespace datastructures {

    //long long
    using ll = long long;
    //const long long
    using cll = const long long;
    //unsigned long long
    using ull = unsigned long long;
    //const unsigned long long
    using cull = const unsigned long long;

    template <typename Ty>
    struct basic_node {
        using _node = basic_node;
        using _node_ptr = basic_node*;
        using _node_ref = basic_node&;
        Ty value;
        basic_node* next;

        basic_node(const Ty& value, const basic_node*& next) : next(next), value(value) {}
	    basic_node(const Ty& value) : value(value), next(nullptr) {}
	    ~basic_node() { delete next; }
    };
    
    template <typename Ty>
    struct basic_bnode {
        using _bnode = basic_bnode;
        using _bnode_ptr = basic_bnode*;
        using _bnode_ref = basic_bnode&;

        Ty value;
        _bnode_ptr next;
	    _bnode_ptr back;

        basic_bnode(const Ty& value, const _bnode*& next, const _bnode*&back) : 
		value(value), back(back), next(next) {}
	    basic_bnode(const Ty& value) : value(value), back(nullptr), next(nullptr) {}
	    ~basic_bnode() { delete this->next, this->back; }
    };

    template<typename Ty>
    struct basic_bynode {
        using _bynode = basic_bynode;
        using _bynode_ptr = basic_bynode*;
        using _bynode_ref = basic_bynode&;

        Ty value;
        ull level, height;
        _bynode_ptr right, left;

        basic_bynode(const Ty& value, ull level, ull height = 0) 
            : value(value), level(level), height(height), left(nullptr), right(nullptr) {}

        basic_bynode(const Ty& value, const _bynode_ptr& right, const _bynode_ptr& left, ull level, ull height = 0) 
            : value(value), level(level), height(height), right(right), left(left) {}

        ~basic_bynode() { delete this->left, this->right; }
    };
}

#endif //__NODES_HPP__