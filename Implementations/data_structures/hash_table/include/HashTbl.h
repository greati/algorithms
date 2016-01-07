#ifndef _HASH_
#define _HASH_

#include <functional>
#include <string>
#include <list>

/**
 * \brief Class that represents an entry in the hash table.
 * */
template<typename KeyType, typename DataType>
class HashEntry {
	public:
		HashEntry (KeyType _k, DataType _d) : key {_k}, data{_d} {};
		KeyType key;
		DataType data;
};

/**
 * \brief Class that represents a Hash Table.
 * \authors Vitor Greati, Vinicius Campos
 * */
template<typename KeyType, typename DataType, typename KeyHash = std::hash<KeyType>, typename KeyEqual = std::equal_to<KeyType>>
class HashTbl {
	public:
		
		typedef HashEntry <KeyType, DataType> Entry;

		/**
		 * \brief Simple constructor.
		 * \param[in] _tblSize HashTable size.
		 * */
		HashTbl (unsigned int _tblSize = DEFAULT_SIZE);

		/**
		 * \brief Destructor.
		 * */
		virtual ~HashTbl();
		
		/**
		 * \brief Inserts an information at the Hash Table.
		 * \param[in] _k The key.
		 * \param[in] _d The information to be inserted.
		 * \return false, if key exists and the information was overwritten, true otherwise.
		 * */
		bool insert (const KeyType & _k, const DataType & _d) throw (std::bad_alloc);
		
		/**
		 * \brief Removes an information from the Hash Table.
		 * \param[in] _k The key.
		 * \return true, if key exists; false otherwise.
		 * */
		bool remove (const KeyType & _k);
		
		/**
		 * \brief Retrieves an information from Hash Table.
		 * \param[in] _k The key.
		 * \param[out] _d The information.
		 * \return true, if key exists; false otherwise.
		 * */
		bool retrieve (const KeyType & _k, DataType & _d) const;
		
		/**
		 * \brief Clear Hash Table.
		 * */
		void clear (void);

		/**
		 * \brief Check if Hash Table is empty.
		 * \return true if it is empty, false otherwise. 
		 * */
		bool empty (void) const;
		
		/**
		 * \brief Counts number of elements in Hash Table.
		 * \return the number of entries.
		 * */
		unsigned long int count (void) const;

		/**
		 * \brief Show Hash Table structure as string.
		 * */
		void showStructure(void) const;
	private:
		unsigned int size;				/**< Size of Hash Table. */ 
		unsigned int countElements; 			/**< Number of elements. */ 
		std::list<Entry> * dataTable;			/**< The data. */ 
		static const short DEFAULT_SIZE = 10;		/**< Default size. */
				
		/**
		 * \brief Returns the corresponding hash for a given key.
		 * \param[in] _k The key.
		 * \returns The corresponding hash.
		 * */
		size_t performHash(const KeyType & _k) const;
		
		/**
		 * \brief Searches for a key and find an iterator for it.
		 * \param[in] _k The key.
		 * \param[out] it Iterator for the element with that key.
		 * \returns True if found, false otherwise.
		 * */
		bool search(const KeyType & _k, typename std::list<Entry>::iterator & it) const;	
};

// Sorry about this
#include "../src/HashTable.cpp"

#endif
