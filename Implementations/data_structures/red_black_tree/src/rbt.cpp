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

template<typename TKey, typename TData, typename TLessComp>
TData * RedBlackTree<TKey, TData, TLessComp>::insert(const TKey & newKey, TData newData) {
	TreeNode * newNode = new TreeNode {newKey, newData, Color::RED};
	TreeNode * trail = nil;
	TreeNode * leader = root;	

	while (leader != nil) {
		trail = leader;
		if (comp(newKey, leader->key))
			leader = leader->left;
		if (comp(leader->key, newKey))
			leader = leader->right;
	}

	newNode->parent = trail;

	if (root == nil)
		root = newNode;
	else if (comp(trail->key, newKey))
		trail->right = newNode;
	else if (comp(newKey, trail->key))
		trail->left = newNode;
	
	fix_up(newNode);

	return &(newNode->data);
}	
