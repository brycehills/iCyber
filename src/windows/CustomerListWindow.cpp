#include "CustomerListWindow.h"
void CustomerListWindow::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		zr_header(&context, "Customer List", 0, 0, ZR_HEADER_LEFT);
		zr_layout_row_dynamic(&context, 30, 1);
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			changeWindow(ADMIN);
		}
		{
			try {
				if (customers->empty()) {
					throw 0;
				}
				zr_checkbox(&context, "Key only", &isCheckBoxUnTicked);

				// need a copy of the list for output
				vector<Customer> CustomerOutputVector = *customers;
				for (int i = 0; !CustomerOutputVector.empty(); i++) {
					if ((isCheckBoxUnTicked == 0
							&& CustomerOutputVector.front().GetIsKey())
							| (isCheckBoxUnTicked == 1)) {
						// name row
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Name: ", ZR_TEXT_LEFT);
						zr_label(&context,
								CustomerOutputVector.front().GetName().c_str(),
								ZR_TEXT_LEFT);

						// address row
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Address: ", ZR_TEXT_LEFT);
						output =
								CustomerOutputVector.front().GetStreet() + ", "
										+ CustomerOutputVector.front().GetStateZipCode();
						zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

						// Pamphlet row
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Sent Pamphlet? ", ZR_TEXT_LEFT);
						output =
								CustomerOutputVector.front().GetStreet() + ", "
										+ CustomerOutputVector.front().GetStateZipCode();
						if (CustomerOutputVector.front().GetPamphlet()) {
							output = "Yes";
						} else {
							output = "No";
						}
						zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

						// Key row
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Type: ", ZR_TEXT_LEFT);
						if (CustomerOutputVector.front().GetIsKey()) {
							output = "Key";
						} else {
							output = "Nice to have";
						}
						zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

						// Rating row
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Rating: ", ZR_TEXT_LEFT);
						zr_label(&context,
								CustomerOutputVector.front().GetRating().c_str(),
								ZR_TEXT_LEFT);

						// Username row
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Username: ", ZR_TEXT_LEFT);
						zr_label(&context,
								CustomerOutputVector.front().GetUsername().c_str(),
								ZR_TEXT_LEFT);

						// Minimum Package Row
						ostringstream productQuantityStream;
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Minimum Package Purchases: ",
								ZR_TEXT_LEFT);
						productQuantityStream
								<< CustomerOutputVector.front().GetMinimumPurchases()
								<< " ($"
								<< CustomerOutputVector.front().GetMinimumPurchases()
										* Customer::minimumPackageCost
								<< "/Month)";
						output = productQuantityStream.str();
						zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

						// Extreme Package Row
						zr_layout_row_dynamic(&context, 30, 2);
						productQuantityStream.str("");
						productQuantityStream.clear();
						zr_label(&context, "Extreme Package Purchases: ",
								ZR_TEXT_LEFT);
						productQuantityStream
								<< CustomerOutputVector.front().GetExtremePurchases()
								<< " ($"
								<< CustomerOutputVector.front().GetExtremePurchases()
										* Customer::extremePackageCost
								<< "/Month)";
						output = productQuantityStream.str();
						zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

						// Ultimate Package Row
						productQuantityStream.str("");
						productQuantityStream.clear();
						zr_layout_row_dynamic(&context, 30, 2);
						zr_label(&context, "Ultimate Package Purchases: ",
								ZR_TEXT_LEFT);
						productQuantityStream
								<< CustomerOutputVector.front().GetUltimatePurchases()
								<< " ($"
								<< CustomerOutputVector.front().GetUltimatePurchases()
										* Customer::ultimatePackageCost
								<< "/Month)";

						output = productQuantityStream.str();
						zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

						// Edit and Remove Button Row
						zr_layout_row_dynamic(&context, 30, 2);
						editButtonString = "Edit "
								+ CustomerOutputVector.front().GetName();

						if (zr_button_text(&context, editButtonString.c_str(),
								ZR_BUTTON_DEFAULT)) {
							*customer_index = i;
							issue_update();
							changeWindow(EDIT_CUSTOMER);
						}
						removeButtonString = "Remove "
								+ CustomerOutputVector.front().GetName();
						if (zr_button_text(&context, removeButtonString.c_str(),
								ZR_BUTTON_DEFAULT)) {
							customers->erase(customers->begin() + i);
							SaveCustomers(customers);
							issue_update();
						}
					}

					CustomerOutputVector.erase(CustomerOutputVector.begin());
				}

				zr_layout_row_dynamic(&context, 30, 1);
				zr_checkbox(&context, "Key only", &isCheckBoxUnTicked);
				if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
					changeWindow(ADMIN);
				}
			} catch (...) {
				zr_label(&context, "There are currently no customers",
						ZR_TEXT_LEFT);
			}
		}

	}
	zr_end(&context, window);
}

