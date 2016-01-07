#ifndef _LIST_
#define _LIST_

#include "iterator.h"
#include "const_iterator.h"

namespace Greati {

template<typename T>
class List {

	friend class const_iterator<T>;
	friend class iterator<T>;

	private:
		/**
		 * /brief Represents each element of the list.
		 * */
		struct Node {
			T dat; 		/**< The information itself */
			Node * prev;	/**< Pointer to the previous element */	
			Node * next;	/**< Pointer to the next element */	
			/** \brief Full constructor, takes all attributes. */
			Node(const T & _dat = T(), Node *_prev = nullptr, Node *_next = nullptr) : dat{_dat}, prev{_prev}, next{_next}{};
		};
		
		Node * head;		/**< Pointer to the first element */
		Node * tail;		/**< Pointer to the last element */
		int listsize;		/**< Number of elements in the list */
	
	public:

		/**
		* \brief Initializes head and tail.
		* */
		void init();	
	
		/**
		 * Basic constructor.
		 * */
		List();
	
		/**
		 * Copy constructor.
		 * */
		List (const List<T> & rhs);

		/**
		 * Destroyer.
		 * */
		~List();

		/**
		 * \return Iterator to the first element,
		 * after the head, mutable.
		 * */
		iterator<T> begin();
		
		/**
		 * \return Iterator to the first element,
		 * after the head, constant
		 * */
		const_iterator<T> begin() const;

		/**
		 * \return Iterator to the tail (after the last
		 * element), mutable.
		 * */
		iterator<T> end();

		/**
		 * \return Iterator to the tail (after the last
		 * element), constant.
		 * */
		const_iterator<T> end() const;

		/**
		 * Overloading assignment operator.
		 * */
		const List<T> & operator=(const List<T> & rhs);

		/**
		 * \return The size of the list. 
		 * */
		int size() const;

		/**
		 * \return True, if list is empty; false if not.
		 * */
		bool empty() const;

		/**
		 * Clear the list, makes it empty.
		 * */
		void clear();

		/**
		 * \return The first element, mutable.
		 * */
		T & front();

		/**
		 * \return The first element, constant.
		 * */
		const T & front() const;

		/**
		 * \return The last element, mutable.
		 * */
		T & back();

		/**
		 * \return The last element, constant.
		 * */
		const T & back() const;
	
		/**
		 * Insert element at the beginning.
		 * */	
		void push_front(const T & obj);

		/**
		 * Insert element at the end.
		 * */
		void push_back(const T & obj);
		
		/**
		 * Remove the first element.
		 * */
		void pop_front();

		/**
		 * Remove the last element.
		 * */
		void pop_back();

		/**
		 * Insert element at a position defined by an iterator. 
		 * */
		iterator<T> insert(iterator<T> itr, const T & obj);
	
		/**
		 * Erase element at position specified by an iterator.
		 * */
		iterator<T> erase(iterator<T> itr);

		/**
		 * Erase elements in the range specified, from
		 * start to end (exclusive).
		 * */
		iterator<T> erase(iterator<T> start, iterator<T> end);

		/**
		 * \return An interator to the searched element, constant.
		 * */
		const_iterator<T> find(const T & obj) const;
		
		/**
		 * \return An interator to the searched element, mutable.
		 * */
		iterator<T> find(const T & obj);

		/**
		 * \brief Print a representation of the list.
		 * */
		inline friend
		std::ostream & operator<<(std::ostream & out, const List<T> & list) {
			out << "[ ";
			for (auto i (list.begin()); i != list.end(); ++i) 
				out << *i << " ";
			out << "]" << std::endl;	
			return out;
		}
};

};

// Sorry about this
#include "../src/List.cpp"

#endif
