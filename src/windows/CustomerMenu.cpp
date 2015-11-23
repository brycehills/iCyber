#include "CustomerMenu.h"

void CustomerMenu::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		zr_header(&context, "Menu", 0, 0, ZR_HEADER_LEFT);
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
//		if (zr_button_text(&context, "Request Pamphlet", ZR_BUTTON_DEFAULT)) {
//			changeWindow(INFOQUANTITY);
//		}
	}
	zr_end(&context, window);
}
