#include "bst_wp.h"
#include <functional>
#include <iostream>
#include <cstring>

int main(void) {

    BinarySearchTreeWP<int, std::string, std::less<int> > bst;

    std::string s1 = "Vitor";

    bst.insert(2, s1);
    bst.insert(4, s1);
    bst.insert(3, s1);
    bst.insert(6, s1);
    bst.insert(1, s1);
    bst.printKeys();
    bst.remove(2);
    bst.printKeys();
    
    return 0;
}
