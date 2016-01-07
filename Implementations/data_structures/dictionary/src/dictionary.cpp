#include "dictionary.h"

template <typename Key, typename Data, typename KeyComparator>
Dictionary<Key, Data, KeyComparator>::~Dictionary() {
	delete [] (this->dataStored);
}

template <typename Key, typename Data, typename KeyComparator>
bool Dictionary<Key, Data, KeyComparator>::search(Key _key, Data & _receiver) const {
	KeyComparator comp;
	int internalSearchResult = searchIntern(_key);
	// test if the element was not found
	if (internalSearchResult == this->size || 
            comp((this->dataStored + internalSearchResult)->key, _key) != 0) 
		return false;	
	// if the element exists, give it to the client
	_receiver = (dataStored + internalSearchResult)->dat;
	return true;
}

