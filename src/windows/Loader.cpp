#include "Loader.h"

void Loader::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		if (state == 1) {
			zr_header(&context, "Loading", 0, 0, ZR_HEADER_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "Loading right now", ZR_TEXT_LEFT);
		} else if (state == 2) {
			issue_update(); //update variable globally. This is important!
			zr_header(&context, "Success!", 0, 0, ZR_HEADER_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "Loading right now", ZR_TEXT_LEFT);
			changeWindow(LOADER); //to main window!
		} else {
			zr_header(&context, "Welcome to the BulkClub!", 0, 0, ZR_HEADER_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
			if (state == 3) zr_label(&context, "Error! Could not load from specified directory", ZR_TEXT_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "Please input the directory where the core files lie:", ZR_TEXT_LEFT);
			zr_layout_row_static(&context, 30, 240, 3);
			zr_editbox(&context, &eb);
			zr_layout_row_dynamic(&context, 30, 6);
			if (zr_button_text(&context, "Submit", ZR_BUTTON_DEFAULT)) {
				state = 1;
				//do stuffs!
			}
		}
	}
	zr_end(&context, window);
}
