#include "iterator.h"
#include "const_iterator.h"
#include "List.h"

namespace Greati { 

template<typename T>
iterator<T>::iterator() : const_iterator<T>::const_iterator() {};

template<typename T>
const T & iterator<T>::operator*() const {
		return (this->current->dat);
	}

template<typename T>
T & iterator<T>::operator*() {
		return (this->current->dat);
}

template<typename T>
iterator<T> & iterator<T>::operator++() {
	this->current = this->current->next;
	return *this;	
}

template<typename T>
iterator<T> iterator<T>::operator++(int) {
	this->current = this->current->next;
	return *this;	
}

template<typename T>
iterator<T> & iterator<T>::operator--() {
	this->current = this->current->prev;
	return *this;	
}

template<typename T>
iterator<T> iterator<T>::operator--(int) {
	this->current = this->current->prev;
	return *this;	
}

template<typename T>
iterator<T>::iterator(typename List<T>::Node *p) : const_iterator<T>::const_iterator(p) {};

};
