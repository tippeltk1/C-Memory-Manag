//---------------------------------------------------------------------
// Takes the user input and calls classes to handle the input
// Reads in commands and outputs information 
//---------------------------------------------------------------------

#include "Company.h"
#include "Directory.h"
#include "LList.h"
#include <iostream>
using namespace std;

void Directory::Run()
{
	int numCompanies;
	cin >> numCompanies;
	cout << "There are " << numCompanies << " companies initially in the directory." << endl;
	cout << "They will be read in and inserted in the list in order." << endl;
	for (int i = 0; i < numCompanies; i++)
		Insert();

	char command;
	cin >> command;
	cout << endl;
	while (command != 'S')
	{
		switch (command)
		{
		case 'I':
			Insert();
			break;
		case 'D':
			Delete();
			break;
		case 'P':
			Print();
			break;
		default:
			cout << "Invalid command!" << endl;
			break;
		}
		cout << endl;
		cin >> command;
	}
	companyList.~LList();
	cout << "Normal Termination of program 2!" << endl;
	cin.ignore();
}

void Directory::Insert()
{
	Company * c = new Company;
	cin >> *c;
	bool inserted = companyList.Insert(c);
	if (inserted == true)
		cout << "Added to directory:     " << *c;
	else
	{
		cout << "Already in directory:   " << *c;
		delete c;
	}	
}

void Directory::Delete()
{
	Company *c = new Company;
	cin >> *c;
	bool deleted = companyList.Delete(*c);
	if (deleted)
	{
		cout << "Deleted from directory: " << *c;
		delete c;
	}
	else
	{
		cout << "Wasn't in directory:    " << *c;
		delete c;
	}
}

void Directory::Print()
{
	cout << "Below are the companies currently in the directory:" << endl;
	companyList.Display(cout);
}