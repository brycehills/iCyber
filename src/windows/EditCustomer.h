#ifndef WINDOWS_EDITCUSTOMER_H_
#define WINDOWS_EDITCUSTOMER_H_

#include "Window.h"
#include "../util/Loader.h" // save
#include "../util/StringOperations.h" // save

class EditCustomer : public Window {
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

	ostringstream stringStream;
	string output;

	string name;
	string street;
	string stateZipCode;
	bool isPamphletReceived;
	bool isKey;
	string username;
	string password;

	unsigned int searchIndex;

	string newCustomerNotification;

	bool isCustomerChanged;

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
	bool isNameDuplicate;
	bool isUsernameDuplicate;
	bool isUsernameInvalid;
	bool isPasswordInvalid;
	bool isInvalidCustomer;

	int findCustomer(string searchName);

public:
	EditCustomer(MyStack<TestimonialClass>* t, vector<Customer>* c, int *c_i) :
		Window(t, c, c_i) {
		ID = EDIT_CUSTOMER;
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
		searchIndex = 0;
		currentRatingInt = 0;
		ratingComboBoxState = 0;
		isKey = false;
		isPamphletReceived = false;
		isCustomerChanged = false;
		isUsernameDuplicate = false;
		isInvalidCustomer = false;
		isUsernameInvalid = false;
		isPasswordInvalid = false;

		if (*customer_index != -1) {
			if (customers->at(*customer_index).GetIsKey()) {
				isKeyBoxUnTicked = 0;
			} else {
				isKeyBoxUnTicked = 1;
			}
			if (customers->at(*customer_index).GetPamphlet()) {
				isPamphletBoxUnTicked = 0;
			}
			else {
				isPamphletBoxUnTicked = 1;
			}
			product1Value = customers->at(*customer_index).GetMinimumPurchases();
			product2Value = customers->at(*customer_index).GetExtremePurchases();
			product3Value = customers->at(*customer_index).GetUltimatePurchases();
			zr_edit_box_add(&nameBox, customers->at(*customer_index).GetName().c_str(), customers->at(*customer_index).GetName().size());
			zr_edit_box_add(&streetBox, customers->at(*customer_index).GetStreet().c_str(), customers->at(*customer_index).GetStreet().size());
			zr_edit_box_add(&stateZipCodeBox, customers->at(*customer_index).GetStateZipCode().c_str(), customers->at(*customer_index).GetStateZipCode().size());
			zr_edit_box_add(&usernameBox, customers->at(*customer_index).GetUsername().c_str(), customers->at(*customer_index).GetUsername().size());
		} else {
			isPamphletBoxUnTicked = 1;
			isKeyBoxUnTicked = 1;
			product1Value = 0;
			product2Value = 0;
			product3Value = 0;
			zr_edit_box_clear(&nameBox);
			zr_edit_box_clear(&streetBox);
			zr_edit_box_clear(&stateZipCodeBox);
			zr_edit_box_clear(&usernameBox);
			zr_edit_box_clear(&passwordBox);
		}
	}
	~EditCustomer() {}
	void render_main(zr_window *);
	void init() {
		isNameDuplicate = false;
		searchIndex = 0;
		currentRatingInt = 0;
		ratingComboBoxState = 0;
		isKey = false;
		isPamphletReceived = false;
		isCustomerChanged = false;
		isPamphletBoxUnTicked = 1;
		isUsernameDuplicate = false;
		isInvalidCustomer = false;
		isUsernameInvalid = false;
		isPasswordInvalid = false;

		if (*customer_index != -1) {
			if (customers->at(*customer_index).GetIsKey()) {
				isKeyBoxUnTicked = 0;
			} else {
				isKeyBoxUnTicked = 1;
			}
			if (customers->at(*customer_index).GetPamphlet()) {
				isPamphletBoxUnTicked = 0;
			}
			else {
				isPamphletBoxUnTicked = 1;
			}
			product1Value = customers->at(*customer_index).GetMinimumPurchases();
			product2Value = customers->at(*customer_index).GetExtremePurchases();
			product3Value = customers->at(*customer_index).GetUltimatePurchases();
			zr_edit_box_add(&nameBox, customers->at(*customer_index).GetName().c_str(), customers->at(*customer_index).GetName().size());
			zr_edit_box_add(&streetBox, customers->at(*customer_index).GetStreet().c_str(), customers->at(*customer_index).GetStreet().size());
			zr_edit_box_add(&stateZipCodeBox, customers->at(*customer_index).GetStateZipCode().c_str(), customers->at(*customer_index).GetStateZipCode().size());
			zr_edit_box_add(&usernameBox, customers->at(*customer_index).GetUsername().c_str(), customers->at(*customer_index).GetUsername().size());
		} else {
			isPamphletBoxUnTicked = 1;
			isKeyBoxUnTicked = 1;
			product1Value = 0;
			product2Value = 0;
			product3Value = 0;
			zr_edit_box_clear(&nameBox);
			zr_edit_box_clear(&streetBox);
			zr_edit_box_clear(&stateZipCodeBox);
			zr_edit_box_clear(&usernameBox);
			zr_edit_box_clear(&passwordBox);
		}
	}
};

#endif /* WINDOWS_EDITCUSTOMER_H_ */
