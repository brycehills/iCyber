#include "OrderProducts.h"
#include <sstream>

void OrderProducts::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		zr_header(&context, "Order Products", 0, 0, ZR_HEADER_LEFT);
		zr_layout_row_dynamic(&context, 30, 1);
		if (state == 1) {
			zr_label(&context, "You have ordered products", ZR_TEXT_LEFT);
		}

		stringStream.str("");
		stringStream.clear();

		// Minimal Spinner Row
		stringStream << "Minimal ($" << Customer::minimumPackageCost
				<< "/month):";
		output = stringStream.str();
		zr_layout_row_dynamic(&context, 30, 1);
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);
		zr_layout_row_static(&context, 30, 240, 3);
		zr_spinner_int(&context, 0, &product1Value, 9999, 1, &product1State);
		stringStream.str("");
		stringStream.clear();
		stringStream << "Current Quantity: "
			<< customers->at(*customer_index).GetMinimumPurchases();
		output = stringStream.str();
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

		stringStream.str("");
		stringStream.clear();

		// Extreme Spinner Row
		stringStream << "Extreme ($" << Customer::extremePackageCost
				<< "/month):";
		output = stringStream.str();
		zr_layout_row_dynamic(&context, 30, 1);
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);
		zr_layout_row_static(&context, 30, 240, 3);
		zr_spinner_int(&context, 0, &product2Value, 9999, 1, &product2State);
		stringStream.str("");
		stringStream.clear();
		stringStream << "Current Quantity: "
			<< customers->at(*customer_index).GetExtremePurchases();
		output = stringStream.str();
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

		stringStream.str("");
		stringStream.clear();

		// Ultimate Spinner Row
		stringStream << "Ultimate ($" << Customer::ultimatePackageCost
				<< "/month):";
		output = stringStream.str();
		zr_layout_row_dynamic(&context, 30, 1);
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);
		zr_layout_row_static(&context, 30, 240, 3);
		zr_spinner_int(&context, 0, &product3Value, 9999, 1, &product3State);
		stringStream.str("");
		stringStream.clear();
		stringStream << "Current Quantity: "
			<< customers->at(*customer_index).GetUltimatePurchases();
		output = stringStream.str();
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

		stringStream.str("");
		stringStream.clear();

		// total cost row
		zr_layout_row_static(&context, 30, 120, 3);
		zr_label(&context, "Total Cost:", ZR_TEXT_LEFT);
		totalCost = (product1Value * Customer::minimumPackageCost)
				+ (product2Value * Customer::extremePackageCost)
				+ (product3Value * Customer::ultimatePackageCost);
		stringStream << "$" << totalCost << "/Month";
		output = stringStream.str();
		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

		zr_layout_row_dynamic(&context, 30, 1);
		if (zr_button_text(&context, "Submit", ZR_BUTTON_DEFAULT)) {
			if (product1Value + product2Value + product3Value > 0) {
				customers->at(*customer_index).AddMimimumPackage(product1Value);
				customers->at(*customer_index).AddExtremePackage(product2Value);
				customers->at(*customer_index).AddUltimatePackage(product3Value);
				SaveCustomers(customers);
				issue_update();
				product1Value = 0;
				product2Value = 0;
				product3Value = 0;
				state = 1;
			}
		}
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			changeWindow(CUSTOMER_MENU);
		}
	}
	zr_end(&context, window);
}
