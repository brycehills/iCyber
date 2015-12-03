#ifndef WINDOWS_CUSTOMERMENU_H_
#define WINDOWS_CUSTOMERMENU_H_

#include "Window.h"
#include "../util/Loader.h" // save

class CustomerMenu : public Window {
private:
	int state;
public:
	CustomerMenu(stack<string>* t, vector<Customer>* c, int *c_i) : Window(t, c, c_i) {
		ID = CUSTOMER_MENU;
		state = 0;
	}
	~CustomerMenu() {}
	void render_main(zr_window *);
	void init() {
		state = 0;
	}
};



#endif /* WINDOWS_CUSTOMERMENU_H_ */
