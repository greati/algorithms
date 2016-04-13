#include "bst_wp.h"

template<typename TKey, typename TData, typename TComp>
typename BinarySearchTreeWP<TKey,TData,TComp>::Node * BinarySearchTreeWP<TKey,TData,TComp>::searchNode(const TKey & key, Node * parentReceiver) const {
	Node * i { root };
	while (i != nullptr and not (not comp(key, i->key) and not comp(i->key, key))) 
		i = comp(key, i->key) ?  i->left : i->right;
	return i;
}

template<typename TKey, typename TData, typename TComp>
TKey * BinarySearchTreeWP<TKey,TData,TComp>::insert(const TKey & newKey, TData & newData) {

}

template<typename TKey, typename TData, typename TComp>
TData * BinarySearchTreeWP<TKey,TData,TComp>::remove(const TKey & keyToRemove) {

}

template<typename TKey, typename TData, typename TComp>
TData * BinarySearchTreeWP<TKey,TData,TComp>::search(const TKey & keyToSearch) const {

}
