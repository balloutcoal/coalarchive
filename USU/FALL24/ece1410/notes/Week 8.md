# Function Templates
* A skeleton for creating definitions of functions that differ only in the type of data they manipulate
* Code logic is agnostic of data type
* They can be better than overloaded functions, since the code defining the algorithm of the function is only written once
## Example
### Templates
```
void swap(int &x, int &y){
	int temp = x; x = y;
	y = temp;  
}  

void swap(char &x, char &y){
	char temp = x; x = y;
	y = temp;  
}  
```
### Swap Template
```
template<class T>

void saw(int &x, int &y){
	T temp = x; x = y;
	y = temp;
}
```
## Using a Template Function
* When a function defined by a template is called, the compiler creates the actual definition from the template by inferring the type of the type parameters from the arguments in the call:
```
int i = 1, j = 2;
swap(i,j);
```
* This code makes the compiler instantiate the template with type int in place of the type parameter T
# Class Templates
it's fucking impossible to take notes in this class
# Linked Lists
## Definition
* A chain of structures or objects (called nodes)
* Each node is an array length 2 where 0 is the contents and 1 is a pointer to the next node
* A pointer keeps track of the "head" of the list
* The last node's pointer points to NULL/nullptr
### Why?
* A linked list is more flexible than an array
	* Can grow/shrink as needed without wasting memory or going out of bounds
	* Much easier to store data
* Access is slower, you must start as HEAD and step node to node
## Example
Define the Node
```
Class Contact{
	public:
		Contact(string ln, string fn, string num);
		string getFirstName();
		string getLastName();
		string getNumber();
		Contact *getNext();
		void setNext(Contact *p);
	private:
		string first_name;
		string last_name;
		string number;
		Contact *next;
};
```
Define the list
```
class List{
	public:
		Contact (string ln, string fn, string fn, string num);
		void printList();
		~List();
	private:
		Contact *head; //HEAD POINTER
};
```
Add node function
```
void List::addNode(string ln, string fn, string num){
	Contact *p, *cur, *prev;
	p = new Contact(ln, fn, num);
	...
	for (cur = head, prev = NULL;
		cur != NULL && p->getLastName() > cur->getLastName();
		prev = cur, cur = cur->getNext());
		
	p->setNext(cur);
	if (prev == NULL) {
		head = p;
	}else{
		prev->setNext(p);
	}
}
```
# Stacks and Queues
## Stack
* LIFO - Last in, First out
* Identical to a "stack" of books on a table
	* Insertions and removals take place from the same end
	* PUSH - insertion
	* POP - Removal
# Inheritance
will be absent look into notes