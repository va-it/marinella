#include "Boat.h"
#include <string>

Boat::Boat()
{
	cout << "Please enter the lenght of the boat:\n>";
	cin >> length;
	cout << "Please enter the depth of the boat:\n>";
	cin >> depth;
	cout << "Please enter the name of the boat:\n>";
	//https://stackoverflow.com/questions/3731529/program-is-skipping-over-getline-without-taking-user-input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, name);
}

Boat::~Boat()
{
}

float Boat::getLength()
{
	return length;
}

float Boat::getDepth()
{
	return depth;
}

string Boat::getName()
{
	return name;
}

void Boat::getMeasures()
{
	cout << "\nDetails of the boat:" << endl;
	cout << "Lenght: " << length << endl;
	cout << "Depth: " <<  depth << endl;
}

void Boat::displayInfo() 
{
	Boat::getMeasures();
	cout << "Name: " << name << endl;
}

// ++++++++++++++++++ STATIC METHODS +++++++++++++++++
float Boat::readLength()
{
	float boatLength;
	cout << "Please enter the lenght of the boat: ";
	cin >> boatLength;
	return boatLength;
}

float Boat::readDepth()
{
	float boatDepth;
	cout << "Please enter the depth of the boat: ";
	cin >> boatDepth;
	return boatDepth;
}
