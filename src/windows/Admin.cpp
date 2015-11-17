#include "Admin.h"

string default_data[][5] =
{{"Los Angeles Airport", "1 World Way", "Los Angeles", "CA", "90045"},
{"FBI", "1234 Lincoln Ave.", "Washington", "DC", "00234"},
{"CIA", "987 Jefferson Blvd", "Baltimore", "MD", "00754"},
{"Saddleback College", "28000 Marguerite Pkwy", "Mission Viejo", "CA", "92692"},
{"Los Angeles Dodgers", "1000 Elysian Park Avenue", "Los Angeles", "CA", "90012"},
{"Los Angeles Angels", "2000 East Gene Autry Way", "Anaheim", "CA", "92806"}};


int default_data_2[][2] =
{{VERY, KEY},
{SOMEWHAT, KEY},
{NOT, KEY},
{SOMEWHAT, NTH},
{VERY, NTH},
{VERY, KEY}};

void Admin::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		if (state == 1) {
			zr_header(&context, "Loading", 0, 0, ZR_HEADER_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "Loading right now", ZR_TEXT_LEFT);

			//load from
			ifstream infile("data.dat");
			if (!infile) {
				state = 3;
			} else {

			}
		} else if (state == 2) {
			issue_update(); //update variable globally. This is important!
			zr_header(&context, "Success!", 0, 0, ZR_HEADER_LEFT);
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, "Loading right now", ZR_TEXT_LEFT);
			changeWindow(LOADER); //to main window!
		} else {
			zr_header(&context, "Welcome Admin!", 0, 0, ZR_HEADER_LEFT);
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

			//add delete customer
			//
		}
	}
	zr_end(&context, window);
}

