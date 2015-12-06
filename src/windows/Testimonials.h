#ifndef WINDOWS_TESTIMONIALS_H_
#define WINDOWS_TESTIMONIALS_H_

#include "Window.h"
#include "../util/Loader.h" // save/load
#include <iomanip>
#include <iostream>

class Testimonials : public Window {
private:
	zr_edit_box eb;
	zr_char edit_buffer[MAX_BUFFER];
	string newTestimonial;
	Date *postDate;
	TestimonialClass *newTestimonialObject;
	bool invalidTestimonial;
public:
	Testimonials(MyStack<TestimonialClass>* t, vector<Customer>* c, int *c_i) : Window(t, c, c_i) {
		ID = TESTIMONIALS;
		zr_edit_box_init_fixed(&eb, edit_buffer, 999, NULL, NULL);
		invalidTestimonial = false;
	}
	~Testimonials() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&eb);
		invalidTestimonial = false;
		newTestimonial = "";
	}
};



#endif /* WINDOWS_TESTIMONIALS_H_ */
