#include "dictionary.h"
#include <stdexcept>

template <typename Key, typename Data, typename KeyComparator>
int DictionaryUnord<Key, Data, KeyComparator>::searchIntern(Key _key) const {
	KeyComparator comp;
	// starts a linear search
	for (auto i(0); i < this->size; ++i)
		if (comp(_key, ((this->dataStored) + i)->key) == 0)
			return i;
	// if not found, the last position is where a new element should be, so return it
	return (this->size);	
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryUnord<Key, Data, KeyComparator>::remove(Key _key, Data & _receiver) {
	// search for the object to remove
	int targetIndex = searchIntern(_key);
	// if not found, following the rule of searchIntern method, return false
	if (targetIndex == (this->size)) 
		return false;		
	// if found, pass a copy to the client
	_receiver = ((this->dataStored) + targetIndex)->dat;
	// and put the last element at the deleted object's position
	((this->dataStored) + targetIndex)->dat = ((this->dataStored) + (this->size - 1))->dat; 
	((this->dataStored) + targetIndex)->key = ((this->dataStored) + (this->size - 1))->key; 
	// decrement logic size
	--(this->size);
	return true;	
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryUnord<Key, Data, KeyComparator>::insert(Key _key, Data & _new) {
	// search for that key
	int existKeyIndex = searchIntern(_key);		
	// check if it exists
	if (existKeyIndex != (this->size)) {
		// exists, so overwrite the data at that key
		(this->dataStored + existKeyIndex)->dat = _new;
		return true;
	// doesn't exist
	} else {
		// if the dictionary is not full
		if ((this->size) < (this->capacity)) {
			// make the new node
			(this->dataStored + (this->size))->key = _key;	
			(this->dataStored + (this->size))->dat = _new;
			// and increment logic size
			++(this->size);
			return true;
		}
	}
	// something went wrong
	return false;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryUnord<Key, Data, KeyComparator>::max(Key & _keyReceiver) const {
	KeyComparator comp;
	int indexMax = 0;
	// fails if dictionary is empty
	if (this->size == 0) return false;
	// performs a simple search for maximum key
	for (int i (0); i < this->size; ++i)
		if (comp((*(this->dataStored + i)).key, (*(this->dataStored + indexMax)).key) > 0)
			indexMax = i;
	_keyReceiver = (this->dataStored + indexMax)->key;
	return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryUnord<Key, Data, KeyComparator>::min(Key & _keyReceiver) const {
	KeyComparator comp;
	int indexMin = 0;
	// fails if dictionary is empty
	if (this->size == 0) return false;
	// performs a simple search for minimum key
	for (int i (0); i < this->size; ++i)
		if (comp((*(this->dataStored + i)).key , (*(this->dataStored + indexMin)).key) < 0)
			indexMin = i;
	_keyReceiver = (this->dataStored + indexMin)->key;
	return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryUnord<Key, Data, KeyComparator>::sucessor(Key _key, Data & _receiver) const {
	KeyComparator comp;
	// search for that key
	int indexKey = searchIntern(_key);
	// if it doesn't exist, error
	if (indexKey == (this->size)) return false;		
	int indexSuc = indexKey;
	for (int i (0); i < this->size; ++i)
		// take element greater than _key
		if (comp((*(this->dataStored + i)).key, (*(this->dataStored + indexKey)).key) > 0)
			// if it's the smallest until now
			if (comp((*(this->dataStored + i)).key, (*(this->dataStored + indexSuc)).key) < 0 || (indexSuc == indexKey))
				indexSuc = i; // take it
	if (indexSuc == indexKey) return false; // no sucessor
	_receiver = (*(this->dataStored + indexSuc)).dat;
	return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryUnord<Key, Data, KeyComparator>::predecessor(Key _key, Data & _receiver) const {
	KeyComparator comp;
	int indexKey = searchIntern(_key);
	// if it doesn't exist, error
	if (indexKey == (this->size)) return false;		
	int indexPred = indexKey;
	for (int i (0); i < this->size; ++i)
		// take element smaller than _key
		if (comp((*(this->dataStored + i)).key, (*(this->dataStored + indexKey)).key) < 0)
			// if it's the greatest until now
			if (comp((*(this->dataStored + i)).key, (*(this->dataStored + indexPred)).key) > 0 || (indexPred == indexKey))
				indexPred = i; // take it
	if (indexPred == indexKey) return false; // no predecessor
	_receiver = (*(this->dataStored + indexPred)).dat;
	return true;
}
