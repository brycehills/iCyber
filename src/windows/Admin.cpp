#include "Admin.h"

void Admin::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		zr_header(&context, "Admin Menu", 0, 0, ZR_HEADER_LEFT);
		zr_layout_row_dynamic(&context, 30, 1);
		zr_label(&context, "Please select an option:", ZR_TEXT_LEFT);
		zr_layout_row_static(&context, 30, 240, 3);

		if (zr_button_text(&context, "Customer List", ZR_BUTTON_DEFAULT)) {
			changeWindow (CUSTOMER_LIST);
		}
		if (zr_button_text(&context, "Add Customer", ZR_BUTTON_DEFAULT)) {
			changeWindow (ADD_USER);
		}
		if (zr_button_text(&context, "Log Off", ZR_BUTTON_DEFAULT)) {
			changeWindow(LOGIN);
		}
	}
	zr_end(&context, window);
}

