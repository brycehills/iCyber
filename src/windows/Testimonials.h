#ifndef WINDOWS_TESTIMONIALS_H_
#define WINDOWS_TESTIMONIALS_H_

#include "Window.h"
#include "../util/Loader.h" // save/load

class Testimonials : public Window {
private:
	zr_edit_box eb;
	zr_char edit_buffer[MAX_BUFFER];
	string newTestimonial;
public:
	Testimonials(stack<string>* t, vector<Customer>* c, int *c_i) : Window(t, c, c_i) {
		ID = TESTIMONIALS;
		zr_edit_box_init_fixed(&eb, edit_buffer, 999, NULL, NULL);
	}
	~Testimonials() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&eb);
	}
};



#endif /* WINDOWS_TESTIMONIALS_H_ */
