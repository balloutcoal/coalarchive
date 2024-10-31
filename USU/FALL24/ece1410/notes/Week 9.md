# Type Compatibility in Inheritance Hierarchies
* Classes in a program can be part of an inheritance hierarchy
* Classes in the lower hierarchies are special cases of those higher
* Example: [[Inheritance Hierarchy.canvas|Inheritance Hierarchy]]
## Type Compatibility in Inheritance
//TODO: fill in notes

# Polymorphism
* Consider [[Inheritance Hierarchy.canvas|Inheritance Hierarchy]] where each class has its own version of the member function 'id()'
```
class Animal{
	void id(){cout << "animal";}
};

class Cat : public Animal{
	void id(){cout << "cat";}
};

class Dog : public Animal{
	void id(){cout << "dog";}
};
```
* Consider a collection of different Animal objects
```
Animal *pA[] = {new Animal, new Dog, new Cat};
```
* And accompanying code,
```
for(int k = 0; k < 3; k++) pA[k]->id(); //pA[k]->id() only sees Animal pointer
```
* This would just print 'animal animal animal' ignoring the dog/cat id types
* The code just listed is NOT polymorphic, so the following code will be adjusted to fix that
## Virtual Functions
* To make the function polymorphic, the ids must be declared as virtual
```
class Animal{
	virtual void id(){cout << "animal";}
};

class Cat : public Animal{
	virtual void id(){cout << "cat";}
};

class Dog : public Animal{
	virtual void id(){cout << "dog";}
};
```
* Virtual fun
# PROGRAM 8: BANK