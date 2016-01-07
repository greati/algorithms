#ifndef _IT_
#define _IT_

#include "const_iterator.h"
#include "List.h"

namespace Greati {

template<typename T>
class iterator : public const_iterator<T>{
	
	friend class List<T>;
	
	public:
		/**
		 * Basic constructor, calls superclass constructor.
		 * */
		iterator();
		
		/**
		 * Overloading * (acessor), constant.
		 * */
		const T & operator* () const;

		/**
		 * Overloading * (acessor), mutable.
		 * */
		T & operator*();	
	
		/**
		 * Overloading ++ (increment) operator.
		 * */
		iterator & operator++();
		iterator operator++(int);

		/**
		 * Overloading -- (decrement) operator.
		 * */
		iterator & operator--();
		iterator operator--(int);

	protected:
		/**
		 * Constructor that waits for a position to
		 * set the pointer.
		 * */
		iterator(typename List<T>::Node *p);

};

};
// Sorry about this
#include "../src/iterator.cpp"

#endif
