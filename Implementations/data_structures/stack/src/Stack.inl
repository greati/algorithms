#include <stdexcept>
#include "Stack.h"

using namespace std;

template <typename Object>
void Stack<Object>::doubleData() {
	Object * _new = new Object[capacity * 2];
	for (auto i(0); i < topIndex; ++i)
		_new[i] = this->data[i];
	delete [] data;
	this->data = _new;
	capacity *= 2;	
}

template <typename Object>
void Stack<Object>::push (const Object & x) {
	if (topIndex == capacity)
		doubleData();
	data[topIndex++] = x;
}

template <typename Object>
const Object & Stack<Object>::pop() {
	if (topIndex == 0)
		throw std::runtime_error("Empty stack.");
	return data[--topIndex];
}

template <typename Object>
const Object & Stack<Object>::top() const {
	if (topIndex == 0)
		throw std::runtime_error("Empty stack.");
	return data[topIndex - 1];
}

template <typename Object>
bool Stack<Object>::empty() const {
	return (!topIndex);
}

template <typename Object>
void Stack<Object>::clear() {
	topIndex = 0;
}

