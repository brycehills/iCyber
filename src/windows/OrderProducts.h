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

class OrderProducts : public Window {
private:
	unsigned int product1State;
	int product1Value;

	unsigned int product2State;
	int product2Value;

	unsigned int product3State;
	int product3Value;

	double totalCost;

	int state;
public:
	OrderProducts(Member **m, int *n_m) : Window(m, n_m) {
		ID = ORDER_PRODUCTS;
		state = 0;
		totalCost = 0;
		product1Value = 0;
		product2Value = 0;
		product3Value = 0;
	}
	~OrderProducts() {}
	void render_main(zr_window *);
	void init() {
		state = 0;
	}
};



#endif /* WINDOWS_ORDERPRODUCTS_H_ */
