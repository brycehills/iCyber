#ifndef WINDOWS_CUSTOMERMENU_H_
#define WINDOWS_CUSTOMERMENU_H_

#include "Window.h"

class CustomerMenu : public Window {
public:
	CustomerMenu(stack<string>* t, vector<Customer>* c, int *c_i) : Window(t, c, c_i) {
		ID = CUSTOMER_MENU;
	}
	~CustomerMenu() {}
	void render_main(zr_window *);
	void init() {}
};



#endif /* WINDOWS_CUSTOMERMENU_H_ */
