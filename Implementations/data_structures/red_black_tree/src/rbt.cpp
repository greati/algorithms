#include "rbt.h"

template<typename TKey, typename TData, typename TLessComp>
void RedBlackTree<TKey, TData, TLessComp>::left_rotate(TreeNode * node) {
	if (node->right == nil) return;

	TreeNode * newRoot = node->right;

	node->right = newRoot->left;	
	if (newRoot->left != nil)
		newRoot->left->parent = node;

	newRoot->parent = node->parent;

	if (node->parent == nil)
		root = newRoot;
	else if (node->parent->left == node)
		node->parent->left = newRoot;
	else
		node->parent->right = newRoot;

	newRoot->left = node;
	node->parent = newRoot;
}


template<typename TKey, typename TData, typename TLessComp>
void RedBlackTree<TKey, TData, TLessComp>::right_rotate(TreeNode * node) {
	if (node->left == nil) return;
	
	TreeNode * newRoot = node->left;

	node->left = newRoot->right;
	if (newRoot->right != nil)
		newRoot->right->parent = node;

	newRoot->parent = node->parent;

	if (node->parent == nil)
		root = newRoot;
	else if (node->parent->left == node)
		node->parent->left = newRoot;
	else
		node->parent->right = newRoot;

	newRoot->left = node;
	node->parent = newRoot;
}
