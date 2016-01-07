#ifndef _STACKIMPL_
#define _STACKIMPL_

#include "AbsStack.h"

template <typename Object>
class Stack : public AbsStack<Object> {

	private:
		static const int DEF_CAPACITY = 50;
		int capacity;
		int topIndex;
		Object *data;
	
		void doubleData();
			
	public:
		Stack() : AbsStack<Object>(),	
			  capacity {DEF_CAPACITY},
	       		  topIndex {0},	
			  data { new Object[capacity] } {};
		
		~Stack() { delete [] data; };
		void push (const Object & x);
		const Object & pop();
		const Object & top() const;
		bool empty() const;
		void clear();
};

// Sorry about this
#include "../src/Stack.inl"

#endif
