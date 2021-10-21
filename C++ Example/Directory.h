//---------------------------------------------------------------------
// Takes the user input and calls classes to handle the input
// Reads in commands and outputs information 
//---------------------------------------------------------------------
#ifndef _DIRECTORY_H
#define _DIRECTORY_H
#include "LList.h"

class Directory
{
public:
	//---------------------------------------------------------------------
	// // Handle user input and calls classes to handle the input
	//---------------------------------------------------------------------
	void Run();

private:
	LList companyList; 
	//---------------------------------------------------------------------
	// Reads in a company and inserts the company into the linked list 
	// If the company is already in the list, it is not added
	//---------------------------------------------------------------------
	void Insert();
	//---------------------------------------------------------------------
	// Reads a company from the user and delets the company from the list 
	// If the company is not in the list, it is not deleted
	//---------------------------------------------------------------------
	void Delete();
	//---------------------------------------------------------------------
	// Prints all companies in the linked list 
	//---------------------------------------------------------------------
	void Print();
};
#endif 