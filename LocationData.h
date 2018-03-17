//Filename:		LocationData.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class LocationData
{
	public:
		//Constructor functions
		LocationData ();	//Sets string variables to empty string, all int and float to 0
		//Intialises all attribute variables
		LocationData (string, int, int,	float, float);
		
		//Accessor functions
		string getSunType () const;				//Returns sunType
		int getNoOfEarthLikePlanets () const;	//Returns noOfEarthLikePlanets
		int getNoOfEarthLikeMoons () const;		//Returns noOfEarthLikeMoons
		float getAveParticulateDensity () const;//Returns aveParticulateDensity
		float getAvePlasmaDensity () const;		//Returns avePlasmaDensity
		
		//Mutator functions
		void setSunType (string);				//Sets sunType to a value
		void setNoOfEarthLikePlanets (int);		//Sets noOfEarthLikePlanets to a value
		void setNoOfEarthLikeMoons (int);		//Sets noOfEarthLikeMoons to a value
		void setAveParticulateDensity (float);	//Sets aveParticulateDensity to value
		void setAvePlasmaDensity (float);	  	//Sets avePlasmaDensity to a value
		
		//Returns a string containing the name of each attribute and its value respectively  
		string toString () const;
		
		//Computes and returns the location's civilisation index
		static float computeCivIndex (string, int, int, float, float);

	private:
		string sunType;
		int noOfEarthLikePlanets, noOfEarthLikeMoons;
		float aveParticulateDensity, avePlasmaDensity;
};

