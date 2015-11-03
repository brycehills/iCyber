#include "Customer.h"

/******************
 ***CONSTRUCTOR ***
 ******************/
Customer::Customer()
{
	name = "";
	address = "";
	receivedPamphlet = false;
	type = ' ';
	rating = 1;

}

// NON DEFAULT constructor
Customer::Customer(string customerName, string customerAddress,
		bool customerPamphlet, char customerType, int customerRating)
{
	name 	= customerName;
	address = customerAddress;
	receivedPamphlet = customerPamphlet;
	type 	= customerType;
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

void Customer::SetValues(string customerName, string customerAddress,
		bool customerPamphlet, char customerType, int customerRating)
{
	name		  		= customerName;
	address  	  		= customerAddress;
	receivedPamphlet 	= customerPamphlet;
	type          		= customerType;
	rating		  		= customerRating;
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
 * void SetCustomerAddress(string customerAddress);
 * MUTATOR: Sets the Customer's address
 * Return: none
 ***********************************************************************/
void Customer::SetCustomerAddress(string customerAddress)
{
	address = customerAddress;
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
void Customer::SetType(char customerType)
{
	type = customerType;
}

/************************************************************************
 * void SetRating(int customerRating);
 * MUTATOR: Sets the customer rating
 * Return: none
 ***********************************************************************/
void Customer::SetRating(int customerRating)
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
 * string GetCustomerNum();
 * MUTATOR: none
 * Return: CustomerNum
 ***********************************************************************/
string Customer::GetCustomerAddress()
{
	return address;
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
char Customer::GetType()
{
	return type;
}

/************************************************************************
 * char GetRating();
 * MUTATOR: none
 * Return: rating
 ***********************************************************************/
int Customer::GetRating()
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
	ostringstream out;

	out << left;
	out << setw(25) << name;
	out << setw(15) << address;
	out << setw(10) << type;
	out << setw(10) << rating;
	//out << setw(10) << receivedPamphlet;
	if(receivedPamphlet)
	{
		out << "Received";
	}
	else
	{
		out << "Not Received";
	}

	out << right;
	out << endl;

	return out.str();
}
