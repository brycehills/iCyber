#include "Customer.h"

/******************
 ***CONSTRUCTOR ***
 ******************/
Customer::Customer()
{
	name = "";
	street = "";
	stateZipCode = "";
	receivedPamphlet = false;
	isKey = false;
	rating = "not interested";

}

// NON DEFAULT constructor
Customer::Customer(string customerName, string customerStreet, string customerStateZipCode,
		bool customerPamphlet, bool customerIsKey, string customerRating)
{
	name 	= customerName;
	street = customerStreet;
	stateZipCode = customerStateZipCode;
	receivedPamphlet = customerPamphlet;
	isKey 	= customerIsKey;
	rating 	= customerRating;
}

/******************
 *** DESTRUCTOR ***
 ******************/
Customer::~Customer(){}


/******************
 ***  MUTATORS  ***
 ******************/

/************************************************************************
 * void SetValues(string customerName, string customerAddress,
		bool customerPamphlet, char customerType, int customerRating)

 * MUTATOR: Sets all values for customer
 * Return: none
 ***********************************************************************/

void Customer::SetValues(string customerName, string customerStreet,
		string customerStateZipCode, bool customerPamphlet, bool customerIsKey,
		string customerRating)
{
	name 	= customerName;
	street = customerStreet;
	stateZipCode = customerStateZipCode;
	receivedPamphlet = customerPamphlet;
	isKey 	= customerIsKey;
	rating 	= customerRating;
}


/************************************************************************
 * void SetName(string memName);
 * MUTATOR: Sets the Customers name
 * Return: none
 ***********************************************************************/
void Customer::SetName(string customerName)
{
	name = customerName;
}

/************************************************************************
 * void SetStreet(string customerStreet);
 * MUTATOR: Changes the Customer's street
 * Return: none
 ***********************************************************************/
void Customer::SetStreet(string customerStreet)
{
	street = customerStreet;
}

/************************************************************************
 * void SetStateZipCode (string customerStateZipCode);
 * MUTATOR: Changes the Customer's state and zip code
 * Return: none
 ***********************************************************************/
void Customer::SetStateZipCode(string customerStateZipCode)
{
	stateZipCode = customerStateZipCode;
}

/************************************************************************
 * void SetReceivedPamphlet(Customer memNum);
 * MUTATOR: Sets the Customer's pamphlet status
 * Return: none
 ***********************************************************************/
void Customer::SetReceivedPamphlet(bool customerPamphlet)
{
	receivedPamphlet = customerPamphlet;
}

/************************************************************************
 * void SetType(char memType);
 * MUTATOR: Sets whether the Customer is a regular Customer or key
 * Return: none
 ***********************************************************************/
void Customer::SetType(bool customerIsKey)
{
	isKey = customerIsKey;
}

/************************************************************************
 * void SetRating(int customerRating);
 * MUTATOR: Sets the customer rating
 * Return: none
 ***********************************************************************/
void Customer::SetRating(string customerRating)
{
	rating = customerRating;
}


/******************
 ***  ACCESSORS ***
 ******************/

/************************************************************************
 * string GetName();
 * MUTATOR: none
 * Return: CustomerName
 ***********************************************************************/
string Customer::GetName()
{
	return name;
}

/************************************************************************
 * string GetStreet();
 * ACCESSOR: none
 * Return: street
 ***********************************************************************/
string Customer::GetStreet()
{
	return street;
}

/************************************************************************
 * string GetStateZipCode();
 * ACCESSOR: none
 * Return: stateZipCode
 ***********************************************************************/
string Customer::GetStateZipCode()
{
	return stateZipCode;
}

/************************************************************************
 * bool GetPamphlet();
 * MUTATOR: none
 * Return: true or flase
 ***********************************************************************/
bool Customer::GetPamphlet()
{
	return receivedPamphlet;
}

/************************************************************************
 * char GetCustomerType();
 * MUTATOR: none
 * Return: CustomerType
 ***********************************************************************/
bool Customer::GetIsKey()
{
	return isKey;
}

/************************************************************************
 * char GetRating();
 * MUTATOR: none
 * Return: rating
 ***********************************************************************/
string Customer::GetRating()
{
	return rating;
}


/******************
 ***  METHODS   ***
 ******************/


/************************************************************************
 * string Print()
 * MUTATOR: none
 * Return: a string with all the Customer's data
 ***********************************************************************/
string Customer::Print()
{
//	ostringstream out;
//
//	out << left;
//	out << setw(25) << name;
//	out << setw(15) << address;
//	if(isKey)
//	{
//		out << setw(10) << "key";
//	}
//	else
//	{
//		out << setw(10) << "nice to have";
//	}
//	out << setw(10) << rating;
//	if(receivedPamphlet)
//	{
//		out << "Received";
//	}
//	else
//	{
//		out << "Not Received";
//	}
//
//	out << right;
//	out << endl;
//
//	return out.str();
	return "null";
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
	return name < otherCustomer.name;
}
