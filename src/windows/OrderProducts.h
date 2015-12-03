/*************************************************************************
 * AUTHOR	     : Steve Fajardo
 * STUDENT ID    : 832032
 * ASSIGNMENT #6 : Pointers
 * CLASS	     : CS1C
 * SECTION       : MW 5:30 P.M.
 * DUE DATE      : 9/28/15
 ************************************************************************/
#ifndef WINDOWS_ORDERPRODUCTS_H_
#define WINDOWS_ORDERPRODUCTS_H_

#include "Window.h"
#include "../util/Loader.h" // save

class OrderProducts : public Window {
private:
	string output;
	ostringstream stringStream;

	unsigned int product1State;
	int product1Value;

	unsigned int product2State;
	int product2Value;

	unsigned int product3State;
	int product3Value;

	double totalCost;

	int state;
public:
	OrderProducts(stack<string>* t, vector<Customer>* c, int *c_i) : Window(t, c, c_i) {
		ID = ORDER_PRODUCTS;
		state = 0;
		totalCost = 0;
		product1Value = 0;
		product2Value = 0;
		product3Value = 0;
		output = "";
	}
	~OrderProducts() {}
	void render_main(zr_window *);
	void init() {
		state = 0;
		totalCost = 0;
		product1Value = 0;
		product2Value = 0;
		product3Value = 0;
	}
};



#endif /* WINDOWS_ORDERPRODUCTS_H_ */
