#ifndef UTIL_MYSTACK_H_
#define UTIL_MYSTACK_H_

#include <string>
#include <stack>
#include <iostream>
#include <iomanip>
using namespace std;

template <class Type>
class MyStack {
  public:
	MyStack();
	~MyStack();
	void push(Type theObject);
	void pop();
	Type top();
	Type Get(unsigned int index);
	unsigned int size();
	bool empty();
  private:
	stack<Type> theStack;
};



#endif /* UTIL_MYSTACK_H_ */
