#include <functional>
#include <iostream>
#include <cstring>
#include "bst.h"

int main(void) {
	
	BinarySearchTree<int, std::string, std::less<int> > bst;
	std::cout << "Início testes" << std::endl;

	int k1 = 2;
	std::string s1 = "Oi";
	std::string * d1 = bst.insert(k1,s1);
	//std::cout << *d1 << std::endl;
	bst.print_keys(2);
	std::string * ds1 = bst.search(k1);
	if (ds1 != nullptr)
		std::cout << (*ds1) << std::endl;
	int k2 = 3;
	std::string s2 = "Oilá";
	bst.insert(k2,s2);
	bst.print_keys(2);
	std::string * ds2 = bst.search(k2);
	if (ds2 != nullptr)
		std::cout << (*ds2) << std::endl;

	return 0;
}
