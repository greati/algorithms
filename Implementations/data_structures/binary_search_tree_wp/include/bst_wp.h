#ifndef _BSTWP_
#define _BSTWP_

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
    
    public:
        
        BinarySearchTreeWP() : root {nullptr} {};

        void insert(const TKey & newKey, TData & newData);
        void remove(const TKey & keyToRemove);
        void search(const TKey & keyToSearch);

};


#endif
