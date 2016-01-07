#include "dictionary.h"

template <typename Key, typename Data, typename KeyComparator>
int DictionaryOrd<Key, Data, KeyComparator>::searchIntern(Key _key) const {
	KeyComparator comp;
	int l = 0, h = (this->size) - 1;
	// keeps the key greater than _key at each iteration
	int ifNotFound = this->size;
	// binary search
	while (l <= h) {
		int m = l + (h - l) / 2;
		int resComp = comp(_key, (this->dataStored + m)->key);
		if (resComp == 0) { 
			return m;
		} else if (resComp < 0) { 
			h = m - 1, ifNotFound = m;
		} else {
			l = m + 1;
		}
	}
	// if _key no found, returns where it should be
	return ifNotFound;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryOrd<Key, Data, KeyComparator>::remove(Key _key, Data & _receiver) {
	KeyComparator comp;
	int targetIndex = searchIntern(_key);
	// if trying to delete an nonexistent object
	if (comp((this->dataStored + targetIndex)->key,_key) != 0) return false;		
	// found, passes the data to the client
	_receiver = ((this->dataStored) + targetIndex)->dat;
	// shift elements to the left
	for (auto i(targetIndex); i < ((this->size) - 1); ++i) { 
		*(this->dataStored + i) = *(this->dataStored + (i + 1));
	}
	// decrement logic size
	--(this->size);
	return true;	
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryOrd<Key, Data, KeyComparator>::insert(Key _key, Data & _new) {
	KeyComparator comp;
	int existKeyIndex = searchIntern(_key);		
	// if element already exists, overwrite
	if (existKeyIndex < this->size && comp((this->dataStored + existKeyIndex)->key,_key) == 0) {	
		(this->dataStored + existKeyIndex)->dat = _new;
		return true;
	// if it doesn't
	} else {
		// if list isn't full
		if ((this->size) < (this->capacity)) {
			// shift to the right
			for (auto i(this->size); i > existKeyIndex; --i) {
				*(this->dataStored + i) = *(this->dataStored + (i - 1));
			}
			// insert element at the right position
			(this->dataStored + existKeyIndex)->key = _key;
			(this->dataStored + existKeyIndex)->dat = _new;
			// increment logic size
			++(this->size);
			return true;
		} else return false; // fail
	}
	return false; // fail
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryOrd<Key, Data, KeyComparator>::max(Key & _keyReceiver) const {
	// if list is empty, fail
	if (this->size == 0) return false;
	// if not, takes the last element
	_keyReceiver = (this->dataStored + (this->size - 1))->key;
	return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryOrd<Key, Data, KeyComparator>::min(Key & _keyReceiver) const {
	// if list is empty, fail
	if (this->size == 0) return false;
	// if not, takes the first element
	_keyReceiver = (this->dataStored)->key;
	return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryOrd<Key, Data, KeyComparator>::sucessor(Key _key, Data & _receiver) const {
	KeyComparator comp;
	int indexKey = searchIntern(_key);
	// if it's the last element, fail
	if (indexKey == (this->size) - 1 || (comp((this->dataStored + indexKey)->key,_key) != 0)) return false;
	// if it's not, passes the data to the client
	_receiver = (*(this->dataStored + (indexKey + 1))).dat;	
	return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DictionaryOrd<Key, Data, KeyComparator>::predecessor(Key _key, Data & _receiver) const {
	KeyComparator comp;
	int indexKey = searchIntern(_key);
	// if it's the first element, fail
	if (indexKey == 0 || (comp((this->dataStored + indexKey)->key,_key) != 0)) return false;
	// if it's not, passes the data to the client
	_receiver = (*(this->dataStored + (indexKey - 1))).dat;	
	return true;
}
