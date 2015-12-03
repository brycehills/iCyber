#include "AddUser.h"
#include <sstream>

void AddUser::render_main(zr_window *window) {
	zr_context context;
	zr_begin(&context, window);
	{
		static const char *ratings[] = { "very interested",
				"somewhat interested", "not interested", "never call again" };
		zr_header(&context, "Add Customer", 0, 0, ZR_HEADER_LEFT);
		zr_layout_row_dynamic(&context, 30, 1);
		zr_label(&context, "Note: Username and Password will be auto-generated "
				"upon adding customer if fields left empty", ZR_TEXT_LEFT);

		// name box
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

		// street box
		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Street:", ZR_TEXT_LEFT);
		zr_editbox(&context, &streetBox);
		if (isStreetEmpty) {
			zr_label(&context, "Could not add: Please enter an address",
					ZR_TEXT_LEFT);
		}

		// state zipcode box
		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "State and Zip Code:", ZR_TEXT_LEFT);
		zr_editbox(&context, &stateZipCodeBox);
		if (isStateEmpty) {
			zr_label(&context, "Could not add: Please enter an address",
					ZR_TEXT_LEFT);
		}

		// username box
		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Username:", ZR_TEXT_LEFT);
		zr_editbox(&context, &usernameBox);
		if (isUsernameDuplicate) {
			zr_label(&context, "Could not add: Username already exists",
					ZR_TEXT_LEFT);
		}
		else if (isUsernameInvalid) {
			zr_label(&context, "Could not add: Spaces disallowed",
					ZR_TEXT_LEFT);
		}

		// password box
		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Password:", ZR_TEXT_LEFT);
		zr_editbox(&context, &passwordBox);
		if (isPasswordInvalid) {
			zr_label(&context, "Could not add: Spaces disallowed",
					ZR_TEXT_LEFT);
		}

		// product spinners
		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Minimal Packages:", ZR_TEXT_LEFT);
		zr_spinner_int(&context, 0, &product1Value, 9999, 1, &product1State);

		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Extreme Packages:", ZR_TEXT_LEFT);
		zr_spinner_int(&context, 0, &product2Value, 9999, 1, &product2State);

		zr_layout_row_static(&context, 30, 240, 3);
		zr_label(&context, "Ultimate Packages:", ZR_TEXT_LEFT);
		zr_spinner_int(&context, 0, &product3Value, 9999, 1, &product3State);

		// Rating drop down menu
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

		// Received Pamphlet and Key Customer Box checkboxes
		zr_layout_row_static(&context, 30, 240, 3);
		zr_checkbox(&context, "Requested Pamphlet", &isPamphletBoxUnTicked);
		zr_checkbox(&context, "Key Customer", &isKeyBoxUnTicked);

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
			isUsernameDuplicate = false;
			isUsernameInvalid = false;
			isPasswordInvalid = false;
			name = "";
			street = "";
			stateZipCode = "";
			username = "";
			password = "";

			// get the characters in the name box
			for (unsigned int i = 0; i < nameBox.glyphes; i++) {
				name += ((char*) nameBox.buffer.memory.ptr)[i];
			}
			// trim spaces
			name = trimSpaces(name);
			// check if name empty
			if (name.length() == 0) {
				isNameEmpty = true;
				isInvalidCustomer = true;
			} else {
				// else search for duplicates
				SearchCustomerVector = *customers;
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
			// trim spaces
			street = trimSpaces(street);
			// check if street empty
			if (street.length() == 0) {
				isStreetEmpty = true;
				isInvalidCustomer = true;
			}

			// get the characters in the state zip code box
			for (unsigned int i = 0; i < stateZipCodeBox.glyphes; i++) {
				stateZipCode += ((char*) stateZipCodeBox.buffer.memory.ptr)[i];
			}
			// trim spaces
			stateZipCode = trimSpaces(stateZipCode);
			// check if state zip code empty
			if (stateZipCode.length() == 0) {
				isStateEmpty = true;
				isInvalidCustomer = true;
			}

			// get the characters in the username box
			for (unsigned int i = 0; i < usernameBox.glyphes; i++) {
				username += ((char*) usernameBox.buffer.memory.ptr)[i];
			}
			// check if username empty, if so generate a default username
			if (username.length() == 0 && !isNameEmpty) {
				username = GenerateUsername(name);
			} else if (hasSpaces(username)) {
				// otherwise search for spaces
				isUsernameInvalid = true;
				isInvalidCustomer = true;
			} else {
				// otherwise search for duplicates
				SearchCustomerVector = *customers;
				while (!SearchCustomerVector.empty() && !isUsernameDuplicate) {
					if (SearchCustomerVector.front().GetUsername()
							== username) {
						isUsernameDuplicate = true;
						isInvalidCustomer = true;
					} else {
						SearchCustomerVector.erase(
								SearchCustomerVector.begin());
					}
				}
			}

			// get the characters in the password box
			for (unsigned int i = 0; i < passwordBox.glyphes; i++) {
				password += ((char*) passwordBox.buffer.memory.ptr)[i];
			}
			// check if password empty, if so generate a default password
			if (password.length() == 0) {
				password = GeneratePassword();
			}
			else if (hasSpaces(password)) {
				// otherwise check for spaces
				isPasswordInvalid = true;
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
						isPamphletReceived, isKey, rating, username, password,
						product1Value, product2Value, product3Value);

				customers->push_back(*newCustomer);

				std::sort(customers->begin(), customers->end());
				SaveCustomers(customers);
				issue_update();
				isNewCustomerAdded = true;
			}

		}
		zr_layout_row_dynamic(&context, 30, 1);
		if (zr_button_text(&context, "Main Menu", ZR_BUTTON_DEFAULT)) {
			changeWindow(ADMIN);
		}
		if (isNewCustomerAdded) {
			newCustomerNotification = "You have added customer "
					+ newCustomer->GetName() + " with username "
					+ newCustomer->GetUsername();
			zr_layout_row_dynamic(&context, 30, 1);
			zr_label(&context, newCustomerNotification.c_str(), ZR_TEXT_LEFT);
		}
	}
	zr_end(&context, window);
}

