#ifndef _AVL_TREE
#define _AVL_TREE

template<typename TKey, typename TData, typename TCompLess>
class AVLTree {

	private:
		struct Node {
			TKey key;
			TData data;
			Node * left;
			Node * right;
			char balance;
			Node() {};
			Node(const & TKey k, const & TData d = new TData) : key {k}, data {d}, left {nil}, right {nil} {};
			Node(const & TKey k, const & TData d, Node * l, Node * r) : key {k}, data {d}, left {l}, right {r} {};
		};

		Node * root;
		Node * nil;
	public:
		AVLTree() {
			nil = new Node {-1};
			root = nil;
		};

};

#include "../src/avl_tree.inl"
#endif
