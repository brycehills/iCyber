
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include <sstream>
#include<iomanip>

using namespace std;

/************************************************************************
 * Customer CLASS
 * This class represents Customer of the iCyber product. It is used to
 * store information on the customer.
 ***********************************************************************/
class Customer
{

public:

	//CONSTRUCTORS
	Customer();
	Customer(string customerName, string customerAddress,
			bool customerPamphlet, char customerType, int customerRating);

	//DESTRUCTOR
	~Customer();


	/******************
	 ***  MUTATORS  ***
	 ******************/

	void SetValues(string customerName, string customerAddress,
			bool customerPamphlet, char customerType, int customerRating);

	/************************************************************************
	 * void SetName(string memName);
	 * MUTATOR: Changes the Customers name
	 * Return: none
	 ***********************************************************************/
	void SetName(string memName);

	/************************************************************************
	 * void SetCustomerNumber(Customer memNum);
	 * MUTATOR: Changes the Customer's address
	 * Return: none
	 ***********************************************************************/
	void SetCustomerAddress(string customerAddress);

	/************************************************************************
	 * void SetType(char customerType);
	 * MUTATOR: Changes whether the Customer is a regular or key customer
	 * Return: none
	 ***********************************************************************/
	void SetReceivedPamphlet(bool customerPamphlet);

	/************************************************************************
	 * void SetType(char customerType);
	 * MUTATOR: Changes whether the Customer is a regular or key customer
	 * Return: none
	 ***********************************************************************/
	void SetType(char customerType);

	/************************************************************************
	 * void SetType(char customerType);
	 * MUTATOR: Changes whether the Customer is a regular or key customer
	 * Return: none
	 ***********************************************************************/
	void SetRating(int customerRating);


	/******************
	 ***  ACCESSORS ***
	 ******************/

	/************************************************************************
	 * string GetName();
	 * ACCESSOR: none
	 * Return: CustomerName
	 ***********************************************************************/
	string GetName();

	/************************************************************************
	 * string GetCustomerNumber();
	 * ACCESSOR: none
	 * Return: CustomerAddress
	 ***********************************************************************/
	string GetCustomerAddress();

	/************************************************************************
	 * bool GetPamphlet();
	 * ACCESSOR: none
	 * Return: Bool if customer has pamphlet
	 ***********************************************************************/
	bool GetPamphlet();


	/************************************************************************
	 * char GetType();
	 * ACCESSOR: none
	 * Return: type
	 ***********************************************************************/
	char GetType();

	/************************************************************************
	 * int GetRating();
	 * ACCESSOR: none
	 * Return: int - rating of customer
	 ***********************************************************************/
	int GetRating();


	/******************
	 ***  METHODS   ***
	 ******************/



	/************************************************************************
	 * string Print()
	 * MUTATOR: none
	 * Return: a string with all the Customer's data
	 ***********************************************************************/
	string Print();


private:
    string name;			/// OUT - name of customer
    string address;			/// OUT - Customer number of customer
    bool receivedPamphlet;	/// OUT - if customer has received pamphlet or not
    char type;				/// OUT - tells if Customer is regular or executive
    int rating;				/// OUT - Customer rating


};


#endif /* CUSTOMER_H_ */
