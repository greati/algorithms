#ifndef _CIT_
#define _CIT_

#include "List.h"
#include "iterator.h"

namespace Greati {

// because List is used, but not defined yet
template<typename T>
class List;

template<typename T>
class const_iterator {

	friend class List<T>;

	public:
		/**
		 * Basic constructor.
		 * */
		const_iterator();
		
		/**
		 * Overloading * (acessor) operator.
		 * */	
		const T & operator*() const;

		/**
		 * Overloading ++ (increment) operator.
		 * */
		const_iterator & operator++();
		const_iterator operator++(int);

		/**
		 * Overloading -- (decrement) operator.
		 * */
		const_iterator & operator--();
		const_iterator operator--(int);

		/**
		 * Overloading == (equals) operator.
		 * */
		bool operator==(const const_iterator &) const;

		/**
		 * Overloading != (not equal) operator
		 * */
		bool operator!=(const const_iterator &) const;

	protected:
		typename List<T>::Node * current; /**< Pointer to the current element. */
		
		/**
		 * Constructor that gets a node to point.
		 * */
		const_iterator(typename List<T>::Node *p);

};

};

// Sorry about this
#include "../src/const_iterator.cpp"

#endif

