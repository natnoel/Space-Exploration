//Filename:		PointTwoD.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "LocationData.h"

class PointTwoD
{
	//Outputs the civilisation index and its x-ordinates and y-ordinates
	friend ostream& operator<< (ostream&, const PointTwoD);

	public:
		//Constructor functions
		
		//Initialises all string variables to empty string, all int and floar to 0
		PointTwoD ();
		
		//Initialises all attribute variables to the parameter's values respectively
		PointTwoD (int, int, string, int, int, float, float, float = 0);
		
		//Accessor functions
		int getX () const;						//Returns the value of its x-ordinate
		int getY () const;	  	  	  	  	  	//Returns the value of its y-ordinate
		LocationData getLocationData () const;	//Returns locationData
		float getCivIndex () const;	  	  	  	//Returns its civilisation index
		
		//Mutator functions
		void setX (int);	//Sets x to a value
		void setY (int);	//Sets y to a value
		void setLocationData (string, int, int, float, float);	//Sets locationData
		void setCivIndex (float);	//Sets its civilisation index to a value
		
		//Compares civilisation index between 2 PointTwoD objects
		bool operator> (const PointTwoD&) const;
		
		//Computes and sets civIndex
		void computeCivIndex ();
		
		//Computes and returns the distance from HQ to the location and back to the HQ again
		float computeDist () const;
		
		//Returns a string containing the name of each attribute and its value respectively
		string toString () const;
		
	private:
		int x, y;
		LocationData locationData;
		float civIndex;
};

