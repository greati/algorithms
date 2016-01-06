#include <iostream>
#include "bst.h"

template<typename TKey, typename TData, typename TLessComp>
void BinarySearchTree<TKey, TData, TLessComp>::print_keys(TreeNode * root) const {
	print_keys(root->left);
	std::cout << root->key << std::endl;
	print_keys(root->right);
}


template<typename TKey, typename TData, typename TLessComp>
typename BinarySearchTree<TKey, TData, TLessComp>::TreeNode * BinarySearchTree<TKey, TData, TLessComp>::search_intern(const TKey & keyToFind) const {
	TreeNode * it = root;
	while (it != nullptr and not (TLessComp(it->key, keyToFind) and TLessComp(keyToFind, it->key))) {
		if (TLessComp(keyToFind, it->key))
			it = it->left;
		else 
			it = it->right;
	}
	return it;
}

template<typename TKey, typename TData, typename TLessComp>
typename BinarySearchTree<TKey, TData, TLessComp>::TreeNode * BinarySearchTree<TKey, TData, TLessComp>::minimum_intern(TreeNode * rootNode) const {
	TreeNode * nodeReceiver = rootNode;
	while (nodeReceiver->left != nullptr)
		nodeReceiver = nodeReceiver->left;	
	return nodeReceiver;
}

template<typename TKey, typename TData, typename TLessComp>
typename BinarySearchTree<TKey, TData, TLessComp>::TreeNode * BinarySearchTree<TKey, TData, TLessComp>::maximum_intern(TreeNode * rootNode) const {
	TreeNode * nodeReceiver = rootNode;
	while (nodeReceiver->right != nullptr)
		nodeReceiver = nodeReceiver->right;
	return nodeReceiver;
}

template<typename TKey, typename TData, typename TLessComp>
TData * BinarySearchTree<TKey, TData, TLessComp>::search(const TKey & keyToFind) const {
	TreeNode * res = search_intern(keyToFind, root);
	if (res != nullptr)
		return &(res->data);
	return nullptr;
}

template<typename TKey, typename TData, typename TLessComp>
TData * BinarySearchTree<TKey, TData, TLessComp>::minimum() const {
	TreeNode * res = minimum_intern(root);
	return (res != nullptr ? &(res->data) : nullptr);
}

template<typename TKey, typename TData, typename TLessComp>
TData * BinarySearchTree<TKey, TData, TLessComp>::maximum() const {
	TreeNode * res = maximum_intern(root);
	return (res != nullptr ? &(res->data) : nullptr);
}
