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
		};

		TreeNode * root;

		TreeNode * search_intern(const TKey &) const;
		TreeNode * minimum_intern(TreeNode * rootNode) const;
		TreeNode * maximum_intern(TreeNode * rootNode) const;
		
	public:
		/**
		 * \brief Prints all keys ordered.
		 * \details Uses inorder-tree-walk algorithm to print
		 * all keys ordered.
		 * 
		 * O(n)
		 * */
		void print_keys(TreeNode *) const;

		/**
		 * \brief Search for a node by its key.
		 * \details Uses an iterative approach. Takes
		 * O(h), being h the height of the tree.
		 * */
		TData * search(const TKey &) const;

		/**
		 * \brief Returns the element with minimum key.
		 * */
		TData * minimum() const;
		
		/**
		 * \brief Returns the element with maximum key.
		 * */
		TData * maximum() const;
};

#include "../src/bst.cpp"
#endif
