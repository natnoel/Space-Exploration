//Filename:		PointTwoD.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "PointTwoD.h"

//Outputs the civilisation index and its x-ordinates and y-ordinates
ostream& operator<< (ostream& os, const PointTwoD p)
{
	os<<"Civ Index : "<<p.civIndex<<", at sector ("<<p.x<<", "<<p.y<<")";
	
	return os;
}

//Constructor functions
//Initialises all string variables to empty string, all int and float variables to 0
PointTwoD::PointTwoD ()
{
	x = 0;
	y = 0;
	civIndex = 0;
}

//Initialises all attribute variables to the parameter's value respectively
PointTwoD::PointTwoD (int x, int y, string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons, 
			float aveParticulateDensity, float avePlasmaDensity, float civIndex)
			:locationData (sunType, noOfEarthLikePlanets, noOfEarthLikeMoons, 
			aveParticulateDensity, avePlasmaDensity)
{//Iniitalises locationData to the parameter values respectively
	this -> x = x;
	this -> y = y;
	this -> civIndex = civIndex;
}
		
//Accessor functions
int PointTwoD::getX () const
{
	return x;
}

int PointTwoD::getY () const
{
	return y;
}
		
LocationData PointTwoD::getLocationData () const
{
	return locationData;
}

float PointTwoD::getCivIndex () const
{
	return civIndex;
}

//Mutator functions
void PointTwoD::setX (int x)
{
	this -> x = x;
}

void PointTwoD::setY (int y)
{
	this -> y = y;
}

//Sets all the attributes variables of locationData to the parameter values respectively
void PointTwoD::setLocationData (string sunType, int noOfEarthLikePlanets, 
				int noOfEarthLikeMoons, float aveParticulateDensity, float avePlasmaDensity)
{
	locationData.setSunType (sunType);
	locationData.setNoOfEarthLikePlanets (noOfEarthLikePlanets);
	locationData.setNoOfEarthLikeMoons (noOfEarthLikeMoons);
	locationData.setAveParticulateDensity (aveParticulateDensity);
	locationData.setAvePlasmaDensity (avePlasmaDensity);
}

void PointTwoD::setCivIndex (float civIndex)
{
	this -> civIndex = civIndex;
}

//Returns true if this -> civIndex is greater than p.civIndex
//Returns false otherwise
bool PointTwoD::operator> (const PointTwoD& p) const
{
	return (civIndex > p.civIndex);
}

//Computes and sets the civIndex using the static function of class LocationData
void PointTwoD::computeCivIndex ()
{
	civIndex = LocationData::computeCivIndex (locationData.getSunType (), 
		locationData.getNoOfEarthLikePlanets (), locationData.getNoOfEarthLikeMoons (), 
		locationData.getAveParticulateDensity (), locationData.getAvePlasmaDensity ());
}

//Computes and returns the distance from HQ to the location and back to the HQ again
float PointTwoD::computeDist () const
{
	return 2 * sqrt (x * x + static_cast<float>(y * y));
}

//Returns a string containing the name of each attribute and its value respectively
string PointTwoD::toString () const
{
	string info, data;
	stringstream ss;
	
	ss<<x<<' '<<y<<' '<<civIndex;
	
	ss>>data;			//data contains value of x in a string format
	info = "x : " + data + '\n';
	
	ss>>data;			//data contains value of y in a string format
	info += "y : " + data + '\n' + "-----<locationData>-----" + '\n' + 
			locationData.toString () + "------------------------" + '\n';
			
	ss>>data;			//data contains value of civIndex in a string format
	info += "civIndex : " + data + '\n';
	
	return info;
}

