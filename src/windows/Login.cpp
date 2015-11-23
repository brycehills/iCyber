#include "Login.h"

void Login::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		if (state == 1) {
			if (adminLogin) {
				zr_header(&context, "Correct login - administrator", 0, 0, ZR_HEADER_LEFT);
				adminLogin = false;
				changeWindow(ADMIN);
			}
			else {
				zr_header(&context, "Correct login - customer", 0, 0, ZR_HEADER_LEFT);
				changeWindow(CUSTOMER_MENU);
			}

		} else {
			zr_header(&context, "Login", 0, 0, ZR_HEADER_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
			if (state == 2) {
				zr_label(&context, "Error! Wrong username/password", ZR_TEXT_LEFT);
			}

			// username label row
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "Username:", ZR_TEXT_LEFT);

			// username box row
			zr_layout_row_static(&context, 30, 240, 3);
			zr_editbox(&context, &usernameBox);

			// password label row
			zr_layout_row_dynamic(&context, 30, 6);
			zr_label(&context, "Password:", ZR_TEXT_LEFT);

			// password box row
			zr_layout_row_static(&context, 30, 240, 8);
			zr_editbox(&context, &passwordBox);

			// submit box row
			zr_layout_row_dynamic(&context, 30, 9);
			if (zr_button_text(&context, "Submit", ZR_BUTTON_DEFAULT)) {
				username = "";
				password = "";
				// get the characters in the username box
				for (unsigned int i = 0; i < usernameBox.glyphes; i++) {
					username += ((char* ) usernameBox.buffer.memory.ptr)[i];
				}

				// get the charactesr in the password box
				for (unsigned int i = 0; i < passwordBox.glyphes; i++) {
					password += ((char* ) passwordBox.buffer.memory.ptr)[i];
				}

				if ((username == "admin") & (password == "admin")) {
					state = 1;
					adminLogin = true;
				}
				else if ((username == "customer") & (password == "customer")) {
					state = 1;
				}
				else {
					state = 2;
				}
			}
		}
	}
	zr_end(&context, window);
}
