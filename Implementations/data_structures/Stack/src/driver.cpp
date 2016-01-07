#include "Stack.h"
#include <iostream>

using namespace std;

int main(void) {

	Stack<int> pilha;

	pilha.push(1);	
	pilha.push(3);	
	pilha.push(5);	
	pilha.push(7);	
	pilha.push(9);

	//pilha.clear();	

	while (!pilha.empty()) {
		cout << pilha.top() << endl;
		pilha.pop();	
	}

	return 0;
}
