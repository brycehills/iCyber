#include "OrderProducts.h"
#include <sstream>

void OrderProducts::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		zr_header(&context, "Order Products", 0, 0, ZR_HEADER_LEFT);
		zr_layout_row_dynamic(&context, 30, 1);
//		if (state == 1) {
//			std::ostringstream confirmationStream;
//			confirmationStream << "You have ordered ";
//			if (product1Value > 0) {
//				confirmationStream << product1Value << " copies of the Minimal Package";
//				if (product2Value > 0 || product3Value > 0) {
//					confirmationStream << ", ";
//				}
//			}
//
//			if (product2Value > 0) {
//				confirmationStream << product2Value
//						<< " copies of the Extreme Package";
//				if (product3Value > 0) {
//					confirmationStream << ", ";
//				}
//			}
//
//			if (product3Value > 0) {
//				confirmationStream << product3Value
//						<< " copies of the Ultimate Package";
//			}
//
//
//			string confirmationMessage = confirmationStream.str();
//			zr_label(&context, confirmationMessage.c_str(), ZR_TEXT_LEFT);
//			confirmationStream.clear();
//			confirmationStream << "";
//		}


		zr_label(&context, "Minimal ($14.95/month):", ZR_TEXT_LEFT);
		zr_spinner_int(&context, 0, &product1Value, 9999, 1, &product1State);

		zr_label(&context, "Extreme ($34.95/month):", ZR_TEXT_LEFT);
		zr_spinner_int(&context, 0, &product2Value, 9999, 1, &product2State);

		zr_label(&context, "Ultimate ($90.00/month):", ZR_TEXT_LEFT);
		zr_spinner_int(&context, 0, &product3Value, 9999, 1, &product3State);

		zr_label(&context, "Total Cost:", ZR_TEXT_LEFT);

		totalCost = (product1Value * 14.95) + (product2Value * 34.95)
				+ (product3Value * 90.00);

		std::ostringstream totalCostStream;
		totalCostStream << "$" << totalCost << "/Month";
		std::string output = totalCostStream.str();

		zr_label(&context, output.c_str(), ZR_TEXT_LEFT);

		if (zr_button_text(&context, "Submit", ZR_BUTTON_DEFAULT)) {
			if (product1Value + product2Value + product3Value > 0) {
//				state = 1;
			}
		}
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			changeWindow(CUSTOMER_MENU);
		}
	}
	zr_end(&context, window);
}
