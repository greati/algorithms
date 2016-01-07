#include "List.h"
#include "iterator.h"

namespace Greati {

template<typename T>
void List<T>::init() {
	head = new Node;
	tail = new Node;
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
	listsize = 0;
}

template<typename T>
List<T>::List() {
	init();
}

template<typename T>
List<T>::List(const List<T> & rhs) {
	if (this != &rhs) {
		init();				
		auto i = rhs.begin();
		while (i != rhs.end()) {
			push_back(*i); 
			++i;
		}
	} 
}

template<typename T>
List<T>::~List() {
	clear();	
	delete head;
	delete tail;
}

template<typename T>
iterator<T> List<T>::begin() {
	return { head->next };	
}

template<typename T>
const_iterator<T> List<T>::begin() const {
	return { head->next };	
}

template<typename T>
iterator<T> List<T>::end() {
	return { tail };	
}

template<typename T>
const_iterator<T> List<T>::end() const {
	return { tail };	
}

template<typename T>
const List<T> & List<T>::operator=(const List<T> & rhs) {
	if (this != &rhs) {
		init();				
		auto i = rhs.begin();
		while (i != rhs.end()) {
			push_back(*i); 
			++i;
		}
	} 
	return *this;
}

template<typename T>
T & List<T>::front() {
	return *begin();
}

template<typename T>
const T & List<T>::front() const {
	return *begin();
}

template<typename T>
T & List<T>::back() {
	return *(end()--);
}

template<typename T>
const T & List<T>::back() const {
	return *(end()--);
}

template<typename T>
int List<T>::size() const {
	return listsize;
}

template<typename T>
bool List<T>::empty() const {
	return (begin() == end());
} 

template<typename T>
void List<T>::clear() {
	if (listsize > 0)
		erase(begin(), end());	
}

template<typename T>
void List<T>::push_front(const T & obj) {
	insert(begin(), obj);	
}

template<typename T>
void List<T>::push_back(const T & obj) {
	insert(end(), obj);
}

template<typename T>
void List<T>::pop_front() {
	erase(begin());
}

template<typename T>
void List<T>::pop_back() {
	erase(end()--);
}

template<typename T>
iterator<T> List<T>::insert(iterator<T> itr, const T & obj) {
	Node * _new = new Node(obj, (itr.current->prev), (itr.current)); 		
	_new->prev->next = _new;
	_new->next->prev = _new;
	++listsize;
	return { _new }; 
}

template<typename T>
iterator<T> List<T>::erase(iterator<T> itr) {
	(itr.current)->next->prev = (itr.current->prev);
	(itr.current)->prev->next = (itr.current->next);
	iterator<T> nextElement {itr.current->next};
	delete (itr.current);
	--listsize;
	return end();
}

template<typename T>
iterator<T> List<T>::erase(iterator<T> start, iterator<T> end) {
	while (start != end) {
		erase(start);
		++start;
	}
	return end;
}

template<typename T>
iterator<T> List<T>::find(const T & obj) {
	iterator<T> start = begin();
	while (*start != obj && start != end()) ++start;
	return start; 
}

template<typename T>
const_iterator<T> List<T>::find(const T & obj) const {
	const_iterator<T> start = List<T>::begin();
	while (*start != obj && start != end()) ++start;
	return start; 
}

};
