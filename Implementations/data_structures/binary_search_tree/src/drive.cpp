#include <functional>
#include <iostream>
#include <cstring>
#include "bst.h"

int main(void) {
	
	BinarySearchTree<int, std::string, std::less<int> > bst;

	int k1 = 2;
	std::string s1 = "Oi";
	bst.insert(k1,s1);
	bst.print_keys(2);
	int k2 = 3;
	std::string s2 = "Oi";
	bst.insert(k2,s2);
	bst.print_keys(2);

	return 0;
}
