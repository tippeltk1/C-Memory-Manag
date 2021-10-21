//------------------------------------------------------------------------
// A linked list that holds all the companies, allows inderting, deleting
// and displaying
//------------------------------------------------------------------------
#ifndef _LLIST_H
#define _LLIST_H
#include "Company.h"
typedef Company InfoType;

class LList
{
public:
	//---------------------------------------------------------------------
	// Creates a new list and sets the list to NULL
	//---------------------------------------------------------------------
	LList() { list = NULL; }
	//---------------------------------------------------------------------
	// Delets all items in the list
	//---------------------------------------------------------------------
	~LList();    
	//---------------------------------------------------------------------
	// Returns true if the list is empty
	//---------------------------------------------------------------------
	bool IsEmpty() const;
	//---------------------------------------------------------------------
	// Inserts a new item into the list if it is not already in the list
	//---------------------------------------------------------------------
	bool Insert(InfoType * x_ptr);
	//---------------------------------------------------------------------
	// Deletes an item from the list if the item is in the list
	//---------------------------------------------------------------------
	bool Delete(const InfoType & x);
	//---------------------------------------------------------------------
	// Displays all items in the list
	//---------------------------------------------------------------------
	void Display(ostream & out_stream) const;

private:
	//---------------------------------------------------------------------
	// Creates a new node list 
	//---------------------------------------------------------------------
	struct Node
	{
		Node(InfoType * x, Node * p = NULL) { infoPtr = x;  next = p; }
		~Node() { delete infoPtr; }
		InfoType * infoPtr;
		Node * next;
	};
	Node * list;
	LList(const LList & copyFrom);
	LList & operator= (const LList & assignFrom);
};
#endif 