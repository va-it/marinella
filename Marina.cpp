#include "Marina.h"
#include <string>
#include <iomanip>

Marina::Marina()
{
	marinaLength = 150;
	maxBoatLength = 15;
	maxBoatDepth = 5;
	costPerMeterPerMonth = 10;
	nameOfStatusFile = "status.bin";
}

Marina* Marina::getInstance()
{
	if (!instance)
	{
		instance = new Marina();
	}

	return instance;
}

float Marina::getRemainingSpace()
{
	return marinaLength - Marina::getOccupiedSpace();
}

void Marina::printRemainingSpace()
{
	cout << "\nSpace left: " << getRemainingSpace() << "m" << endl;
}

float Marina::getOccupiedSpace()
{
	std::list<Boat*>::iterator boat;

	float totalLength = 0;

	for (boat = mooredBoats.begin(); boat != mooredBoats.end(); boat++)
	{
		totalLength += (*boat)->getLength();
	}

	return totalLength;
}

bool Marina::isBoatAllowed(Boat* boat)
{
	// Boat is within limits
	if (boat->getDepth() <= maxBoatDepth && boat->getLength() <= maxBoatLength)
	{
		// There is enough space left
		if (boat->getLength() <= Marina::getRemainingSpace())
		{
			return true;
		}
	}

	return false;
}

void Marina::displayMooredBoats()
{
	list<Boat*>::iterator boatPosition;

	if (!mooredBoats.empty())
	{
		cout << "\n========== Moored boats (" << mooredBoats.size() << ") ==========" << endl;
		
		displayMooredBoatsGraphical();

		for (boatPosition = mooredBoats.begin(); boatPosition != mooredBoats.end(); boatPosition++)
		{
			(*boatPosition)->displayInfo();
		}
	}
	else
	{
		cout << "\n========== No boats moored ==========" << endl;
	}
}

void Marina::displayMooredBoatsGraphical(bool showHeading)
{
	list<Boat*>::const_iterator boatPosition;

	if (!mooredBoats.empty())
	{
		if (showHeading)
		{
			cout << "\n========== Moored boats (" << mooredBoats.size() << ") ==========" << endl;
		}

		cout << "--------------------------------------" << endl;

		for (boatPosition = mooredBoats.cbegin(); boatPosition != mooredBoats.cend(); boatPosition++)
		{
			cout << (*boatPosition)->getBoatName() << " | ";
		}

		cout << "\n--------------------------------------" << endl;
	}
}

void Marina::displayHoldingBay()
{
	std::list<Boat*>::iterator boatPosition;

	if (!holdingBay.empty())
	{
		cout << "\n========== Holding bay (" << holdingBay.size() << ") ==========" << endl;

		displayHoldingBayGraphical();

		for (boatPosition = holdingBay.begin(); boatPosition != holdingBay.end(); boatPosition++)
		{
			(*boatPosition)->displayInfo();
		}
	}
	else
	{
		cout << "\n========== Holding bay is empty ==========" << endl;
	}
}

void Marina::displayHoldingBayGraphical(bool showHeading)
{
	list<Boat*>::const_iterator boatPosition;

	if (!holdingBay.empty())
	{
		if (showHeading)
		{
			cout << "\n========== Holding bay (" << holdingBay.size() << ") ==========" << endl;
		}
		
		cout << "--------------------------------------" << endl;

		for (boatPosition = holdingBay.cbegin(); boatPosition != holdingBay.cend(); boatPosition++)
		{
			cout << (*boatPosition)->getBoatName() << " | ";
		}

		cout << "\n--------------------------------------" << endl;
	}
}

void Marina::displayMarinaInformation()
{
	cout << "\n%%%%%%%%%% MARINA INFORMATION %%%%%%%%%%" << endl;
	printRemainingSpace();
	displayMooredBoats();
}

//http://www.cplusplus.com/reference/list/list/splice/
list<Boat*>::iterator Marina::searchMooredBoatByName(string boatName)
{
	list<Boat*>::iterator boatPosition;

	for (boatPosition = mooredBoats.begin(); boatPosition != mooredBoats.end(); boatPosition++)
	{
		if ((*boatPosition)->getBoatName() == boatName)
		{
			return boatPosition;
		}
	}

	// return end position if no matching boat is found
	// same behaviour as find function
	// http://www.cplusplus.com/reference/algorithm/find/
	return mooredBoats.end();
}

