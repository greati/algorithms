#include "bst_wp.h"

template<typename TKey, typename TData, typename TComp>
typename BinarySearchTreeWP<TKey,TData,TComp>::Node * BinarySearchTreeWP<TKey,TData,TComp>::searchNode(const TKey & key, Node * parentReceiver) const {
	Node * i { root };
	while (i != nullptr and not (not comp(key, i->key) and not comp(i->key, key))) 
		parentReceiver = i, i = comp(key, i->key) ?  i->left : i->right;
	return i;
}

template<typename TKey, typename TData, typename TComp>
TKey * BinarySearchTreeWP<TKey,TData,TComp>::insert(const TKey & newKey, TData & newData) {
    Node * p, res;
    res = searchNode(newKey, p);
    if (res == nullptr) {
        Node * n = new Node {newKey, newData};
        (newKey > p->key) ? p->left = n : p.right = n;
        return &(n->key);
    }
    return nullptr;
}

template<typename TKey, typename TData, typename TComp>
void BinarySearchTreeWP<TKey,TData,TComp>::transplant(const Node * & from, const Node * & to) {
    Node * p {nullptr};
    searchNode(from->key, p); 
    if (p->left == from)
        p->left = to;
    else if (p->right == from)
        p->left = to;
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
        //TODO 
    }
}

template<typename TKey, typename TData, typename TComp>
TData * BinarySearchTreeWP<TKey,TData,TComp>::search(const TKey & keyToSearch) const {
    Node * res = searchNode(keyToSearch);
    return res != nullptr ? &(res->data) : nullptr; 
}
