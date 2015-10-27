#ifndef WINDOWS_LOADER_H_
#define WINDOWS_LOADER_H_

#include "Window.h"

class Loader : public Window {
private:
	zr_edit_box eb;
	zr_char edit_buffer[MAX_BUFFER];
	int state;
public:
	Loader(Member **m, int *n_m) : Window(m, n_m) {
		ID = LOADER;
		state = 0;
		zr_edit_box_init_fixed(&eb, edit_buffer, MAX_BUFFER, NULL, NULL);
	}
	~Loader() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&eb);
		state = 0;
	}
};

#endif /* WINDOWS_LOADER_H_ */
