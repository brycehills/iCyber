#include "OrderProducts.h"

void OrderProducts::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		if (state == 1) {
		} else {
			zr_header(&context, "Order Products", 0, 0, ZR_HEADER_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
		}
	}
	zr_end(&context, window);
}
