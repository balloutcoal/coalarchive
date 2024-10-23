Backtracking Algorithms
	Steps
		Incrementally build a solution candidate
		Abandon partial candidate (AKA backtracked) as soon as deemed valid
	More efficient than "brute force" method
	Gives us an ordered method to build a solution
	What if there is no solution?

Midterm - NO RECURSION

USE PAPER TO HELP UNDERSTAND CODE

REVIEW:
	**CONSTRUCTORS**, STATIC VARIALBES, REFRENCE VARIABLES (&), POINTERS (*), array modification,
	conditional operators (if statement ? then : else), 
	
	C++ General
		Object Oriented Programming allows to allow/restrict specific data mambers to be interacted with

	Variables:
		Static Variables 
			When a function is called as a static it will retain the value every other time it was called
			
	Streams:
		include <iostream> handles cin and cout
		cin >> variable
		cout << "text" << varialbe << endl; (endl optional)
	Functions:
	
	Pointers and Arrays:
		Definition:
			int *intptr; //* placement does not matter in the whitespace)
			int num = 25; //integer
			intptr = &num //intptr has the value of num's address
			cout << intptr //prints num's address
			cout << *intptr //print num's value, 25
			*intptr = 20 //sets sum to 20
		Explanation:
			assignment of a pointer is *var, and interacting with var will be the address while
				*var is the value var is pointing to
		Pointer arrays:
			Arrays are pointers, printing array vals will be the address while vals[i]
				will be the ith value of the array
			Another way to print arrays is printing *vals will be the first item in the array
				while *(vals + i) will be the ith value of the array
			A pointer towards an array will be the exact same
				int *valptr = vals; //valptr and vals are pointing at the same value
				cout << *valptr (or valptr[0]); //displays the first value
			Incrementing a pointer through valptr++ where it goes from the first value
				to the second, and valptr-- does the same just going down an address
		Initialization:
			Pointers can point to nothing
				int *ptr = NULL;, int *ptr = nullptr;, int *ptr{};
		Comparison:
			if(ptr1 == ptr2) //compares addresses
			if(*ptr1 == *ptr2) //compares contents
		**FUNCTION PARAMETERS:
			Requires
				Asterisk on parameter in prototype and header
					void getNum(int *ptr);
				Asterisk in body to dereference
					cin >> *ptr;
				Address as argument to function in call
					getNum(&num);
					void function(int *x, int y){
						*x = *x + y + 3;
						y = *x
					}
					function(&num1, num2); //call
		Smart Pointers:
			Designed to help solve
				Dangling pointers - deleted memory while pointer is still in use
				Memory leaks - allocated memory that is no longer needed
				Double deletion - two pointers deallocating the same memory
			Types
				Unique pointers (unique_ptr)
					Points to a dynamically allocated object with a single owner
					Ownership can be transferred to another unique pointer
					Memory for the object is deallocated when the unique pointer goes
						out of scope, or changes what it is pointing to
					Example (requires <memory>):
						unique_ptr<int> uptr(new int);
						*uptr = 5
						unique_ptr<int> uptr2;
						uptr2 = move(uptr) //any object owned by uptr is deallocated and uptr takes 
							ownership of uptr
				Shared pointers (shared_ptr)
					Owns/manages the object it points to
					Points to a dynamically allocated object that can have multiple ownership
					Control block manages the reference count of the number of shared owners/raw pointers
					
				Weak pointers (weak_ptr)
	
	Classes:
		class Date{
			public: //private variables are only available to be used within the class
			int m_month, m_day, m_year;
			void OutputMonth(); //prototype, does not need anything passed through the function
			void Date::OutputMonth(){
				...
			}
		};
		Constructors 
			Special member functions to create/construct new objects
			Automatically called when an new object is created
				implicit: Date today;
				explicit: Date today(10, 15, 2014)
			Constructor definition (within a class):
				Date::Date(int m, int d, int y){
					SetMonth(m); //assuming these functions are defined
					SetDay(d);
					SetYear(y);
				}
				
	
	Operator Overloading:
		'this' pointer
			Implicit parameter passed to every member function
			Points to the object calling the function
			Can be used to access members that may be hidden by parameters with the same name
			Example:
				class AClass{
					private:
					int num;
					public:
					void setNum(int num){
						this->num = num;
					}
				};
		'const' member function
			Does not modify the calling object
			
BANK ACCOUNT EXAMPLE:
	A function in a class: BankAccount::BankAccount(); does not need any parameters within the class
	Using this->variable = value is good practice but this-> is not needed here
[[Week 8]]