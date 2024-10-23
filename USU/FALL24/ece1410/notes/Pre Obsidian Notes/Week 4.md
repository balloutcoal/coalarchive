Pointers:
	Covered in C, but basically points to the address of the object
	Pointer Variable - a variable that holds an address
		Definition
			int num = 25;
			int *intptr;
			intptr = &num
	Arrays and Pointers
		int vals[] = {4, 7, 11};
		cout << vals; // displays address
		cout << vals[0]; /displays 4
		int *valptr = vals;
		cout << valptr[1]; //displays 7
		cout << *(valptr+1); //displays 7 (must use ())
	Comparing Pointers
		if (prt1 == ptr2){} //compares addresses
		if (*ptr1 == *ptr2){}// compares values
	Dynamic Memory
		Don't have to use malloc
			count = new int;
		Deletion
			delete[] memory
Destructors:
	Basic info
		Special class function similar to constructor
		Called once when a class object becomes out of scope
		Define your own body to do your own cleanup
	Syntax:
		class myClass{
		//code
			public:
			myClass(); //constructor
			~myClass(); //destructor
		}
		myClass_woes:: ~myClass_woes(){
			delete[] my_array; //makes sure dynamic memory is released
		}
	Features
		Like contstructors, no return type
		Unlike constructors, no parameter/arguments
		Only one definition allowed: no overloading
Debugging
	Look into gdb
[[Week 5]]