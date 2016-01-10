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
	int k3 = 4;
	std::string s3 = "max";
	bst.insert(k3,s3);
	bst.print_keys(2);
	std::string * ds3 = bst.search(k3);
	if (ds3 != nullptr)
		std::cout << (*ds3) << std::endl;
	int k4 = 1;
	std::string s4 = "Min";
	bst.insert(k4,s4);
	bst.print_keys(2);
	std::string * ds4 = bst.search(k4);
	if (ds4 != nullptr)
		std::cout << (*ds4) << std::endl;
	std::string * m = bst.minimum();
	std::cout << *m << std::endl;
	std::string * ma = bst.maximum();
	std::cout << *ma << std::endl;
	std::string * suc = bst.sucessor(3);
	std::cout << *suc << std::endl;
	std::string * pred = bst.predecessor(3);
	std::cout << *pred << std::endl;
	
	bst.remove(2);	
	bst.print_keys(3);

	return 0;
}
