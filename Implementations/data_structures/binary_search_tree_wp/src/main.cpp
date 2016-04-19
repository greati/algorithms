#include "bst_wp.h"
#include <functional>
#include <iostream>
#include <cstring>

int main(void) {

    BinarySearchTreeWP<int, std::string, std::less<int> > bst;

    std::string s1 = "Vitor";
    std::string s2 = "Maria";

    bst.insert(1, s1);
    bst.insert(2, s2);
    bst.printKeys();
    
    return 0;
}
