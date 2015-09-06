#include "myvector.h"
#include <stdexcept>
#include <initializer_list>

namespace Greati {

	template<typename T>
	Vector<T>::Vector(int psize) : vecSize{ psize }, vecData{ new T[psize] } {
		if (psize <= 0)
			throw std::invalid_argument("Vector:Vector(int, const T&) : Invalid size.");	
	}

	template<typename T>
	Vector<T>::Vector(int psize, const T & value) : vecSize{ psize }, vecData{ new T[psize] } {
		if (psize <= 0)
			throw std::invalid_argument("Vector:Vector(int, const T&) : Invalid size.");
		for (int i = 0; i < vecSize; ++i) 
			*(vecData + i) = value;
	}

	template<typename T>
	Vector<T>::Vector(const initializer_list<T> & list) : vecSize{ list.size() }, vecData{ new T[vecSize] } {
		typename initializer_list<T>::iterator it;
		it = list.begin();
		for (int i = 0; it != list.end(); ++it, i++)
			*(this->vecData + i) = (*it);
	}

	template<typename T>
	Vector<T>::Vector(const Vector & tocopy) : vecSize{tocopy.vecSize}, vecData{ new T[tocopy.vecSize] } {
		for (int i = 0; i < vecSize; ++i)
			*(vecData + i) = *(tocopy.vecData + i);
	}	

	template<typename T>
	Vector<T>::~Vector() {
		delete [] vecData;
	}

	template<typename T>
	int Vector<T>::size(void) const {
		return vecSize;
	}

	template<typename T>
	void Vector<T>::fill(const T & value) {
		for (int i = 0; i < vecSize; ++i)
			*(vecData + i) = value;
	}

	template<typename T>
	T& Vector<T>::operator[](int index) {
		if (index < 0 && index > vecSize - 1)
			throw std::out_of_range("Error: Index out of range.");
		return *(vecData + index);
	}
	
	template<typename T>
	const T Vector<T>::operator[](int index) const {
		if (index < 0 && index > vecSize - 1)
			throw std::out_of_range("Error: Index out of range.");
		return *(vecData + index);
	}

	template<typename T>
	bool Vector<T>::operator==(const Vector & rhs) const {
		if (this->vecSize != rhs.vecSize) return false;
		for (int i = 0; i < this->vecSize; ++i)
			if (*(this->vecData + i) != *(rhs.vecData + i)) return false;
		return true;
	}
	
	template<typename T>
	const Vector<T> & Vector<T>::operator=(const Vector & rhs) {
		if (this != &rhs) {
			if (rhs.vecSize != (this->vecSize)) {
				delete [] (this->vecData);
				(this->vecData) = new T[rhs.vecSize];
				this->vecSize = rhs.vecSize;
			}
			for (int i = 0; i < rhs.vecSize; ++i)
				*((this->vecData) + i) = *(rhs.vecData + i); 
		}
		return *this;
	}

	template<typename T>
	const Vector<T> & Vector<T>::operator=(const initializer_list<T> & rhs) {
		if (rhs.size() != (this->vecSize)){
			delete [] (this->vecData);
			this->vecData = new T[rhs.size()];
			this->vecSize = rhs.size();	
		}
		typename initializer_list<T>::iterator it;
		it = rhs.begin();
		for (int i = 0; it != rhs.end(); ++it, i++)
			*(this->vecData + i) = (*it);

		return *this;
	} 
	
}
