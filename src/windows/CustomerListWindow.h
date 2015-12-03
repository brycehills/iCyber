#ifndef WINDOWS_CUSTOMERLISTWINDOW_H_
#define WINDOWS_CUSTOMERLISTWINDOW_H_

#include "Window.h"
#include "../util/Loader.h" // save

class CustomerListWindow : public Window {
private:
	int isCheckBoxUnTicked;
	string output;
	string editButtonString;
	string removeButtonString;
public:
	CustomerListWindow(stack<string>* t, vector<Customer>* c, int *c_i) : Window(t, c, c_i) {
		ID = CUSTOMER_LIST;
		isCheckBoxUnTicked = 1;
		output = "";
		editButtonString = "";
		removeButtonString = "";
	}
	~CustomerListWindow() {}
	void render_main(zr_window *);
	void init() {
		output = "";
		editButtonString = "";
		removeButtonString = "";
	}
};

#endif /* WINDOWS_CUSTOMERLISTWINDOW_H_ */
