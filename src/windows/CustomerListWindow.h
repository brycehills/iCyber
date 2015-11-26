#ifndef WINDOWS_CUSTOMERLISTWINDOW_H_
#define WINDOWS_CUSTOMERLISTWINDOW_H_

#include "Window.h"

class CustomerListWindow : public Window {
private:
	int isCheckBoxUnTicked;
public:
	CustomerListWindow(Member **m, int *n_m) : Window(m, n_m) {
		ID = CUSTOMER_LIST;
		isCheckBoxUnTicked = 1;
	}
	~CustomerListWindow() {}
	void render_main(zr_window *);
	void init() {
	}
};

#endif /* WINDOWS_CUSTOMERLISTWINDOW_H_ */
