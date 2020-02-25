#include "Marina.h"
#include <string>
#include <iomanip>

Marina::Marina()
{
	marinaLength = 150;
	maxBoatLength = 15;
	maxBoatDepth = 5;
	costPerMeterPerMonth = 10;
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
	if (boat->getDepth() <= maxBoatDepth && boat->getLength() <= Marina::getRemainingSpace())
	{
		return true;
	}

	return false;
}

void Marina::displayMooredBoats()
{
	std::list<Boat*>::iterator boat;

	if (!mooredBoats.empty())
	{
		cout << "\n========== Moored boats ";
		cout << "(" << mooredBoats.size() << ") ==========" << endl;
		// Display all the boats that are being moved into the holding bay
		for (boat = mooredBoats.begin(); boat != mooredBoats.end(); boat++)
		{
			(*boat)->displayInfo();
		}
	}
	else
	{
		cout << "========== No boats moored ==========" << endl;
	}
}

void Marina::displayHoldingBay()
{
	std::list<Boat*>::iterator boat;

	if (!holdingBay.empty())
	{
		cout << "\n========== Boats in the holding bay ";
		cout << "(" << holdingBay.size() << ") ==========" << endl;
		for (boat = holdingBay.begin(); boat != holdingBay.end(); boat++)
		{
			(*boat)->displayInfo();
		}
	}
	else
	{
		cout << "========== Holding bay is empty ==========" << endl;
	}
}

void Marina::displayMarinaInformation()
{
	cout << "\n%%%%%%%%%% MARINA INFORMATION %%%%%%%%%%" << endl;
	cout << "\n\nSpace left: " << getRemainingSpace() << "m" << endl;
	displayMooredBoats();
	displayHoldingBay();
}

//http://www.cplusplus.com/reference/list/list/splice/
list<Boat*>::iterator Marina::searchMooredBoatByName(string boatName)
{
	list<Boat*>::iterator iterator = mooredBoats.begin();
	for (auto boat : mooredBoats)
	{
		if (boat->getBoatName() == boatName)
		{
			return iterator;
		}
		advance(iterator, 1);
	}
	// return last position if no matching boat is found
	// same behaviour as find function
	// http://www.cplusplus.com/reference/algorithm/find/
	return mooredBoats.end();
}

void Marina::removeBoatFromMarina(list<Boat*>::iterator positionOfBoatToDelete)
{
	list<Boat*>::reverse_iterator reverse_iterator;
	list<Boat*>::iterator iterator;

	string nameOfBoatToDelete = (*positionOfBoatToDelete)->getBoatName();

	// free up memory
	delete *positionOfBoatToDelete;

	if (mooredBoats.size() == 1)
	{
		cout << "\n##### Boat " << nameOfBoatToDelete << " leaving the marina #####" << endl;

		// simply empty the list
		mooredBoats.clear();
	}
	else
	{
		cout << ">>>>> Moving boats into the holding bay... >>>>>" << endl;

		// To move boats between lists use splice
		// http://www.cplusplus.com/reference/list/list/splice/
		// This moves all the boats behind the one to delete (hence advance of 1)
		// into the holding bay.
		advance(positionOfBoatToDelete, 1);

		// Display all the boats that are being moved into the holding bay
		// https://thispointer.com/c-different-ways-to-iterate-over-a-list-of-objects/
		// convert reverse iterator to forward https://stackoverflow.com/questions/2037867/can-i-convert-a-reverse-iterator-to-a-forward-iterator
		for (reverse_iterator = mooredBoats.rbegin(); reverse_iterator.base() != positionOfBoatToDelete; reverse_iterator++)
		{
			cout << (*reverse_iterator)->getBoatName() << " ===> Holding bay" << endl;
		}

		//Moving boats from marina to holding bay
		holdingBay.splice(holdingBay.begin(), mooredBoats, positionOfBoatToDelete, mooredBoats.end());


		cout << "\n##### Boat " << nameOfBoatToDelete << " leaving the marina #####" << endl;

		// Remove last boat from marina (the one we want to get out)
		mooredBoats.pop_back();

		cout << "\n<<<<< Moving boats back into the marina... <<<<<" << endl;

		// Display all the boats that are being moved into the holding bay
		for (iterator = holdingBay.begin(); iterator != holdingBay.end(); iterator++)
		{
			cout << "Marina <=== "<< (*iterator)->getBoatName() << endl;
		}

		mooredBoats.splice(mooredBoats.end(), holdingBay);
	}	
}

void Marina::calculateAndDisplayBookingCost(Boat* boat)
{
	float lengthOfBoat = boat->getLength();
	float bookingDuration = boat->getBookingDuration();

	float costPerLength = (costPerMeterPerMonth * lengthOfBoat);
	float costPerLengthAndDuration = costPerLength * bookingDuration;
	cout << "The calculated cost for this booking is: "<< costPerLengthAndDuration << endl;
}

void Marina::printBoatNotFound(string boatName)
{
	cout << "Boat "<< boatName <<" not found" << endl;
}

void Marina::printBoatIsNotAllowed(Boat* boat)
{
	cout << "Sorry, but boats with these sizes are not allowed" << endl;
	boat->displayMeasures();
}

void Marina::printDeclinedOfferMessage()
{
	cout << "\nSorry, we hope to see you again." << endl;
}

Marina::~Marina()
{
}

//https://gist.github.com/pazdera/1098119
Marina *Marina::instance = 0;
