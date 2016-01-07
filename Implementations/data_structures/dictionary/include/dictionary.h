#ifndef _ARRAYLIST_
#define _ARRAYLIST_

#include <functional>
#include <stdexcept>
#include <iostream>

using namespace std;

/* class Dictionary
 *
 * Class which defines the TAD Dictionary,
 * being a generic interface for different
 * implementations (ordered and unordered, for example).
 *
 * Accepts generic types for key, stored data and 
 * comparison methods for keys, through templates.
 * 
 * KeyComparator must return:
 * 	0, if a equals b
 *	< 0, if a < b
 * 	> 0, if a > b
 *
 * @author Vitor Rodrigues Greati, BTI/IMD/UFRN
 * @date 20/09/2015
 * */
template <typename Key, typename Data, typename KeyComparator = std::equal_to<Key>() >
class Dictionary {
	protected:
		static const int DEF_CAPACITY = 50; // if no inicial capacity is given
		
		int size;		// logic size
		int capacity;		// actual size in memory
		struct Node {
			Key key;	// object key
			Data dat;	// object data
		};
		Node *dataStored;	// pointer to stored data

		/* # searchIntern(_key) : int
		 *
		 * Returns the index of that _key at dataStored member.
		 * If the key doesn't exist, tells where it should be.
		 * Its implementation changes based on the paradigm 
		 * chosen for the list (i.e. binary search or linear search).
		 * */
		virtual int searchIntern(Key _key) const = 0;
	public:
		/* Constructors 
		 * 
		 * + Dictionary()
		 *   Capacity is set to DEF_CAPACITY
		 * + Dictionary(int)
		 *   Accepts the capacity.
		 * */	
		Dictionary(const int & _capacity = DEF_CAPACITY) : size {0}, capacity{ _capacity }, dataStored{ new Node[_capacity] } {};
		
		/* Destroy
		 *
		 * + ~Dictionary()
		 * */
		~Dictionary();

		/* Getters
		 * + getSize() : int
		 *   Return size member
		 * + getCapacity() : int
		 *   Return capacity member
		 *
		 * Public access for some attributes.
		 * */
		int getSize() const { return this->size; }
		int getCapacity() const { return this->capacity; }

		/* + search(_key, _receiver) : bool
		 *
		 * Uses searchIntern(_key) to find the element
		 * and passes its data to the _receiver object.
		 * Its implementation doesn't change at all.
		 * Returns a flag: was the element found or not?
		 * */
		bool search(Key _key, Data & _receiver) const;
		
		/* + remove(_key, _receiver) : bool 
		 * 
		 * Uses searchIntern(_key) to find the element
		 * and delete it from the list if exists.
		 * If fails, return false.
		 * */
		virtual bool remove(Key _key, Data & _receiver) = 0;
		
		/* + insert(_key, _new) : bool 
		 * 
		 * Uses searchIntern(_key) to find that key. If 
		 * doesn't exist, just insert. Otherwise, 
		 * overwrite it.
		 * */
		virtual bool insert(Key _key, Data & _new) = 0;

		/* + max (_receiver) : bool
		 *
		 * Retrieves the greatest key
		 * based on the KeyComparator criterion.
		 * If the dictionary is empty, return false.
		 * */		
		virtual bool max(Key & _keyReceiver) const = 0;
		
		/* + min (_receiver) : bool
		 *
		 * Retrieves the smallest key 
		 * based on the KeyComparator criterion.
		 * If the dictionary is empty, return false.
		 * */
		virtual bool min(Key & _keyReceiver) const = 0;

		/* + predecessor (_key ,_receiver)
		 * 
		 * Retrieves the data of the element whose key is immediately
		 * smaller than the _key passed, following
		 * the KeyComparator criterion. 
		 * */
		virtual bool predecessor(Key _key, Data & _receiver) const = 0;

		/* + sucessor (_receiver)
		 * 
		 * Retrieves the data of the element whose key is immediately
		 * greater than the _key passed, following the
		 * KeyComparator criterion.
		 * */
		virtual bool sucessor(Key _key, Data & _receiver) const = 0;
		
		/* Overloading operator <<
		 *
		 * Print a string representation of the dictionary.
		 * */
		inline friend
		std::ostream & operator<< (std::ostream& _os, const Dictionary<Key, Data, KeyComparator> & _list) {
			_os << "[" << endl;
			for(int i(0); i < _list.size; ++i)
			_os << " { " << (*(_list.dataStored + i)).key << " , " << (*(_list.dataStored + i)).dat << " }" << endl;
			_os << "]\n";
			return _os;
		}
};

/* class DictionaryUnord
 * 
 * Inherits from Dictionary class and implements
 * an unordered dictionary.
 *
 * More information on Dictionary class.
 *
 * @author Vitor Rodrigues Greati, BTI/IMD/UFRN
 * @date 20/09/2015
 * */
template<typename Key, typename Data, typename KeyComparator = std::equal_to<Key> >
class DictionaryUnord : public Dictionary<Key, Data, KeyComparator> {
	
	private:
		static const int DEF_CAPACITY_UNORD = 50;
		
