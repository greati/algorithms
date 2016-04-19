#ifndef _BSTWP_
#define _BSTWP_


/**
 * \brief Implements a Binary Search Tree without
 * using a parent pointer.
 *
 * \author Vitor Greati
 * \since 04/01/2016
 * \version 1.0
 **/
template<typename TKey, typename TData, typename TComp>
class BinarySearchTreeWP {

    private:
        struct Node {
            TKey key;
            Node * left;
            Node * right;
            TData data; 
            Node(const TKey & k, const TData & d) 
                : key {k}, left {nullptr}, right {nullptr}, data {d} {};
            Node(const TKey & k, Node * l , Node * r, const TData & d) 
                : key {k}, left {l}, right {r}, data {d} {};
        };
    
        Node * root;
   
        TComp comp; 
    
        Node * searchNode(const TKey & key, Node * & parentReceiver = nullptr) const;
        Node * minNode (Node * root) const;
        void transplant(Node * & from, Node * & to);

    public:
        
        BinarySearchTreeWP() : root {nullptr} {};

        TKey * insert(const TKey & newKey, TData & newData);
        TData * remove(const TKey & keyToRemove);
        TData * search(const TKey & keyToSearch) const;
        void printKeys(Node * r) const;
        void printKeys() const;
};

// Sorry
#include "../src/bst_wp.cpp"

#endif
