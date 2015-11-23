#include "Admin.h"

string default_data[][5] = { { "Los Angeles Airport", "1 World Way",
		"Los Angeles", "CA", "90045" }, { "FBI", "1234 Lincoln Ave.",
		"Washington", "DC", "00234" }, { "CIA", "987 Jefferson Blvd",
		"Baltimore", "MD", "00754" }, { "Saddleback College",
		"28000 Marguerite Pkwy", "Mission Viejo", "CA", "92692" }, {
		"Los Angeles Dodgers", "1000 Elysian Park Avenue", "Los Angeles", "CA",
		"90012" }, { "Los Angeles Angels", "2000 East Gene Autry Way",
		"Anaheim", "CA", "92806" } };

int default_data_2[][2] = { { VERY, KEY }, { SOMEWHAT, KEY }, { NOT, KEY }, {
		SOMEWHAT, NTH }, { VERY, NTH }, { VERY, KEY } };

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
		if (zr_button_text(&context, "Log Off", ZR_BUTTON_DEFAULT)) {
			changeWindow(LOGIN);
		}
	}
	zr_end(&context, window);
}

