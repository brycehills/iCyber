#include "Testimonials.h"
#include <sstream>

void Testimonials::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		// default testimonials, temporary
		if (state == 0) {
			testimonials.push("Best thing since sliced bread");
			testimonials.push("Take my money");
			cout << testimonials.size()  << "\n";
			state = 1;
		}

		zr_header(&context, "Testimonials", 0, 0, ZR_HEADER_LEFT);
		zr_layout_row_dynamic(&context, 30, 1);

		std::ostringstream testimonialStream;

		// need a copy of the stack for output
		stack<string> testimonialOutputStack = testimonials;
		for (unsigned int i = 0; i < testimonials.size(); i++) {
			testimonialStream << i + 1 << ". \"" << testimonialOutputStack.top() << "\"";
			testimonialOutputStack.pop();
			std::string output = testimonialStream.str();
			zr_label(&context, output.c_str(), ZR_TEXT_LEFT);
			testimonialStream.clear();
			testimonialStream.str("");
		}

		zr_editbox(&context, &eb);

		if (zr_button_text(&context, "Submit", ZR_BUTTON_DEFAULT)) {
			// get the characters in the username box
			for (unsigned int i = 0; i < eb.glyphes; i++) {
				newTestimonial += ((char* ) eb.buffer.memory.ptr)[i];
			}
			testimonials.push(newTestimonial);
			zr_edit_box_clear(&eb);
			newTestimonial = "";
		}

	}
	zr_end(&context, window);
}
