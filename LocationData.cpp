//Filename:		LocationData.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

#include "LocationData.h"

//Constructor functions
LocationData::LocationData ()//Initialises sunType to a null string and all int and float to 0
{
	sunType = "\0";
	noOfEarthLikePlanets = 0;
	noOfEarthLikeMoons = 0;
	aveParticulateDensity = 0;
	avePlasmaDensity = 0;
}

//Initialises all attribute variables to the parameter's values respectively
LocationData::LocationData (string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons, 
			float aveParticulateDensity, float avePlasmaDensity)
{
	this -> sunType = sunType;
	this -> noOfEarthLikePlanets = noOfEarthLikePlanets;
	this -> noOfEarthLikeMoons = noOfEarthLikeMoons;
	this -> aveParticulateDensity = aveParticulateDensity;
	this -> avePlasmaDensity = avePlasmaDensity;
}

		
//Accessor functions
string LocationData::getSunType () const	//Returns sunType
{
	return sunType;
}

int LocationData::getNoOfEarthLikePlanets () const	//Returns noOfEarthLikePlanets
{
	return noOfEarthLikePlanets;
}

int LocationData::getNoOfEarthLikeMoons () const	//Returns noOfEarthLikeMoons
{
	return noOfEarthLikeMoons;
}

float LocationData::getAveParticulateDensity () const	//Returns aveParticulateDensity
{
	return aveParticulateDensity;
}

float LocationData::getAvePlasmaDensity () const	//Returns avePlasmaDensity
{
	return avePlasmaDensity;
}

		
//Mutator functions
void LocationData::setSunType (string sunType)//Sets sunType
{
	this -> sunType = sunType;
}

//Sets noOfEarthLikePlanets
void LocationData::setNoOfEarthLikePlanets (int noOfEarthLikePlanets)
{
	this -> noOfEarthLikePlanets = noOfEarthLikePlanets;
}

//Sets noOfEarthLikeMoons
void LocationData::setNoOfEarthLikeMoons (int noOfEarthLikeMoons)
{
	this -> noOfEarthLikeMoons = noOfEarthLikeMoons;
}

//Sets aveParticulateDensity
void LocationData::setAveParticulateDensity (float aveParticulateDensity)
{
	this -> aveParticulateDensity = aveParticulateDensity;
}

//Sets avePlasmaDensity
void LocationData::setAvePlasmaDensity (float avePlasmaDensity)
{
	this -> avePlasmaDensity = avePlasmaDensity;
}

//Returns a string containing the name of each attribute and its value respectively  	 
string LocationData::toString () const
{
	string info, data;
	stringstream ss;
	
	ss<<sunType<<' '<<noOfEarthLikePlanets<<' '<<noOfEarthLikeMoons<<' '
		<<aveParticulateDensity<<' '<<avePlasmaDensity;
	
	ss>>data;	//data contains value of sunType in a string format
	info = "sunType: " + data + ' ';
	ss>>data;
	info += data + '\n';
	
	ss>>data;	//data contains value of noOfEarthLikePlanets in a string format
	info += "noOfEarthLikePlanets: " + data + '\n';
	
	ss>>data;	//data contains value of noOfEarthLikeMoons in a string format
	info += "noOfEarthLikeMoons: " + data + '\n';
	
	ss>>data;	//data contains value of aveParticulateDensity in a string format
	info += "aveParticulateDensity: " + data + '\n';
	
	ss>>data;	//data contains value of avePlasmaDensity in a string format
	info += "avePlasmaDensity: " + data + '\n';
	
	return info;
}

//Computes and returns the location's civilisation index
float LocationData::computeCivIndex (string sunType, int noOfEarthLikePlanets, 
			int noOfEarthLikeMoons, float aveParticulateDensity, float avePlasmaDensity)
{
	float sunTypePercent;
	
	switch (sunType [5])	//Sets sunTypePercent according to its sunType
	{
		case 'O':	sunTypePercent = 30;
						break;
		case 'B':	sunTypePercent = 45;
						break;
		case 'A':	sunTypePercent = 60;
						break;
		case 'F':	sunTypePercent = 75;
						break;
		case 'G':	sunTypePercent = 90;
						break;
		case 'K':	sunTypePercent = 80;
						break;
		case 'M':	sunTypePercent = 70;
						break;
	}
	
	//The equation for computing the location's civilisation index
	return ((sunTypePercent / 100) - (aveParticulateDensity + avePlasmaDensity) / 200)
			* (noOfEarthLikePlanets + noOfEarthLikeMoons);
}

