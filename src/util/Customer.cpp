#include "Customer.h"

/******************
 ***CONSTRUCTOR ***
 ******************/
Customer::Customer() {
	name = "";
	street = "";
	stateZipCode = "";
	receivedPamphlet = false;
	isKey = false;
	rating = "not interested";
	username = "";
	password = "";
	minimumPurchases = 0;
	extremePurchases = 0;
	ultimatePurchases = 0;
}

// NON DEFAULT constructor
Customer::Customer(string customerName, string customerStreet,
		string customerStateZipCode, bool customerIsKey,
		string customerRating) {
	name = customerName;
	street = customerStreet;
	stateZipCode = customerStateZipCode;
	isKey = customerIsKey;
	rating = customerRating;
	receivedPamphlet = false;
	username = GenerateUsername(name);
	password = GeneratePassword();
	minimumPurchases = 0;
	extremePurchases = 0;
	ultimatePurchases = 0;
}

Customer::Customer(string customerName, string customerStreet,
		string customerStateZipCode, bool customerPamphlet, bool customerIsKey,
		string customerRating, string customerUsername, string customerPassword,
		unsigned int customerMinimumPurchases,
		unsigned int customerExtremePurchases,
		unsigned int customerUltimatePurchases) {
	name = customerName;
	street = customerStreet;
	stateZipCode = customerStateZipCode;
	receivedPamphlet = customerPamphlet;
	isKey = customerIsKey;
	rating = customerRating;
	username = customerUsername;
	password = customerPassword;
	minimumPurchases = customerMinimumPurchases;
	extremePurchases = customerExtremePurchases;
	ultimatePurchases = customerUltimatePurchases;
}

/******************
 *** DESTRUCTOR ***
 ******************/
Customer::~Customer() {
}

/******************
 ***  MUTATORS  ***
 ******************/

/************************************************************************
 * void SetValues

 * MUTATOR: Sets all values for customer
 * Return: none
 ***********************************************************************/
void Customer::SetValues(string customerName, string customerStreet,
		string customerStateZipCode, bool customerPamphlet, bool customerIsKey,
		string customerRating, string customerUsername, string customerPassword,
		unsigned int customerMinimumPurchases,
		unsigned int customerExtremePurchases,
		unsigned int customerUltimatePurchases) {
	name = customerName;
	street = customerStreet;
	stateZipCode = customerStateZipCode;
	receivedPamphlet = customerPamphlet;
	isKey = customerIsKey;
	rating = customerRating;
	username = customerUsername;
	password = customerPassword;
	minimumPurchases = customerMinimumPurchases;
	extremePurchases = customerExtremePurchases;
	ultimatePurchases = customerUltimatePurchases;
}

/************************************************************************
 * void SetName(string memName);
 * MUTATOR: Sets the Customers name
 * Return: none
 ***********************************************************************/
void Customer::SetName(string customerName) {
	name = customerName;
}

/************************************************************************
 * void SetStreet(string customerStreet);
 * MUTATOR: Changes the Customer's street
 * Return: none
 ***********************************************************************/
void Customer::SetStreet(string customerStreet) {
	street = customerStreet;
}

/************************************************************************
 * void SetStateZipCode (string customerStateZipCode);
 * MUTATOR: Changes the Customer's state and zip code
 * Return: none
 ***********************************************************************/
void Customer::SetStateZipCode(string customerStateZipCode) {
	stateZipCode = customerStateZipCode;
}

/************************************************************************
 * void SetReceivedPamphlet(Customer memNum);
 * MUTATOR: Sets the Customer's pamphlet status
 * Return: none
 ***********************************************************************/
void Customer::SetReceivedPamphlet(bool customerPamphlet) {
	receivedPamphlet = customerPamphlet;
}

/************************************************************************
 * void SetType(char memType);
 * MUTATOR: Sets whether the Customer is a regular Customer or key
 * Return: none
 ***********************************************************************/
void Customer::SetType(bool customerIsKey) {
	isKey = customerIsKey;
}

