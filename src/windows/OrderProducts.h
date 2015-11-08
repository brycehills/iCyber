/*
 * OrderProducts.h
 *
 *  Created on: Nov 4, 2015
 *      Author: sfajardo1
 */

#ifndef WINDOWS_ORDERPRODUCTS_H_
#define WINDOWS_ORDERPRODUCTS_H_

#include "Window.h"

class OrderProducts : public Window {
private:
	int state;
	zr_command_buffer buffer;
	struct zr_rect rect;
	struct zr_spinner spinner;
	struct zr_input input;
public:
	OrderProducts(Member **m, int *n_m) : Window(m, n_m) {
		ID = ORDER_PRODUCTS;
		state = 0;
		zr_widget_spinner(&buffer, rect, &spinner, 0, 0, 10, 1, 0, &input, NULL);
	}
	~OrderProducts() {}
	void render_main(zr_window *);
	void init() {
		state = 0;
	}
};

#endif /* WINDOWS_ORDERPRODUCTS_H_ */
