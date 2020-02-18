#include "Boat.h"
#include "HelperFunctions.h"
#include <string>

Boat::Boat()
{
	cout << "Please enter the lenght of the boat:\n>";
	cin >> length;
	cout << "Please enter the depth of the boat:\n>";
	cin >> depth;
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

string Boat::getBoatName()
{
	return boatName;
}

void Boat::setBoatName(string boatNameInput)
{
	boatName = boatNameInput;
}

void Boat::askAndSetBoatName()
{
	cout << "Please enter the name of the boat:\n>";
	setBoatName(HelperFunctions::getStringInput());
}

string Boat::getOwnerName()
{
	return ownerName;
}

void Boat::setOwnerName(string ownerNameInput)
{
	ownerName = ownerNameInput;
}

int Boat::getBookingDuration()
{
	return bookingDuration;
}

void Boat::setBookingDuration(int bookingDurationInput)
{
	bookingDuration = bookingDurationInput;
}

void Boat::askAndSetBookingDuration()
{
	cout << "Please enter the duration of the booking:\n>";
	cin >> bookingDuration;
}

void Boat::askAndSetOwnerName()
{
	cout << "Please enter the name of the boat's owner:\n>";
	setOwnerName(HelperFunctions::getStringInput());
}

void Boat::displayMeasures()
{
	cout << "Boat lenght: " << length << " | " << "Boat depth: " <<  depth << endl;
}

void Boat::displayBoatName()
{
	cout << "Boat Name: " << boatName << endl;
}

void Boat::displayOwnerName()
{
	cout << "Owner Name: " << ownerName << endl;
}

void Boat::displayBoatAndOwnerNames()
{
	cout << "Boat Name: " << boatName << " | " << "Owner Name: " << ownerName << endl;
}

void Boat::displayInfo() 
{
	Boat::displayMeasures();
	Boat::displayBoatAndOwnerNames();
	cout << "\n";
}

// ++++++++++++++++++ STATIC METHODS +++++++++++++++++
float Boat::askAndSetLength()
{
	float boatLength;
	cout << "Please enter the lenght of the boat:\n>";
	cin >> boatLength;
	return boatLength;
}

float Boat::ansAndSetDepth()
{
	float boatDepth;
	cout << "Please enter the depth of the boat:\n>";
	cin >> boatDepth;
	return boatDepth;
}
