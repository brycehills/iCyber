/*************************************************************************
 * AUTHOR        : Bryce Hills
 * STUDENT ID    : 104910
 * Project 1	 : iCyber Project
 * CLASS         : CS1C
 * SECTION       : M-W 5:30pm
 * DUE DATE      : eventually
 ************************************************************************/
#include "header.h"
#include "CustomerList.h"
#include "Customer.h"


int main()
{
	//driver for customerlist

	CustomerList customerObj;		//CALC & OUT - customerlist object

	//adding customers
	customerObj.AddCustomer("Bryce", "12 Main St", true, 'K', 8);
	customerObj.AddCustomer("Kevin", "101 Blue Blvd", false, 'R', 6);
	customerObj.AddCustomer("Daniel", "33 Elm Street", true, 'R', 7);
	customerObj.AddCustomer("Steve", "22 Steve Ave", false, 'K', 9);
	customerObj.AddCustomer("Tom", "44 Tom St", true, 'K' , 10);

	//printing list
	cout << customerObj.PrintCustomerList();
	cout << endl << endl;


	//deleteing customers
	customerObj.RemoveCustomer("Bryce");
	customerObj.RemoveCustomer("Daniel");

	//printing list
	cout << customerObj.PrintCustomerList();


	return 0;
}
