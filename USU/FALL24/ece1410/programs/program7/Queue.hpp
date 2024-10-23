#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Node.hpp"

using namespace std;
 
template <typename T>
class Queue{
	private:
	Node<T>* head; //Points to head of queue
	Node<T>* back; //Points to back of queue
	int size;
	public:
	Queue():head(nullptr), back(nullptr), size(0){} //Constructor
	
	void enqueue(T value){
		Node<T>* newNode = new Node<T>(value);
		if(back){
			back->setNext(newNode);
		}
		back = newNode;
		if(head == nullptr){
			head = newNode;
		}
		size++;
	}
	
	T dequeue(){
		Node<T>* temp = head;
		head = head->getNext();
		T value = temp->getData();
		delete temp;
		size--;
		if(size == 0){
			back = nullptr;
		}
		return value;
	}
	
	T front() const{
		return head->getData();
	}
	
	void reset(){
		while(head){
			Node<T>* temp = head;
			head = head->getNext();
			delete temp;
		}
		back = nullptr;
		size = 0;
	}
	
	int count() const{
		return size;
	}
	
	bool isEmpty() const{
		return size == 0;
	}
	
};

#endif //QUEUE_HPP