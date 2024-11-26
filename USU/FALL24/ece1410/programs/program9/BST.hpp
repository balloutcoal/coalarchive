#ifndef BST_HPP
#define BST_HPP
#include "Node.hpp"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class BST {
    private:
        Node<T>* root; //pointer to root of tree
        int nodecount = 0;
    public:
        BST():root(nullptr){} //constructor

        //test case functions + extra credit
        void insert(const T& data); //insert data in tree
        bool contains(const T& data); //checks if tree contains data
        string search(const T& data); //checks if tree contains data plus path
        int count() const; //the count of each node in the tree
        void remove(const T& data); //remove a node from the tree
};

template <typename T>
void BST<T>::insert(const T& data){
    if(root == nullptr){ //if tree is empty
        root = new Node<T>(data); //insert data
        nodecount += 1; //add one to nodecount
        //cout << "ROOT INSERT !!DEBUG" << endl; //DEBUG
        return;
    }

    Node<T>* current = root; //pointer to node
    while(current != nullptr){ //while branch isn't null keep traversing through
        if(data < current->getData()){ //check left side
            if(current->getLeft() == nullptr){ //make sure left is empty
                current->setLeft(new Node<T>(data)); //insert left data
                //cout << "LEFT INSERT !!DEBUG" << endl; //DEBUG
                break;
            }
            //cout << "LEFT !!DEBUG" << endl; //DEBUG
            current = current->getLeft(); //else keep moving left
        }else if(data > current->getData()){ //check right side
            if(current->getRight() == nullptr){ //make sure right is empty
                current->setRight(new Node<T>(data)); //insert right data
                //cout << "RIGHT INSERT !!DEBUG" << endl; //DEBUG
                break;
            }
            //cout << "RIGHT !!DEBUG" << endl; //DEBUG
            current = current->getRight(); //else keep moving right
        }else return; //if data is equal do nothing
    }
    nodecount += 1; //add one to nodecount
    return;
}

template <typename T>
bool BST<T>::contains(const T& data){
    Node<T>* current = root; //pointer to node
    while(current != nullptr){ //while branch isn't null keep traversing through
        if(data == current->getData()){ //if node is found
            //cout << "CONTAINS FOUND !!DEBUG" << endl; //DEBUG
            return true;
        }else if(data < current->getData()){ //check left
            //cout << "CONTAINS LEFT !!DEBUG" << endl; //DEBUG
            current = current->getLeft(); //move left
        }else if(data > current->getData()){ //check right
            //cout << "CONTAINS RIGHT !!DEBUG" << endl; //DEBUG
            current = current->getRight(); //move right
        }
    }
    //cout << "CONTAINS NOT FOUND !!DEBUG" << endl; //DEBUG
    return false; //not found
}

template <typename T>
string BST<T>::search(const T& data){
    Node<T>* current = root; //pointer to node
    if(root == nullptr) return "Tree is empty."; //if tree is empty
    //cout << "SEARCH ROOT !!DEBUG" << endl; //DEBUG
    ostringstream oss;
    oss << current->getData(); //janky typename to string shenanigains
    string route = "root(" + oss.str() + ")"; //start route string with root data

    while(current != nullptr){ //while branch isn't null keep traversing through
        if(data == current->getData()){ //check if found
            //cout << "SEARCH FOUND !!DEBUG" << endl; //DEBUG
            return "Found: " + route; //return found
        }else if(data < current->getData()){ //check left
            current = current->getLeft(); //move left
            if(current != nullptr){ //if left isn't emtpy
                //cout << "SEARCH LEFT !!DEBUG" << endl; //DEBUG
                oss.str(""); //clear oss
                oss << current->getData(); //janky typename to string shenanigains
                route += "->left(" + oss.str() + ")"; //add left data to route string
            }
        }else if(data > current->getData()){ //check right
            current = current->getRight(); //move right
            if(current != nullptr){ //if right isn't empty
                //cout << "SEARCH RIGHT !!DEBUG" << endl; //DEBUG
                oss.str(""); //clear oss
                oss << current->getData(); //janky typename to string shenanigains
                route += "->right(" + oss.str() + ")"; //add right data to route string
            }
        }
    }
    //cout << "SEARCH NOT FOUND !!DEBUG" << endl; //DEBUG
    return "Not found: " + route; //data not found in tree
}

template <typename T>
int BST<T>::count() const{
    //cout << "NODECOUNT" + to_string(nodecount) + " !!DEBUG" << endl; //DEBUG
    return nodecount; //returns node count refrenced in insert and remove
}


template <typename T>
void BST<T>::remove(const T& data){
    //cout << "hello" << endl;
    return;
}

#endif