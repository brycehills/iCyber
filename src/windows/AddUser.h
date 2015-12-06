#ifndef WINDOWS_ADDUSER_H_
#define WINDOWS_ADDUSER_H_

#include "Window.h"
#include "../util/Loader.h" // save
#include "../util/StringOperations.h" // save

class AddUser : public Window {
private:
	zr_edit_box nameBox;
	zr_edit_box streetBox;
	zr_edit_box stateZipCodeBox;
	zr_edit_box usernameBox;
	zr_edit_box passwordBox;
	zr_context ratingComboBox;
	unsigned int ratingComboBoxState;
	zr_char name_buffer[MAX_BUFFER];
	zr_char street_buffer[MAX_BUFFER];
	zr_char stateZipCode_buffer[MAX_BUFFER];
	zr_char username_buffer[MAX_BUFFER];
	zr_char password_buffer[MAX_BUFFER];
	vector<Customer> SearchCustomerVector;

	string name;
	string street;
	string stateZipCode;
	bool isPamphletReceived;
	bool isKey;
	string username;
	string password;

	string newCustomerNotification;

	bool isNewCustomerAdded;

	string rating;
	int currentRatingInt;

	int isKeyBoxUnTicked;
	int isPamphletBoxUnTicked;

	unsigned int product1State;
	int product1Value;
	unsigned int product2State;
	int product2Value;
	unsigned int product3State;
	int product3Value;

	Customer *newCustomer;

	// error checking
	bool isNameEmpty;
	bool isNameDuplicate;
	bool isStreetEmpty;
	bool isStateEmpty;
	bool isUsernameDuplicate;
	bool isUsernameInvalid;
	bool isPasswordInvalid;
	bool isInvalidCustomer;

public:
	AddUser(MyStack<TestimonialClass>* t, vector<Customer>* c, int *c_i) :
		Window(t, c, c_i) {
		ID = ADD_USER;
		zr_edit_box_init_fixed(&nameBox, name_buffer, MAX_BUFFER, NULL, NULL);
		zr_edit_box_init_fixed(&streetBox, street_buffer, MAX_BUFFER, NULL,
				NULL);
		zr_edit_box_init_fixed(&stateZipCodeBox, stateZipCode_buffer,
				MAX_BUFFER, NULL, NULL);
		zr_edit_box_init_fixed(&usernameBox, username_buffer, MAX_BUFFER, NULL,
				NULL);
		zr_edit_box_init_fixed(&passwordBox, password_buffer, MAX_BUFFER, NULL,
				NULL);
		isNameDuplicate = false;
		currentRatingInt = 0;
		ratingComboBoxState = 0;
		product1Value = 0;
		product2Value = 0;
		product3Value = 0;
		isKey = false;
		isPamphletReceived = false;
		isNewCustomerAdded = false;
		isKeyBoxUnTicked = 1;
		isPamphletBoxUnTicked = 1;
		isNameEmpty = false;
		isStateEmpty = false;
		isStreetEmpty = false;
		isUsernameDuplicate = false;
		isInvalidCustomer = false;
		isUsernameInvalid = false;
		isPasswordInvalid = false;
	}
	~AddUser() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&nameBox);
		zr_edit_box_clear(&streetBox);
		zr_edit_box_clear(&stateZipCodeBox);
		zr_edit_box_clear(&usernameBox);
		zr_edit_box_clear(&passwordBox);
		isNameDuplicate = false;
		currentRatingInt = 0;
		ratingComboBoxState = 0;
		product1Value = 0;
		product2Value = 0;
		product3Value = 0;
		isKey = false;
		isPamphletReceived = false;
		isNewCustomerAdded = false;
		isKeyBoxUnTicked = 1;
		isPamphletBoxUnTicked = 1;
		isNameEmpty = false;
		isStateEmpty = false;
		isStreetEmpty = false;
		isUsernameDuplicate = false;
		isInvalidCustomer = false;
		isUsernameInvalid = false;
		isPasswordInvalid = false;
	}
};




#endif /* WINDOWS_ADDUSER_H_ */
