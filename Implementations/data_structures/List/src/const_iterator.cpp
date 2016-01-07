#include "const_iterator.h"
#include "List.h"

namespace Greati {

template<typename T>
const_iterator<T>::const_iterator() : current {nullptr} {};

template<typename T>
const T & const_iterator<T>::operator*() const {
	return (this->current->dat);
}

template<typename T>
const_iterator<T> & const_iterator<T>::operator++() {
	this->current = this->current->next;
	return *this;	
}

template<typename T>
const_iterator<T> const_iterator<T>::operator++(int) {
	this->current = this->current->next;
	return *this;	
}

template<typename T>
const_iterator<T> & const_iterator<T>::operator--() {
	this->current = this->current->prev;
	return *this;	
}

template<typename T>
const_iterator<T> const_iterator<T>::operator--(int) {
	this->current = this->current->prev;
	return *this;	
}

template<typename T>
bool const_iterator<T>::operator==(const const_iterator<T> & obj) const {
	return obj.current == this->current;
}


template<typename T>
bool const_iterator<T>::operator!=(const const_iterator<T> & obj) const {
	return obj.current != this->current;
}

template<typename T>
const_iterator<T>::const_iterator(typename List<T>::Node *p) {
	this->current = p;	
}

};
