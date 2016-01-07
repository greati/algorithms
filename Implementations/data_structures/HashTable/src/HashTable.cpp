#include "HashTbl.h"
#include <iostream>

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
HashTbl<KeyType, DataType, KeyHash, KeyEqual>::HashTbl(unsigned int _tblSize) : size { _tblSize }, countElements { 0 } {
	dataTable = new std::list<Entry>[_tblSize];
} 

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
HashTbl<KeyType, DataType, KeyHash, KeyEqual>::~HashTbl() {
	clear();
	delete [] dataTable;
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::search(const KeyType & _k, typename std::list<Entry>::iterator & it) const {
	KeyEqual equalFunc;
	size_t hashed = performHash(_k); 
	// Searching for an equal key, if has, overwrite and return false
	for (auto i ((dataTable + hashed)->begin()); i != (dataTable + hashed)->end(); ++i) {
		if (equalFunc((*i).key, _k)) {
			it = i;
			return true;
		}
	}
	return false;
}	

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
size_t HashTbl<KeyType, DataType, KeyHash, KeyEqual>::performHash(const KeyType & _k) const{
	KeyHash hashFunc;
	return (hashFunc(_k) % size);	
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::insert (const KeyType & _k, const DataType & _d) throw (std::bad_alloc) {
	Entry _new {_k, _d};
	typename std::list<Entry>::iterator it;
	// Search for repeated key
	if (search(_k, it)) {
		(*it).data = _d;
		return false;
	}
	// Normal insertion
	dataTable[performHash(_k)].push_back(_new);
	++countElements;
	return true;
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::remove (const KeyType & _k) {
	typename std::list<Entry>::iterator it;
	size_t hashed = performHash(_k);
	// Search
	if (search(_k, it)) {
		(dataTable + hashed)->erase(it);			
		--countElements;
		return true;
	}
	// Key not found, not removed	
	return false;
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::retrieve (const KeyType & _k, DataType & _d) const {
	typename std::list<Entry>::iterator it;
	// Search
	if (search(_k, it)) {
		_d = (*it).data;
		return true;
	}
	// Key not found	
	return false;
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::clear (void) {
	for (auto i (dataTable); i != (dataTable + size); ++i) {
		i->clear();
	}
	countElements = 0;
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::empty (void) const {
	return (countElements == 0);
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
unsigned long int HashTbl<KeyType, DataType, KeyHash, KeyEqual>::count (void) const {
	return countElements;
}

template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::showStructure (void) const {
	int j = 0;
	std::cout << "Hash Table (size = " << size << ")" << std::endl;
	for (auto i (dataTable); i != (dataTable + size); ++i, j++) {
		std::cout << j << " - [ ";
		for (auto it (i->begin()); it != (i->end()); ++it) {
			std::cout << " { ";
			std::cout << (*it).data.personName;
			std::cout << " } ";
		}
		std::cout << " ] " << std::endl;
	}
}

