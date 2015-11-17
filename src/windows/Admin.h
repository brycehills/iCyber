#ifndef WINDOWS_ADMIN_H_
#define WINDOWS_ADMIN_H_

#include <fstream>
#include "Window.h"

class Admin : public Window {
private:
	zr_edit_box eb;
	zr_char edit_buffer[MAX_BUFFER];
	int state;
public:
	Admin(Member **m, int *n_m) : Window(m, n_m) {
		ID = ADMIN;
		state = 0;
		zr_edit_box_init_fixed(&eb, edit_buffer, MAX_BUFFER, NULL, NULL);
	}
	~Admin() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&eb);
		state = 0;
	}
};

#endif /* WINDOWS_ADMIN_H_ */
