//Filename:		BST.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "BST.h"

//Constructor function
BST::BST ()
{
	root = NULL;
}

//Destructor function
BST::~BST ()
{
	postOrderDel (root);
}

//Inserts a new node to the tree
void BST::insert (PointTwoD p)
{
	insert (root, p);
}

//Recursive function to add a node
void BST::insert (NodePtr& root, PointTwoD p)
{
	if (root == NULL)
	{
		NodePtr pNew = new Node;
		pNew -> ptd = p;
		pNew -> left = NULL;
		pNew -> right = NULL;
		
		root = pNew;
	}
	
	else if (p > (root -> ptd))
		insert (root -> right, p);
	else
		insert (root -> left, p);
}

//Counts and returns the number of records
int BST::countNodes () const
{
	return countNodes (root);
}

//Recursive function to count the number of records
int BST::countNodes (NodePtr root) const
{
	if (root == NULL)
		return 0;
	else
		return 1 + countNodes (root -> left) + countNodes (root -> right);
}

//Displays the top n nodes with highest civIndex
void BST::displayTop (int& count, const int top)
{
	displayTop (root, count, top);
}

//Recursive function to display top n nodes with highest civIndex
void BST::displayTop (NodePtr root, int& count, const int top)
{
	if (root != NULL)
	{
		displayTop (root -> right, count, top);
		
		if (count < top)
		{
			cout<<count + 1<<")\t";
			cout<<root -> ptd<<endl;
			displayTop (root -> left, ++count, top);
		}
	}
}

//Checks if the coordinates already exist in the tree
// Returns true if it does, otherwise returns false
bool BST::alreadyExist (int x, int y) const
{
	return alreadyExist (root, x, y);
}

//Recursive function to check if a PointTwoD object with coordinates x and y already
//exist in the tree
// Returns true if it does, otherwise returns false
bool BST::alreadyExist (NodePtr root, int x, int y) const
{
	if (root == NULL)
		return false;
	else if (root -> ptd.getX () == x && root -> ptd.getY () == y)
			return true;
	else
		return alreadyExist (root -> left, x, y) || alreadyExist (root -> right, x, y);
}

//Deletes all the nodes of the BST
void BST::postOrderDel (NodePtr& root)
{
	if (root != NULL)
	{
		postOrderDel (root -> left);
		postOrderDel (root -> right);
		
		cout<<"Deleted node from tree with information:"<<endl
			<<root -> ptd.toString ()
			<<"--------------------------------------------------------"<<endl;
		delete root;
	}
}

//Displays civIndex and distance to and back from the location
void BST::displayNode (int x, int y) const
{
	displayNode (root, x, y);
}

//Recursive function to display civIndex and distance to and back from the location
void BST::displayNode (NodePtr root, int x, int y) const
{
	if (root != NULL)
	{
		if (root -> ptd.getX () == x && root -> ptd.getY () == y)
		{
			cout<<root -> ptd<<endl;
			cout<<"Distance to the location and back = "<<root -> ptd.computeDist ()
			<<" million km"<<endl;
		}
		else
		{
			displayNode (root -> left, x, y);
			displayNode (root -> right, x, y);
		}
	}
}

//Computes and stores the distances to and back from the top 5 locations in an array
void BST::getTopNDist (int& count, const int top, float dist[])
{
	getTopNDist (root, count, top, dist);
}


//Computes and stores the distances to and back from the top 5 locations in an array
//using recursion
void BST::getTopNDist (NodePtr root, int& count, const int top, float dist[])
{
	if (root != NULL)
	{
		getTopNDist (root -> right, count, top, dist);
		
		if (count < top)
		{
			dist [count] = root -> ptd.computeDist ();
			getTopNDist (root -> left, ++count, top, dist);
		}
	}
}

