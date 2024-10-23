#ifndef STACK_HPP
#define STACK_HPP

#include "Node.hpp"

using namespace std;

template <typename T>
class Stack{
	private:
	Node<T>* topval; //Points to top of stack
	int size;
	public:
		Stack():topval(nullptr), size(0){} //Constructor
		
		void push(T value){ //Pushes value to top of list creating a new node
			Node<T>* newNode = new Node<T>(value); //New node
			newNode->setNext(topval);
			topval = newNode;
			size++;
		}
		
		T pop(){ //Removes top element of stack removing node returning popped value
			Node<T>* temp = topval;
			topval = topval->getNext();
			T value = temp->getData();
			delete temp;
			size--;
			return value;
		}
		
		T top() const{ //Returns top value
			return topval->getData();
		}
		
		void reset(){
			while(topval){
				Node<T>* temp = topval;
				topval = topval->getNext();
				delete temp;
			}
			size = 0;
		}
		
		int count() const{
			return size;
		}
};

#endif //STACK_HPP