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
	float totalLength = 0;

	//https://stackoverflow.com/questions/16229729/printing-out-contents-of-a-list-from-the-c-list-library
	// Bear in mind this is C++11 (https://www.fluentcpp.com/2018/10/26/how-to-access-the-index-of-the-current-element-in-a-modern-for-loop/)
	for (auto b : mooredBoats)
	{
		totalLength += b->getLength();
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
	if (!mooredBoats.empty())
	{
		cout << "\n========== Moored boats ";
		cout << "(" << mooredBoats.size() << ") ==========" << endl;
		for (auto boat : mooredBoats)
		{
			boat->displayInfo();
		}
	}
	else
	{
		cout << "========== No boats moored ==========" << endl;
	}
}

void Marina::displayHoldingBay()
{
	if (!holdingBay.empty())
	{
		cout << "\n========== Boats in the holding bay ";
		cout << "(" << holdingBay.size() << ") ==========" << endl;
		for (auto boat : holdingBay)
		{
			boat->displayInfo();
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
	string nameOfBoatToDelete = (*positionOfBoatToDelete)->getBoatName();
	// To move boats between lists use splice
	// http://www.cplusplus.com/reference/list/list/splice/
	// This moves all the boats behind the one to delete (hence advance of 1)
	// into the holding bay.
	advance(positionOfBoatToDelete, 1);
	holdingBay.splice(holdingBay.begin(), mooredBoats, positionOfBoatToDelete, mooredBoats.end());

	cout << ">>>>> Moving boats into the holding bay... >>>>>" << endl;

	displayMooredBoats();
	displayHoldingBay();

	// Highlight this section a bit more.
	cout << "\nBoat " << nameOfBoatToDelete << " leaving the marina..." << endl;
	mooredBoats.pop_back();

	cout << "\n<<<<< Moving boats back into the marina... <<<<<" << endl;
	mooredBoats.splice(mooredBoats.end(), holdingBay);

	displayMooredBoats();
	displayHoldingBay();

	// free up memory
	delete *positionOfBoatToDelete;
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
