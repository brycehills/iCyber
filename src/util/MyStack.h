#ifndef UTIL_MYSTACK_H_
#define UTIL_MYSTACK_H_

#include <string>
#include <stack>
using namespace std;

template <class Type>
class MyStack {
  public:
	MyStack();
	~MyStack();
	void push(Type theObject);
	string popAndOutput();
  private:
	//Date creationDate;
	stack<Type> theStack;
};



#endif /* UTIL_MYSTACK_H_ */
