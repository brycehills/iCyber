#include "CustomerListWindow.h"

void CustomerListWindow::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		customers.clear();
		LoadCustomers();
		zr_header(&context, "Customer List", 0, 0, ZR_HEADER_LEFT);
		zr_layout_row_dynamic(&context, 30, 1);
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			changeWindow(ADMIN);
		}
		zr_checkbox(&context, "Key only", &isCheckBoxUnTicked);

		std::ostringstream customerStream;
		string output;

		// need a copy of the list for output
		vector<Customer> CustomerOutputVector = customers;
		while (!CustomerOutputVector.empty()) {
			if ((isCheckBoxUnTicked == 0
					&& CustomerOutputVector.front().GetIsKey())
					| (isCheckBoxUnTicked == 1)) {
				output = "Name: " + CustomerOutputVector.front().GetName();
				zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

				output = "Address: " + CustomerOutputVector.front().GetStreet()
						+ ", " + CustomerOutputVector.front().GetStateZipCode();
				zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

				output = "Received Pamphlet? ";
				if (CustomerOutputVector.front().GetPamphlet()) {
					output = output + "Yes";
				}
				else {
					output = output + "No";
				}
				zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

				output = "Type: ";
				if (CustomerOutputVector.front().GetIsKey()) {
					output = output + "Key";
				}
				else {
					output = output + "Nice to have";
				}
				zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

				output = "Rating: " + CustomerOutputVector.front().GetRating();
				zr_label(&context, output.c_str(), ZR_TEXT_LEFT);
			}
			if (zr_button_text(&context, "Edit",
					ZR_BUTTON_DEFAULT)) {
				//changeWindow(ADMIN);
			}
			CustomerOutputVector.erase(CustomerOutputVector.begin());
//			if ((isCheckBoxUnTicked == 0
//					&& CustomerOutputVector.front().GetIsKey()
//					&& !CustomerOutputVector.empty()) |(isCheckBoxUnTicked == 1
//					&& !CustomerOutputVector.empty())
//					) {
//				zr_label(&context, "----------------------------",
//						ZR_TEXT_LEFT);
//			}
		}

		zr_checkbox(&context, "Key only", &isCheckBoxUnTicked);
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			changeWindow(ADMIN);
		}
	}
	zr_end(&context, window);
}




