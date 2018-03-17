//Filename:		LinkedList.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "LinkedList.h"

//Constructor function
LinkedList::LinkedList ()
{
	head = NULL;
}

//Destructor function
LinkedList::~LinkedList ()
{
	NodePtr temp;
	
	while (head != NULL)
	{
		temp = head;
		head = head -> next;
		
		PointTwoD item = temp -> ptd;
		delete temp;
		
		cout<<"Deleted node from linked list containing information:"<<endl;
		cout<<item.toString ();
		cout << "------------------------------------------" << endl;
	}
}

//Adds a node at the head of list
void LinkedList::addHead (PointTwoD p)
{
	NodePtr pNew = new Node;
	pNew -> ptd = p;
	
	pNew -> next = head;
	head = pNew;
}

//Computes civIndex for all nodes and returns the number of nodes
int LinkedList::updateList ()
{
	return updateList (head);
}

// Recursive function to update all the nodes
int LinkedList::updateList (NodePtr& head)
{
	if (head == NULL)
		return 0;
	else
	{
		head -> ptd.computeCivIndex ();
		return 1 + updateList (head -> next);
	}
}

//Removes the head node and returns the PointTwoD object it contains
PointTwoD LinkedList::removeHead ()
{
	NodePtr temp;
	PointTwoD item;
	
	temp = head;
	head = head -> next;
	
	item = temp -> ptd;
	
	delete temp;
	
	return item;
}

//Returns true if the list is empty, otherwise returns false
bool LinkedList::isEmpty () const
{
	return head == NULL;
}

//Checks if the coordinates already exist in the tree
// Returns true if it does, otherwise returns false
bool LinkedList::alreadyExist (int x, int y) const
{
	return alreadyExist (head, x, y);
}

//Recursive function to check if a PointTwoD object with coordinates x and y already
//exist in the list
// Returns true if it does, otherwise returns false
bool LinkedList::alreadyExist (NodePtr root, int x, int y) const
{
	if (root == NULL)
		return false;
	else if (root -> ptd.getX () == x && root -> ptd.getY () == y)
		return true;
	else
		return alreadyExist (root -> next, x, y);
}

