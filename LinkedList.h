//Filename:		LinkedList.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "PointTwoD.h"

class LinkedList
{
	public:
		//Constructor function
		LinkedList ();
		
		//Destructor function
		~LinkedList ();
		
		//Adds a node at the head of list
		void addHead (PointTwoD);
		
		//Computes civIndex for all nodes and returns the number of nodes
		int updateList ();
		
		//Removes the head node and returns the PointTwoD object it contains
		PointTwoD removeHead ();
		
		//Checks if list is empty
		bool isEmpty () const;
		
		//Checks if the coordinates already exist in the list
		bool alreadyExist (int, int) const;
		
	private:
		struct Node;
		typedef Node* NodePtr;
		
		struct Node
		{
			PointTwoD ptd;
			NodePtr next;
		};
		
		NodePtr head;
		
		// Recursive function to update all the nodes
		int updateList (NodePtr&);
		
		//Recursive function to check if a PointTwoD object with coordinates x and y already
		//exist in the list
		// Returns true if it does, otherwise returns false
		bool alreadyExist (NodePtr, int, int) const;
};

