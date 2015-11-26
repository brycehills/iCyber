#ifndef WINDOWS_ADDUSER_H_
#define WINDOWS_ADDUSER_H_

#include "Window.h"

class AddUser : public Window {
private:
	zr_edit_box nameBox;
	zr_edit_box streetBox;
	zr_edit_box stateZipCodeBox;
	zr_context ratingComboBox;
	unsigned int ratingComboBoxState;
	zr_char name_buffer[MAX_BUFFER];
	zr_char street_buffer[MAX_BUFFER];
	zr_char stateZipCode_buffer[MAX_BUFFER];

	string name;
	string street;
	string stateZipCode;
	bool isPamphletReceived;
	bool isKey;

	bool isNewCustomerAdded;

	string rating;
	int currentRatingInt;

	int isKeyBoxUnTicked;
	int isPamphletBoxUnTicked;

	Customer *newCustomer;

	// error checking
	bool isNameEmpty;
	bool isNameDuplicate;
	bool isStreetEmpty;
	bool isStateEmpty;
	bool isInvalidCustomer;
public:
	AddUser(Member **m, int *n_m) : Window(m, n_m) {
		ID = ADD_USER;
		zr_edit_box_init_fixed(&nameBox, name_buffer, MAX_BUFFER, NULL, NULL);
		zr_edit_box_init_fixed(&streetBox, street_buffer, MAX_BUFFER, NULL, NULL);
		zr_edit_box_init_fixed(&stateZipCodeBox, stateZipCode_buffer, MAX_BUFFER, NULL, NULL);
		isNameDuplicate = false;
		currentRatingInt = 0;
		ratingComboBoxState = 0;
		isKey = false;
		isPamphletReceived = false;
		isNewCustomerAdded = false;
		isKeyBoxUnTicked = 1;
		isPamphletBoxUnTicked = 1;
		isNameEmpty = false;
		isStateEmpty = false;
		isInvalidCustomer = false;
		isStreetEmpty = false;
	}
	~AddUser() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&nameBox);
		zr_edit_box_clear(&streetBox);
		zr_edit_box_clear(&stateZipCodeBox);
		isKeyBoxUnTicked = 1;
		isPamphletBoxUnTicked = 1;
	}
};




#endif /* WINDOWS_ADDUSER_H_ */
