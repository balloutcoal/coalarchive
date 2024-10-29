#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

template <typename T>
class List{
	private:
		Node<T>* head; //Points to head of list
		int size; //List size
	public:
		List():head(nullptr), size(0) {} //Constructor
		
		~List(){ //Destructor
			reset();
		}
		
		void insert(T value){ //Adds to list creating new node
			Node<T>* newNode = new Node<T>(value);
			newNode->setNext(nullptr);
			if(head == nullptr){
				head = newNode; //Insert as first node
			}else{
				Node<T>* curr = head;
				while(curr->getNext() != nullptr){
					curr = curr->getNext();
				}
				curr->setNext(newNode); //Insert at end
			}
			size++;
		}
		
		T at(int index) const{ //Checks value in list
			if(index < 0 || index >= size){
				throw std::out_of_range("Index out of range"); //DEBUG
			}
			Node<T>* curr = head;
			for(int i = 0; i < index; ++i){
				curr = curr->getNext();
			}
			return curr->getData();
		}
		
		bool contains(T data) const{ //Checks if node exists
			Node<T>* curr = head;
			while(curr){
				if(curr->getData() == data){
					return true;
				}
				curr = curr->getNext();
			}
			return false;
		}
		
		//NOTE: I cannot for the life of me figure out the segmentation fault happening at the removes
		void remove(T data){ //Remove and return last of list
			Node<T>* curr = head;
			Node<T>* prev = nullptr;
			while(curr){
				if(curr->getData() == data){
					if(prev == nullptr){
						head = curr->getNext();
					}else{
						prev->setNext(curr->getNext());
					}
					delete curr;
					size--;
					return;		
				}
				prev = curr;
				curr = curr->getNext();
			}
		}
		
		void reset(){ //Clears the list
			while(head){
				Node<T>* temp = head;
				head = head->getNext();
				delete temp;
			}
			size = 0;
		}
		
		int count() const{ //Returns list size
			return size;
		}
		
		string toString() const{ //Turns list into string
			stringstream ss;
			Node<T>* curr = head;
			while(curr){
				ss << curr->getData() << " ";
				curr = curr->getNext();
			}
			return ss.str();
		}
	
};

#endif //LIST_HPP