#include "AddUser.h"
#include <sstream>

void AddUser::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		static const char *ratings[] = { "very interested",
				"somewhat interested", "not interested", "never call again" };
		zr_header(&context, "Add Customer", 0, 0, ZR_HEADER_LEFT);

		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Name:", ZR_TEXT_LEFT);
		zr_editbox(&context, &nameBox);
		if (isNameDuplicate) {
			zr_label(&context, "Could not add: Name already exists",
					ZR_TEXT_LEFT);
		} else if (isNameEmpty) {
			zr_label(&context, "Could not add: Please enter a name",
					ZR_TEXT_LEFT);
		}

		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Street:", ZR_TEXT_LEFT);
		zr_editbox(&context, &streetBox);
		if (isStreetEmpty) {
			zr_label(&context, "Could not add: Please enter an address",
					ZR_TEXT_LEFT);
		}

		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "State Zip Code:", ZR_TEXT_LEFT);
		zr_editbox(&context, &stateZipCodeBox);
		if (isStateEmpty) {
			zr_label(&context,
					"Could not add: Please enter an address",
					ZR_TEXT_LEFT);
		}

		zr_layout_row_static(&context, 30, 240, 3);
		zr_checkbox(&context, "Received Pamphlet", &isPamphletBoxUnTicked);
		zr_checkbox(&context, "Key Customer", &isKeyBoxUnTicked);

		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Rating: ", ZR_TEXT_LEFT);
		zr_combo_begin(&context, &ratingComboBox, ratings[currentRatingInt],
				&ratingComboBoxState);
		{
			zr_layout_row_dynamic(&ratingComboBox, 25, 1);
			for (int i = 0; i < 4; i++) {
				if (zr_combo_item(&ratingComboBox, ratings[i], ZR_TEXT_LEFT)) {
					currentRatingInt = i;
				}
			}
		}
		zr_combo_end(&context, &ratingComboBox, &ratingComboBoxState);

		// submit box row
		zr_layout_row_dynamic(&context, 30, 1);
		if (zr_button_text(&context, "Submit", ZR_BUTTON_DEFAULT)) {
			// initialize
			isNewCustomerAdded = false;
			isNameDuplicate = false;
			isNameEmpty = false;
			isInvalidCustomer = false;
			isNameEmpty = false;
			isStateEmpty = false;
			isStreetEmpty = false;
			name = "";
			street = "";
			stateZipCode = "";

			// get the characters in the name box
			for (unsigned int i = 0; i < nameBox.glyphes; i++) {
				name += ((char*) nameBox.buffer.memory.ptr)[i];
			}

			// check if name empty
			if (name.length() == 0) {
				isNameEmpty = true;
				isInvalidCustomer = true;
			} else {
				// search for duplicates
				vector<Customer> SearchCustomerVector = customers;
				while (!SearchCustomerVector.empty() && !isNameDuplicate) {
					if (SearchCustomerVector.front().GetName() == name) {
						isNameDuplicate = true;
						isInvalidCustomer = true;
					} else {
						SearchCustomerVector.erase(
								SearchCustomerVector.begin());
					}
				}
			}

			// get the characters in the street box
			for (unsigned int i = 0; i < streetBox.glyphes; i++) {
				street += ((char*) streetBox.buffer.memory.ptr)[i];
			}

			// check if street empty
			if (street.length() == 0) {
				isStreetEmpty = true;
				isInvalidCustomer = true;
			}

			// get the characters in the state zip code box
			for (unsigned int i = 0; i < stateZipCodeBox.glyphes; i++) {
				stateZipCode += ((char*) stateZipCodeBox.buffer.memory.ptr)[i];
			}

			// check if state empty
			if (stateZipCode.length() == 0) {
				isStateEmpty = true;
				isInvalidCustomer = true;
			}

			// get whether key
			if (!isKeyBoxUnTicked) {
				isKey = true;
			} else {
				isKey = false;
			}

			// get pamphlet
			if (!isPamphletBoxUnTicked) {
				isPamphletReceived = true;
			} else {
				isPamphletReceived = false;
			}
			// get rating
			rating = ratings[currentRatingInt];

			if (!isInvalidCustomer) {
				newCustomer = new Customer(name, street, stateZipCode,
						isPamphletReceived, isKey, rating);

				customers.push_back(*newCustomer);

				std::sort(customers.begin(), customers.end());
				SaveCustomers();
				isNewCustomerAdded = true;
			}

		}
		if (isNewCustomerAdded) {
			zr_layout_row_static(&context, 30, 240, 3);
			zr_label(&context, "You have added a new customer", ZR_TEXT_LEFT);
		}
		zr_layout_row_dynamic(&context, 30, 1);
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			isNameDuplicate = false;
			changeWindow(ADMIN);
		}
	}
	zr_end(&context, window);
}