		/* - searchIntern(_key) : int
		 *
		 * Uses linear search for finding a key.
		 * O(n)
		 *
		 * More detailed description at 
		 * Dictionary definition.
		 * */
		int searchIntern(Key _key) const;
	public:
		/* Constructors
		 * 
		 * + DictionaryUnord(int)
		 * + DictionaryUnord()
		 *
		 * Works like the ones at superclass Dictionary.
		 * */
		DictionaryUnord(const int & _capacity = DEF_CAPACITY_UNORD) : Dictionary<Key, Data, KeyComparator>(_capacity) {};
		
		/* + remove(_key, _receiver) : bool 
		 * 
		 * Performs this action in O(1) + O(n), since
		 * it needs to rearrange only the last element.
		 *
		 * More details at Dictionary definition.
		 * */
		bool remove(Key _key, Data & _receiver);
		
		/* + insert(_key, _new) : bool 
		 * 
		 * Performs this action in O(1) + O(n).
		 * Insert always at the end.
		 *
		 * More details at Dictionary definition.
		 * */
		bool insert(Key _key, Data & _new);

		/* + max (_receiver) : bool
		 *
		 * Retrives the greatest key
		 * based on the KeyComparator criterion,
		 * using a linear search.
		 * O(n)
		 * 
		 * More details at Dictionary definition.
		 * */		
		bool max(Key & _keyReceiver) const;
		
		/* + min (_receiver) : bool
		 *
		 * Retrives the smallest key 
		 * based on the KeyComparator criterion,
		 * using a linear search.
		 * O(n)
		 *
		 * More details at Dictionary definition.
		 * */
		bool min(Key & _keyReceiver) const;

		/* + predecessor (_key ,_receiver) : bool
		 * 
		 * Retrieves the data of the element whose key is immediately
		 * smaller than the _key passed, following
		 * the KeyComparator criterion, using a linear search.
		 * O(n).
		 * 
		 * More details at Dictionary definition.
		 * */
		bool predecessor(Key _key, Data & _receiver) const; 

		/* + sucessor (_receiver) : bool
		 * 
		 * Retrieves data of the element whose key is immediately
		 * greater than the _key passed. Following the
		 * the KeyComparator criterion, using a linear search.
		 * O(n).
		 *
		 * More details at Dictionary definition.
		 * */
		bool sucessor(Key _key, Data & _receiver) const; 
};

/* class DictionaryOrd
 * 
 * Inherit from Dictionary class and implements
 * an ordered dictionary.
 *
 * More information on Dictionary class.
 *
 * @author Vitor Rodrigues Greati, BTI/IMD/UFRN
 * @date 20/09/2015
 * */
template<typename Key, typename Data, typename KeyComparator = std::equal_to<Key> >
class DictionaryOrd : public Dictionary<Key, Data, KeyComparator> {
	
	private:
		static const int DEF_CAPACITY_ORD = 50;
		
		/* - searchIntern(_key) : int
		 *
		 * Uses binary search for finding a key.
		 * O(log n)
		 *
		 * More detailed description at 
		 * Dictionary definition.
		 * */
		int searchIntern(Key _key) const;
	public:
		/* Constructors
		 * 
		 * + DictionaryOrd(int)
		 * + DictionaryOrd()
		 * */
		DictionaryOrd(const int & _capacity = DEF_CAPACITY_ORD) : Dictionary<Key, Data, KeyComparator>(_capacity) {};
	
		/* + remove(_key, _receiver) : bool 
		 * 
		 * Performs this action in O(n) + O(log n), since
		 * it needs to rearrange only the last element.
		 *
		 * More details at Dictionary definition.
		 * */
		bool remove(Key _key, Data & _receiver);
		
		/* + insert(_key, _new) : bool 
		 * 
		 * Performs this action in O(n) + O(log n).
		 *
		 * More details at Dictionary definition.
		 * */
		bool insert(Key _key, Data & _new);

		/* + max (_receiver) : bool
		 *
		 * Retrieves the data of the greatest key
		 * based on the KeyComparator criterion.
		 *
		 * More details at Dictionary definition.
		 * */		
		bool max(Key & _keyReceiver) const;
		
		/* + min (_receiver) : bool
		 *
		 * Retrieves the data of the smallest key 
		 * based on the KeyComparator criterion.
		 * 
		 * More details at Dictionary definition.
		 * */
		bool min(Key & _keyReceiver) const;

		/* + predecessor (_key) : bool
		 * 
		 * Retrieves the data of the element whose key is immediately
		 * smaller than the _key passed, following
		 * the KeyComparator criterion. 
		 * 
		 * More details at Dictionary definition.
		 * */
		bool predecessor(Key _key, Data & _receiver) const; 

		/* + sucessor (_receiver) : bool
		 * 
		 * Retrieves the data of the element whose key is immediately
		 * greater than the _key passed. Following the
		 * KeyComparator criterion.
		 * 
		 * More details at Dictionary definition.
		 * */
		bool sucessor(Key _key, Data & _receiver) const; 
};

// Sorry about this
#include "../src/dictionary.cpp"
#include "../src/dictionaryunord.cpp"
#include "../src/dictionaryord.cpp"

#endif
