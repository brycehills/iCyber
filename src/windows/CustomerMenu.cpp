#include "CustomerMenu.h"

void CustomerMenu::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		// debug: set equal to first customer if need to
		if (*customer_index == -1) {
			*customer_index = 0;
		}

		customerNameStream.str("");
		customerNameStream.clear();
		customerNameStream << "Menu - logged in as "
			<< customers->at(*customer_index);
		output = customerNameStream.str();
		zr_header(&context, output.c_str(), 0, 0, ZR_HEADER_LEFT);
		if (state == 1) {
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "You have already requested a pamphlet",
					ZR_TEXT_LEFT);
		}
		if (state == 2) {
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "You have requested a pamphlet",
					ZR_TEXT_LEFT);
		}
		zr_layout_row_dynamic(&context, 30, 1);
		zr_label(&context, "Please select an option:", ZR_TEXT_LEFT);
		zr_layout_row_static(&context, 30, 240, 3);
		if (zr_button_text(&context, "Order Products", ZR_BUTTON_DEFAULT)) {
			changeWindow(ORDER_PRODUCTS);
		}
		if (zr_button_text(&context, "Testimonials", ZR_BUTTON_DEFAULT)) {
			changeWindow(TESTIMONIALS);
		}
		if (zr_button_text(&context, "Log Off", ZR_BUTTON_DEFAULT)) {
			changeWindow(LOGIN);
		}
		if (zr_button_text(&context, "Request Pamphlet", ZR_BUTTON_DEFAULT)) {
			if (customers->at(*customer_index).GetPamphlet()) {
				state = 1;
			}
			else {
				customers->at(*customer_index).SetReceivedPamphlet(true);
				SaveCustomers(customers);
				state = 2;
			}
		}
	}
	zr_end(&context, window);
}
