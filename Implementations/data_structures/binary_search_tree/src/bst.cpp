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

template<typename TKey, typename TData, typename TLessComp>
typename BinarySearchTree<TKey, TData, TLessComp>::TreeNode * BinarySearchTree<TKey, TData, TLessComp>::sucessor_intern(TreeNode * ofNode) const {
	if (ofNode->right != nullptr)
		return minimum_intern(ofNode->right);
	TreeNode * parentOfNode = ofNode->parent;
	while (parentOfNode != nullptr and (not TLessComp(ofNode->key, parentOfNode->right->key) and not TLessComp(parentOfNode->right->key, ofNode->key))) {
		ofNode = parentOfNode;
		parentOfNode = ofNode->parent;
	}
	return parentOfNode;
}

template<typename TKey, typename TData, typename TLessComp>
typename BinarySearchTree<TKey, TData, TLessComp>::TreeNode * BinarySearchTree<TKey, TData, TLessComp>::predecessor_intern(TreeNode * ofNode) const {
	if (ofNode->left != nullptr)
		return minimum_intern(ofNode->left);
	TreeNode * parentOfNode = ofNode->parent;
	while (parentOfNode != nullptr and (not TLessComp(ofNode->key, parentOfNode->left->key) and not TLessComp(parentOfNode->left->key, ofNode->key))) {
		ofNode = parentOfNode;
		parentOfNode = ofNode->parent;
	}
	return parentOfNode;
}

template<typename TKey, typename TData, typename TLessComp>
TData * BinarySearchTree<TKey, TData, TLessComp>::sucessor(const TKey & ofNodeKey) const {
	TreeNode * node = search_intern(ofNodeKey);
	if (node != nullptr)
		return sucessor_intern(node);
	return nullptr;
}

template<typename TKey, typename TData, typename TLessComp>
TData * BinarySearchTree<TKey, TData, TLessComp>::predecessor(const TKey & ofNodeKey) const {
	TreeNode * node = search_intern(ofNodeKey);
	if (node != nullptr)
		return predecessor_intern(node);
	return nullptr;

}

template<typename TKey, typename TData, typename TLessComp>
TData * BinarySearchTree<TKey, TData, TLessComp>::insert(const TKey & newKey, TData newData) {
	TreeNode * newNode {newKey, newData};		
	TreeNode * leader = root;
	TreeNode * trail = nullptr;
	while (leader != nullptr) {
		if (TLessComp(newKey, leader->key))
			leader = leader->left;	
		else if (TLessComp(leader->key, newKey))
			leader = leader->right;	
		trail = leader;
	}
	newNode->parent = trail;
	if (trail == nullptr)
		root = newNode;
	else if(TLessComp(newKey, trail->key))
		trail->left = newNode;	
	else
		trail->right = newNode;

	return newNode->data;
}

template<typename TKey, typename TData, typename TLessComp>
void BinarySearchTree<TKey, TData, TLessComp>::transplant(TreeNode * n1, TreeNode * n2) {
	if (n1->parent == nullptr)
		root = n2;		
	else if (n1->parent->left == n1)
		n1->parent->left = n2;
	else 
		n1->parent->right = n2;
	if (n2 != nullptr)
		n2->parent = n1->parent;
}

template<typename TKey, typename TData, typename TLessComp>
bool BinarySearchTree<TKey, TData, TLessComp>::remove(const TKey & keyToFind) {
	TreeNode * nodeToDelete = search_intern(keyToFind);			
	if (nodeToDelete != nullptr) {
		if (nodeToDelete->left == nullptr)
			transplant(nodeToDelete, nodeToDelete->right);	
		else if (nodeToDelete->right == nullptr)
			transplant(nodeToDelete, nodeToDelete->left);	
		else {
			TreeNode * nodeSucessor = sucessor_intern(nodeToDelete);	
			if (nodeSucessor->parent != nodeToDelete) {
				transplant(nodeSucessor, nodeSucessor->right);	
				nodeSucessor->right = nodeToDelete->right;
				nodeSucessor->right->parent = nodeSucessor;
			}
			transplant(nodeToDelete, nodeSucessor);
			nodeSucessor->left = nodeToDelete->left;
			nodeSucessor->left->parent = nodeSucessor;
		}
		return true;
	}
	return false;
}
