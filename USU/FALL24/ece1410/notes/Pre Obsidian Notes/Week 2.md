9/3/24
TYPES:

Reversed word symbols or keywords:
	Cannot be redefined within a program
	Cannot be used for anything other than their intended use
	Int, str, float, double, etc.

Identifiers:
An identifier is the name of something at appears in a program
	Consists of letters, digits, and the underscore
	Identifiers are case sensitive (number /= NUMBER)
	Two pre-identified identities are cout and cin
	Can be redefined but not a good idea

Data Types:
A data type is a set of values together with a set of allowed operations
	C++ data types have three categories
		Simple data type
		Structured data type
		Pointers

Simple Data Types:
There are three types of simple data
	Integral (integers): Non-decimal numbers
		Can be further categorized: char, short, int, long, bool, unsigned variants
	Floating-point: Decimal numbers
		Double (8 bytes) is twice the space of a float (4 bytes)
		Float values are called single precision, double values are called double precision
	Enumeration: User-defined
	Different compilers may allow different ranges of values

Variable declaration/assignment
	Syntax is: dataType identifier;
		Example: int counter;
	Syntax is: variable = expression;
		Examples: interestRate = 0.05;

Type Safety:
	Language rule: type safety
		Every object will be used according to its type
	Ideal: static type safety
		A program that violates the type safety will not compile
	Ideal: dynamic type safety
		If you write a program that violates type safety it will be detected at run time
	C++ is not very statically or dynamically type-safe, which allows more expression at the risk of bugs
	
Extra Notes:
TUTORING ENGR 320
USE #include <sstream>

9/5/24

5:30 engr 108
ARRAYS:
Array: a variable that can store multiple values of the same type 
	The values are stored in consecutive subscript locations
	Declared using the [] operator,
		const int ISIZE = 5;
		int tests[ISIZE
	Allocates in linear subscripts from 0 to n 
	The size of an array is the number of elements times the number of bytes needed per element
Copying arrays
	for (int indx=0; indx < ISIZE; indx++)
		tests2[indx] = tests[indx];

For Loop:
Syntax:	
	for (data_type var : array)
		statement;
	for (int &score : grades){
		cout << "Enter a score: ";
		cin >> score;
		}
		
Increment Operators:
tests[i]++; //adds 1 to tests[i]
tests[i++]; //increments i but no effects to tests[i]

Try-Catch:
	An exception is a broad class of events in system design used to describe unintended behavior
	throw, try, catch (preceeds try)
[[Week 3]]