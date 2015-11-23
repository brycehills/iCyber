#ifndef WINDOWS_CUSTOMERMENU_H_
#define WINDOWS_CUSTOMERMENU_H_

#include "Window.h"

class CustomerMenu : public Window {
public:
	CustomerMenu(Member **m, int *n_m) : Window(m, n_m) {
		ID = CUSTOMER_MENU;
	}
	~CustomerMenu() {}
	void render_main(zr_window *);
	void init() {}
};



#endif /* WINDOWS_CUSTOMERMENU_H_ */
