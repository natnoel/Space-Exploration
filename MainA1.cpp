//Filename:		MainA1.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "BST.h"

const int TOP = 5;	//Top 5 exploration destination

class MissionPlan
{
	public:
		int main ()
		{
			do
			{
				//Display main menu
				cout<<"Welcome to Mission Plan program!"<<endl<<endl
					<<"1)	Input statistical data"<<endl
					<<"2)	Compute civ. index value (for all records)"<<endl
					<<"3)	Print top 5 exploration destinations"<<endl
					<<"4)	Print total travel distance"<<endl
					<<"5)	Display civIndex and travel distance to and back from a location"
					<<endl
					<<"6)	Exit"<<endl<<endl
					<<"Please enter your choice : ";
					
				cin>>option;	//Enter option
				
				cout<<endl;
				
				switch (option)
				{
					case '1':	try
								{
									//Entering the attributes of a PointTwoD object
									cout<<"[ Input statistical data ]"<<endl
										<<"Please enter x-ordinate : ";
									cin>>x;
									
									cout<<"Please enter y-ordinate : ";
									cin>>y;
									
									cout<<"Please enter sun type : ";
									cin.clear ();
									cin.ignore (100, '\n');
									getline (cin, sunType);
									
									cout<<"Please enter no. of earth-like planets : ";
									cin>>earthLikePlanets;
									
									cout<<"Please enter no. of earth-like moons : ";
									cin>>earthLikeMoons;
									
									cout<<"Please enter ave. particulate density (%-tage) : ";
									cin>>aveParticulateDensity;
									
									cout<<"Please enter ave. plasma density (%-tage) : ";
									cin>>avePlasmaDensity;
									
									cout<<endl;
									
									if (!verifyData ())	//Checks for error in the entry
										throw errorCode;
									
									//Sets the attribute variables of a PointTwoD object
									planet.setX (x);
									planet.setY (y);
									planet.setLocationData (sunType, earthLikePlanets, 
										earthLikeMoons, aveParticulateDensity, 
										aveParticulateDensity);
									
									//Adds the PointTwoD object into the linked list
									entry.addHead (planet);
									
									cout<<"Record successfully stored. "
										<<"Going back to main menu ..."<<endl;
								}
								catch (int e)	//Displaying where the error lies
								{
									cout<<"Invalid ";
									switch (errorCode)
									{
										case 0:	cout<<"sun type ";
												break;
										case 1:	cout<<"earth-like planets ";
												break;
										case 2:	cout<<"earth-like moons ";
												break;
										case 3:	cout<<"ave. particulate density ";
												break;
										case 4:	cout<<"ave. plasma density ";
												break;
										default:cout<<"coordinates ";
									}
									cout<<"entered!"<<endl;
									if (errorCode == 5)
										cout<<"x and y coordinates already exist!"<<endl;
								}
								
								break;
								
					case '2':	//Computes the civIndex for each PointTwoD object in the
								//linked list and stores the number of nodes to the
								//"update" variable
								updated = entry.updateList ();
					
								//Transferring data from linked list to tree
								//while at the same time deleting the linked list
								while (!entry.isEmpty ())
									recordTree.insert(entry.removeHead ());
								
								cout<<"Computation completed! ("<<updated<<" records were "
									<<"updated)"<<endl;
								break;
								
					case '3':	//Displays number of nodes in the tree
								//(the tree only contains nodes with civIndex computed)
								//(or updated nodes only)
								cout<<"Total no. of records available = "
									<<recordTree.countNodes ()<<endl
									<<"Printing top "<<TOP<<" exploration destinations..."
									<<endl;
									
								count = 0;	//Initialising count to 0
								
								//Displays top TOP (5) location with the highest civIndex
								recordTree.displayTop (count, TOP);
								
								//If number of nodes in the 3 are less than 5
								//display the following
								while (count < TOP)
									cout<<++count<<")\t<no other records available>"<<endl;
								
								break;
								
					case '4':	count = 0;		//Initialising count to 0
					
								recordTree.getTopNDist (count, TOP, topNDist);
								
								totalDist = 0;	//Initialising totalDist to 0
								
								for (int i = 0; i < count; i++)
									totalDist += topNDist [i];
								
								//Displays total travel distance
								cout<<"Total (approx) travel distance = "
									<<totalDist<<" million km"<<endl;
									
								break;
								
					case '5':	cout<<"Enter x-ordinate : ";
								cin>>x;
								cout<<"Enter y-ordinate : ";
								cin>>y;
								
								cout<<endl;
								
								//If record exist but not updated
								if (entry.alreadyExist (x, y))
									cout<<"Please compute civ. index value before proceeding"
										<<endl;
										
								//If updated record available
								else if (recordTree.alreadyExist (x, y))
									recordTree.displayNode (x, y);
									
								//If cannot find the record
								else
									cout<<"Cannot find location ("<<x<<", "<<y
										<<") in records!"<<endl;
								
								break;
								
					case '6':	cout<<"Have a nice day!"<<endl;	//Exit option
								break;
								
					default:	cout<<"Invalid option!"<<endl;	//Invalid option entered
				}
				cout<<"--------------------------------------------------------"<<endl<<endl;
			} while (option != '6');
			
			cout<<"End of Mission Plan program"<<endl<<endl;
			
			return 0;
		}
	private:
		char option;
		int x, y, earthLikePlanets, earthLikeMoons, errorCode, updated, count;
		float aveParticulateDensity, avePlasmaDensity, totalDist;
		float topNDist [TOP];	//Stores the distances to and back from the top five locations
		string sunType;
		PointTwoD planet;
		LinkedList entry;	//Used to store new entries that are not updated
		BST recordTree;		//Used to store updated records
		
		bool verifyData ();	//Checks if data entered are correct
};

//Returns true if data is correctly entered, otherwise returns false
//Also sets the errorCode if data entered is invalid
bool MissionPlan::verifyData ()
{
	bool valid = true;
	
	if (sunType != "Type O" && sunType != "Type B" && sunType != "Type A" &&
		sunType != "Type F"	&& sunType != "Type G" && sunType != "Type K" &&
		sunType != "Type M")	//If incorrect sunType entered
	{
		errorCode = 0;
		valid = false;
	}
	else if (earthLikePlanets < 0)	//If incorrect earthLikePlanets entered
	{
		errorCode = 1;
		valid = false;
	}
	else if (earthLikeMoons < 0)	//If incorrect earthLikeMoons entered
	{
		errorCode = 2;
		valid = false;
	}
	//If incorrect aveParticulateDensity entered
	else if (aveParticulateDensity < 0 || aveParticulateDensity > 100)
	{
		errorCode = 3;
		valid = false;
	}
	//If incorrect avePlasmaDensity entered
	else if (avePlasmaDensity < 0 || avePlasmaDensity > 100)
	{
		errorCode = 4;
		valid = false;
	}
	//If coordinates already exist
	else if (recordTree.alreadyExist (x, y) || entry.alreadyExist (x, y))
	{
		errorCode = 5;
		valid = false;
	}
	
	return valid;
}

int main ()
{	 
	MissionPlan a;
	a.main ();
}

