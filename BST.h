//Filename:		BST.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "LinkedList.h"

class BST
{
	public:
		//Constructor function
		BST ();
		
		//Destructor function
		~BST ();
		
		//Inserts a new node to the tree
		void insert (PointTwoD);
		
		//Counts and returns the number of records
		int countNodes () const;
		
		//Displays the top n nodes with highest civIndex
		void displayTop (int&, const int);
		
		//Checks if the coordinates already exist in the tree
		bool alreadyExist (int, int) const;
		
		//Displays civIndex and distance to and back from the location
		void displayNode (int, int) const;
		
		//Computes and stores the distances to and back from the top 5 locations in an array
		void getTopNDist (int&, const int, float []);
		
	private:
		struct Node;
		typedef Node* NodePtr;
		
		struct Node
		{
			PointTwoD ptd;
			NodePtr left, right;
		};
		
		NodePtr root;
		
		//Deletes all the nodes of the BST
		void postOrderDel (NodePtr&);
		
		//Recursive function to add a node
		void insert (NodePtr&, PointTwoD);
		
		//Recursive function to count the number of records
		int countNodes (NodePtr) const;
		
		//Recursive function to display top n nodes with highest civIndex
		void displayTop (NodePtr, int&, const int);
		
		//Recursive function to check if a PointTwoD object with coordinates x and y already
		//exist in the tree
		// Returns true if it does, otherwise returns false
		bool alreadyExist (NodePtr, int, int) const;
		
		//Recursive function to display civIndex and distance to and back from the location
		void displayNode (NodePtr, int, int) const;
		
		//Computes and stores the distances to and back from the top 5 locations in an array
		//using recursion
		void getTopNDist (NodePtr, int&, const int, float[]);
};

