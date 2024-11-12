#ifndef BST_HPP
#define BST_HPP
#include "Node.hpp"

template <typename T>
class BST {
    private:
        Node<T>* root; //pointer to root of tree
    public:
        BST():root(nullptr){} //constructor

        //test case functions + extra credit
        void insert(const T& data);
        bool contains(const T& data);
        Node<T>* search(const T& data);
        int count() const;
        void remove(const T& data);

};

void BST<T>::insert(const T& data){
    if(root == nullptr){
        root = new node<T>(data);  
        return;
    }

}

#endif