void Marina::removeBoatFromMarina(list<Boat*>::iterator positionOfBoatToDelete)
{
	list<Boat*>::reverse_iterator reverse_iterator;
	list<Boat*>::iterator iterator, boatToDelete;
	bool boatToDeleteIsLast = false;

	string nameOfBoatToDelete = (*positionOfBoatToDelete)->getBoatName();

	if (mooredBoats.size() == 1)
	{
		cout << "\n##### Boat " << nameOfBoatToDelete << " leaving the marina #####" << endl;

		// Free up memory. clear wouldn't call the destructor since the object has been created dynamically
		delete mooredBoats.back();
		// simply empty the list
		mooredBoats.clear();
		// Show that the marina is empty
		displayMooredBoats();
	}
	else
	{
		// If the boat to delete is the last one then don't show the message about moving things into the holding bay 
		// https://stackoverflow.com/questions/3516196/testing-whether-an-iterator-points-to-the-last-item
		if ((positionOfBoatToDelete != mooredBoats.end()) && (next(positionOfBoatToDelete) == mooredBoats.end()))
		{
			boatToDeleteIsLast = true;
		}

		// Show the current status of the marina
		displayMooredBoatsGraphical(true);
		displayHoldingBayGraphical(true);

		if (!boatToDeleteIsLast)
		{
			cout << "\n>>>>> Moving boats into the holding bay... >>>>>" << endl;

			// To move boats between lists use splice
			// http://www.cplusplus.com/reference/list/list/splice/
			// Display all the boats that are being moved into the holding bay
			// https://thispointer.com/c-different-ways-to-iterate-over-a-list-of-objects/
			// convert reverse iterator to forward to compare with parameter
			// https://stackoverflow.com/questions/2037867/can-i-convert-a-reverse-iterator-to-a-forward-iterator
			// Using next to only move the boats behind the one to delete.
			for (reverse_iterator = mooredBoats.rbegin(); reverse_iterator.base() != next(positionOfBoatToDelete); reverse_iterator++)
			{
				cout << "\n" << (*reverse_iterator)->getBoatName() << " ===> Holding bay";
			}

			// Moving boats from marina to holding bay
			holdingBay.splice(holdingBay.begin(), mooredBoats, next(positionOfBoatToDelete), mooredBoats.end());

			// Show how the boats behind the one to delete are now in the holding bay
			cout << "\n";
			displayMooredBoatsGraphical(true);
			displayHoldingBayGraphical(true);
		}

		cout << "\n##### Boat " << nameOfBoatToDelete << " leaving the marina #####" << endl;

		// pop_back doesn't call the destructor since the object has been created dynamically
		// this (delete mooredBoats.back();) should work, but it causes error in certain situations.

		// Remove last boat from marina (the one we want to get out)
		mooredBoats.pop_back();

		if (!boatToDeleteIsLast)
		{
			cout << "\n<<<<< Moving boats back into the marina... <<<<<" << endl;

			// Display all the boats that are being moved into the holding bay
			for (iterator = holdingBay.begin(); iterator != holdingBay.end(); iterator++)
			{
				cout << "\nMarina <=== " << (*iterator)->getBoatName();
			}

			mooredBoats.splice(mooredBoats.end(), holdingBay);
		}

		// Show that all the boats are once again in the marina
		cout << "\n";
		displayMooredBoatsGraphical(true);
		displayHoldingBayGraphical(true);
	}	
}

void Marina::calculateAndDisplayBookingCost(Boat* boat)
{
	float lengthOfBoat = boat->getLength();
	int bookingDuration = boat->getBookingDuration();

	float costPerLength = (costPerMeterPerMonth * lengthOfBoat);
	float costPerLengthAndDuration = costPerLength * bookingDuration;
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "The calculated cost for this booking is: "<< costPerLengthAndDuration << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
}

void Marina::printBoatNotFound(string boatName)
{
	cout << "\nBoat \""<< boatName <<"\" not found" << endl;
}

void Marina::printBoatIsNotAllowed(Boat* boat)
{
	cout << "\n-------------------------------------------------" << endl;
	cout << "|  !!!!!     This boat is not allowed     !!!!! |" << endl;
	cout << "-------------------------------------------------\n";

	cout << "\n----------------------------------------------" << endl;
	boat->displayMeasures();
	printMaxBoatSizes();
	printRemainingSpace();
	cout << "----------------------------------------------" << endl;

}

void Marina::printDeclinedOfferMessage()
{
	cout << "\nSorry, we hope to see you again." << endl;
}

Marina::~Marina()
{
}

void Marina::printMaxBoatSizes()
{
	cout << "\nMax boat length allowed: " << maxBoatLength << "m" << endl;
	cout << "Max boat depth allowed: " << maxBoatDepth << "m" << endl;
}

//https://gist.github.com/pazdera/1098119
Marina *Marina::instance = 0;
