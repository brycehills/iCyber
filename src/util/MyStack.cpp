#include "MyStack.h"

template<class Type>
MyStack<Type>::MyStack()  {

}

template<class Type>
MyStack<Type>::~MyStack()  {

}

template<class Type>
void MyStack<Type>::push(Type theObject)  {
	theStack.push(theObject);
}

template<class Type>
void MyStack<Type>::pop()  {
	try {
		if (theStack.empty()) {
			throw 0;
		}
		theStack.pop();
	}
	catch (...) {
		cerr << "\nCould not pop - stack empty!\n";
	}

}

template<class Type>
unsigned int MyStack<Type>::size()  {
	return theStack.size();
}

template<class Type>
Type MyStack<Type>::top()  {
	return 	theStack.top();
}

template<class Type>
bool MyStack<Type>::empty()  {
	return 	theStack.empty();
}

template<class Type>
Type MyStack<Type>::Get(unsigned int index)  {
	Type returnObject;
	stack<Type> outputStack = theStack;
	unsigned int loopIndex = 0;
	bool found = false;

	try {
		if (index < 0 || index > theStack.size()) {
			throw index;
		}
		while (!outputStack.empty() && !found) {
			if (loopIndex == index) {
				returnObject = outputStack.top();
				found = true;
			}
			else {
				outputStack.pop();
				loopIndex++;
			}
		}
	}
	catch (unsigned int e) {
		cerr << "\nError: Invalid index\n";
	}

	return returnObject;
}
