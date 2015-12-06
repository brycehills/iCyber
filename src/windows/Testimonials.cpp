#include "Testimonials.h"
#include <sstream>

void Testimonials::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		zr_header(&context, "Testimonials", 0, 0, ZR_HEADER_LEFT);
		if (invalidTestimonial) {
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "Please enter a message", ZR_TEXT_LEFT);
		}
		zr_layout_row_dynamic(&context, 30, 1);

		std::ostringstream testimonialStream;

		for (unsigned int i = 0; i < testimonials->size(); i++) {
			testimonialStream << i + 1
					<< ") " << testimonials->Get(i).GetDate().GetDate()
					<< ": \"" << testimonials->Get(i).GetMessage()
					<< "\"";
			std::string output = testimonialStream.str();
			zr_label(&context, output.c_str(), ZR_TEXT_LEFT);
			testimonialStream.clear();
			testimonialStream.str("");
		}

		zr_editbox(&context, &eb);

		if (zr_button_text(&context, "Submit", ZR_BUTTON_DEFAULT)) {
			// get the characters in the username box
			newTestimonial = "";
			invalidTestimonial = false;
			for (unsigned int i = 0; i < eb.glyphes; i++) {
				newTestimonial += ((char* ) eb.buffer.memory.ptr)[i];
			}
			if (newTestimonial.length() != 0) {
				postDate = new Date();
				newTestimonialObject = new TestimonialClass(newTestimonial,
						postDate);
				testimonials->push(*newTestimonialObject);
				SaveTestimonials(testimonials);
				issue_update();
				zr_edit_box_clear(&eb);
				newTestimonial = "";
			}
			else {
				invalidTestimonial = true;
			}

		}
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			changeWindow(CUSTOMER_MENU);
		}

	}
	zr_end(&context, window);
}
