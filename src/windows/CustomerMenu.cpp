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
		zr_layout_row_dynamic(&context, 30, 1);
		if (state == 1) {
			zr_label(&context, "You have already requested a pamphlet",
					ZR_TEXT_LEFT);
		}
		if (state == 2) {
			zr_label(&context, "You have requested a pamphlet",
					ZR_TEXT_LEFT);
		}
		zr_layout_row_dynamic(&context, 30, 1);
		zr_label(&context, "Customer information", ZR_TEXT_CENTERED);
		zr_seperator(&context);
		zr_layout_row_dynamic(&context, 30, 1);
		// Username row
		zr_layout_row_dynamic(&context, 30, 2);
		zr_label(&context, "Username: ", ZR_TEXT_LEFT);
		zr_label(&context,
				customers->at(*customer_index).GetUsername().c_str(),
				ZR_TEXT_LEFT);

		// address row
		zr_layout_row_dynamic(&context, 30, 2);
		zr_label(&context, "Address: ", ZR_TEXT_LEFT);
		output =
				customers->at(*customer_index).GetStreet() + ", "
						+ customers->at(*customer_index).GetStateZipCode();
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

		// Pamphlet row
		zr_layout_row_dynamic(&context, 30, 2);
		zr_label(&context, "Sent Pamphlet? ", ZR_TEXT_LEFT);
		output =
				customers->at(*customer_index).GetStreet() + ", "
						+ customers->at(*customer_index).GetStateZipCode();
		if (customers->at(*customer_index).GetPamphlet()) {
			output = "Yes";
		} else {
			output = "No";
		}
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

		// Minimum Package Row
		ostringstream productQuantityStream;
		zr_layout_row_dynamic(&context, 30, 2);
		zr_label(&context, "Minimum Package Purchases: ",
				ZR_TEXT_LEFT);
		productQuantityStream
				<< customers->at(*customer_index).GetMinimumPurchases()
				<< " ($"
				<< customers->at(*customer_index).GetMinimumPurchases()
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
				<< customers->at(*customer_index).GetExtremePurchases()
				<< " ($"
				<< customers->at(*customer_index).GetExtremePurchases()
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
				<< customers->at(*customer_index).GetUltimatePurchases()
				<< " ($"
				<< customers->at(*customer_index).GetUltimatePurchases()
						* Customer::ultimatePackageCost
				<< "/Month)";

		output = productQuantityStream.str();
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);
		zr_seperator(&context);
		zr_layout_row_dynamic(&context, 30, 1);

		//zr_layout_row_dynamic(&context, 30, 1);
		//zr_label(&context, "Please select an option:", ZR_TEXT_LEFT);
		zr_layout_row_static(&context, 30, 200, 4);
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
