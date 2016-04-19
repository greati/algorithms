#include <iostream>
#include "bst_wp.h"

template<typename TKey, typename TData, typename TComp>
typename BinarySearchTreeWP<TKey,TData,TComp>::Node * BinarySearchTreeWP<TKey,TData,TComp>::searchNode(const TKey & key, Node * & parentReceiver) const {
	Node * i { root };
	while (i != nullptr and not (not comp(key, i->key) and not comp(i->key, key))) { 
		parentReceiver = i;
        i = comp(key, i->key) ? i->left : i->right;
	}
    return i;
}

template<typename TKey, typename TData, typename TComp>
TKey * BinarySearchTreeWP<TKey,TData,TComp>::insert(const TKey & newKey, TData & newData) {
    Node * p = nullptr;
    Node * res = searchNode(newKey, p);
    if (res == nullptr) {
        Node * n = new Node {newKey, newData};
        if (p == nullptr)
            root = n;
        else 
            (newKey > p->key) ? p->right = n : p->left = n;
        return &(n->key);
    }
    return nullptr;
}

template<typename TKey, typename TData, typename TComp>
void BinarySearchTreeWP<TKey,TData,TComp>::transplant(Node * & from, Node * & to) {
    Node * p {nullptr};
    searchNode(from->key, p);
    if (p != nullptr) { 
        if (p->left == from)
            p->left = to;
        else if (p->right == from)
            p->right = to;
    } else root = to;
}


template<typename TKey, typename TData, typename TComp>
typename BinarySearchTreeWP<TKey,TData,TComp>::Node * BinarySearchTreeWP<TKey,TData,TComp>::minNode(Node * root) const {
    while (root->left != nullptr)
        root = root->left; 
    return root;
}

template<typename TKey, typename TData, typename TComp>
void BinarySearchTreeWP<TKey,TData,TComp>::printKeys(Node * r) const {
    if (r != nullptr) {
        std::cout << r->key << std::endl;
        if (r->left != nullptr)  
            printKeys(r->left);
        if (r->right != nullptr)
            printKeys(r->right); 
    }
}

template<typename TKey, typename TData, typename TComp>
void BinarySearchTreeWP<TKey,TData,TComp>::printKeys() const {
    printKeys(root); 
}

template<typename TKey, typename TData, typename TComp>
TData * BinarySearchTreeWP<TKey,TData,TComp>::remove(const TKey & keyToRemove) {
    Node * p = nullptr;
    Node * toRemove = searchNode(keyToRemove, p);
    if (toRemove->left == nullptr)
        transplant(toRemove, toRemove->right);
    else if (toRemove->right == nullptr)
        transplant(toRemove, toRemove->left);
    else {
        Node * suc = minNode(toRemove->right);
        if (toRemove->right != suc) {
            transplant(toRemove, toRemove->right);
            suc->right = toRemove->right;
        }
        transplant(toRemove, suc);
        suc->left = toRemove->left;
    }
}

template<typename TKey, typename TData, typename TComp>
TData * BinarySearchTreeWP<TKey,TData,TComp>::search(const TKey & keyToSearch) const {
    Node * res = searchNode(keyToSearch);
    return res != nullptr ? &(res->data) : nullptr; 
}
