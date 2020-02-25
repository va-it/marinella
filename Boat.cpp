#include "Boat.h"
#include "HelperFunctions.h"
#include <string>
#include <iomanip>

Boat::Boat()
{
	bool invalidLength, invalidDepth;

	do 
	{
		invalidLength = false;
		cout << "Please enter the lenght of the boat:\n>";
		string boatLength = HelperFunctions::getStringInput();

		if (HelperFunctions::checkIfStringIsFloat(boatLength))
		{
			length = HelperFunctions::convertStringToFloat(boatLength);
		}
		else
		{
			HelperFunctions::printInvalidInputMessage();
			invalidLength = true;
		}

	} while (invalidLength);

	do
	{
		invalidDepth = false;
		cout << "Please enter the depth of the boat:\n>";
		string boatDepth = HelperFunctions::getStringInput();

		if (HelperFunctions::checkIfStringIsFloat(boatDepth))
		{
			depth = HelperFunctions::convertStringToFloat(boatDepth);
		}
		else
		{
			HelperFunctions::printInvalidInputMessage();
			invalidDepth = true;
		}

	} while (invalidDepth);
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
	bool invalidDuration;
	do
	{
		invalidDuration = false;
		cout << "Please enter the duration (in months) of the booking:\n>";
		string bookingDurationInput = HelperFunctions::getStringInput();
		
		if (HelperFunctions::checkIfStringIsInteger(bookingDurationInput))
		{
			bookingDuration = HelperFunctions::convertStringToInteger(bookingDurationInput);
		}
		else
		{
			HelperFunctions::printInvalidInputMessage();
			invalidDuration = true;
		}

	} while (invalidDuration);
}

void Boat::askAndSetOwnerName()
{
	cout << "Please enter the name of the boat's owner:\n>";
	setOwnerName(HelperFunctions::getStringInput());
}

void Boat::displayMeasures()
{
	cout << "Boat lenght: " << length << "m | " << "Boat depth: " << depth << "m" << endl;
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

void Boat::displayBookingDuration()
{
	cout << "Booking duration: " << bookingDuration << endl;
}

void Boat::displayInfo() 
{
	Boat::displayMeasures();
	Boat::displayBoatAndOwnerNames();
	Boat::displayBookingDuration();
	cout << "\n";
}
