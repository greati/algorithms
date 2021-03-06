#ifndef _BST_
#define _BST_

template<typename TKey, typename TData, typename TLessComp>
class BinarySearchTree {

	private:
		struct TreeNode {
			TKey key;
			TData data;
			TreeNode * left;
			TreeNode * right;
			TreeNode * parent;

			/** 
			 * Empty constructor.
			 * */
			TreeNode(){};

			/**
			 * Full constructor.
			 * */
			TreeNode(TKey k, TData d, TreeNode * l, TreeNode * r, TreeNode * p) : 
			key {k}, data {d}, left {l}, right {r}, parent {p}{};

			/**
			 * Key, Data constructor.
			 * */
			TreeNode(TKey k, TData d) : 
			key {k}, data {d}, left {nullptr}, right {nullptr}, parent {nullptr}{};
		};

		TreeNode * root;

		TLessComp comp;


		/**
		 * \brief Prints all keys ordered from a certain node.
		 * \details Uses inorder-tree-walk algorithm to print
		 * all keys ordered.
		 * 
		 * O(n)
		 * */
		void print_keys(TreeNode *) const;

		TreeNode * search_intern(const TKey &) const;
		TreeNode * minimum_intern(TreeNode * rootNode) const;
		TreeNode * maximum_intern(TreeNode * rootNode) const;
		TreeNode * sucessor_intern(TreeNode * ofNode) const;
		TreeNode * predecessor_intern(TreeNode * ofNode) const;
		
		/**
		 * \brief Cuts of the subtree rooted at n1, replacing it by 
		 * subtree rooted at n2.
		 * */
		void transplant(TreeNode * n1, TreeNode * n2);
		
	public:
		/**
		 * Constructor.
		 * */
		BinarySearchTree() : root {nullptr} {};

		/**
		 * \brief Prints all keys ordered from a certain node
		 * using it's key as identifier.
		 * \details Uses inorder-tree-walk algorithm to print
		 * all keys ordered.
		 * 
		 * O(n)
		 * */
		void print_keys(const TKey & key) const;

		/**
		 * \brief Search for a node by its key.
		 * \details Uses an iterative approach. Takes
		 * O(h), being h the height of the tree.
		 * */
		TData * search(const TKey &) const;

		/**
		 * \brief Returns the element with minimum key.
		 * \details Takes O(h).
		 * */
		TData * minimum() const;
		
		/**
		 * \brief Returns the element with maximum key.
		 * \details Takes O(h).
		 * */
		TData * maximum() const;

		/**
		 * \brief Returns a sucessor of a node.
		 * \details A sucessor of a node x is defined as the node with the smallest key
		 * greater than x's key. Takes O(h).
		 * */
		TData * sucessor(const TKey & ofNodeKey) const;
		
		/**
		 * \brief Returns a predecessor of a node.
		 * \details A predecessor of a node x is defined as the node with the greatest key
		 * smaller than x's key. Takes O(h).
		 * */
		TData * predecessor(const TKey & ofNodeKey) const;

		/**
		 * \brief Insert a new node in the tree.
		 * \details It finds the right place to put the node.
		 * \return Pointer to the data of the new node.
		 * */
		TData * insert(const TKey & newKey, TData newData);

		/**
		 * \brief Deletes a node from the tree.
		 * \details 
		 * \return 
		 * */
		bool remove(const TKey & newKey);
};

#include "../src/bst.cpp"
#endif