/************************************************************************
 * void SetRating(int customerRating);
 * MUTATOR: Sets the customer rating
 * Return: none
 ***********************************************************************/
void Customer::SetRating(string customerRating) {
	rating = customerRating;
}

/************************************************************************
 * AddMimimumPackage (unsigned int packages)
 * MUTATOR: Sets the customer rating
 * Return: none
 ***********************************************************************/
void Customer::AddMimimumPackage(unsigned int packages) {
	minimumPurchases += packages;
}

/************************************************************************
 * AddExtremePackage (unsigned int packages)
 * MUTATOR: Sets the customer rating
 * Return: none
 ***********************************************************************/
void Customer::AddExtremePackage(unsigned int packages) {
	extremePurchases += packages;
}

/************************************************************************
 * AddUltimatePackage (unsigned int packages)
 * MUTATOR: Sets the customer rating
 * Return: none
 ***********************************************************************/
void Customer::AddUltimatePackage(unsigned int packages) {
	ultimatePurchases += packages;
}

/******************
 ***  ACCESSORS ***
 ******************/

/************************************************************************
 * string GetName();
 * MUTATOR: none
 * Return: CustomerName
 ***********************************************************************/
string Customer::GetName() {
	return name;
}

/************************************************************************
 * string GetStreet();
 * Return: street
 ***********************************************************************/
string Customer::GetStreet() {
	return street;
}

/************************************************************************
 * string GetStateZipCode();
 * Return: stateZipCode
 ***********************************************************************/
string Customer::GetStateZipCode() {
	return stateZipCode;
}

/************************************************************************
 * bool GetPamphlet();
 * Return: true or false, the variable receivedPamphlet
 ***********************************************************************/
bool Customer::GetPamphlet() {
	return receivedPamphlet;
}

/************************************************************************
 * char GetCustomerType();
 * Return: true or false, the variable CustomerType
 ***********************************************************************/
bool Customer::GetIsKey() {
	return isKey;
}

/************************************************************************
 * string GetRating();
 * Return: rating
 ***********************************************************************/
string Customer::GetRating() {
	return rating;
}

/************************************************************************
 * string GetUsername();
 * Return: username
 ***********************************************************************/
string Customer::GetUsername() {
	return username;
}
/************************************************************************
 * string GetPassword();
 * Return: password
 ***********************************************************************/
string Customer::GetPassword() {
	return password;
}

/************************************************************************
 * unsigned int GetMinimumPurchases();
 * Return: unsigned int - # of minimum packages purchased
 ***********************************************************************/
unsigned int Customer::GetMinimumPurchases() {
	return minimumPurchases;
}

/************************************************************************
 * unsigned int GetExtremePurchases();
 * Return: unsigned int - # of extreme packages purchased
 ***********************************************************************/
unsigned int Customer::GetExtremePurchases() {
	return extremePurchases;
}

/************************************************************************
 * unsigned int GetUltimatePurchases();
 * Return: unsigned int - # of ultimate packages purchased
 ***********************************************************************/
unsigned int Customer::GetUltimatePurchases() {
	return ultimatePurchases;
}

/******************
 ***  UTILITY ***
 ******************/

/************************************************************************
 * bool operator<(const Customer &otherCustomer) const
 * DESCRIPTION: Overloads < operator for sorting
 * MUTATOR: none
 * Return: whether the object's name is alphabetically lower than the
 * other object's name
 ***********************************************************************/
bool Customer::operator<(const Customer &otherCustomer) const {
	return toupper(name) < toupper(otherCustomer.name);
}

/************************************************************************
 * ostream& Customer::operator<< (ostream& output, Customer& outputCustomer)
 * DESCRIPTION: Overloads << operator to display customer name
 * MUTATOR: none
 * Return: ostream of customer's name
 ***********************************************************************/
ostream& operator<< (ostream& output, Customer& outputCustomer) {
	output << outputCustomer.name;
	return output;
}
