#ifndef WINDOWS_TESTIMONIALS_H_
#define WINDOWS_TESTIMONIALS_H_

#include "Window.h"

class Testimonials : public Window {
private:
	zr_edit_box eb;
	zr_char edit_buffer[MAX_BUFFER];
	int state;
	string newTestimonial;
public:
	Testimonials(Member **m, int *n_m) : Window(m, n_m) {
		ID = TESTIMONIALS;
		state = 0;
		zr_edit_box_init_fixed(&eb, edit_buffer, 999, NULL, NULL);
	}
	~Testimonials() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&eb);
		state = 0;
	}
};



#endif /* WINDOWS_TESTIMONIALS_H_ */
