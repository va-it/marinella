#include "Marina.h"
#include <string>

Marina::Marina()
{
	length = 150;
	maxBoatLength = 15;
	maxBoatDepth = 5;
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
	return length - Marina::getOccupiedSpace();
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

void Marina::displayMooredBoats()
{
	for (auto boat : mooredBoats)
	{
		boat->displayInfo();
	}
}

void Marina::displayHoldingBay()
{
	for (auto boat : holdingBay)
	{
		boat->displayInfo();
	}
}

//http://www.cplusplus.com/reference/list/list/splice/
list<Boat*>::iterator Marina::searchMooredBoatByName(string boatName)
{
	list<Boat*>::iterator iterator = mooredBoats.begin();
	for (auto boat : mooredBoats)
	{
		if (boat->getName() == boatName)
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
	// To move boats between lists use splice
	// http://www.cplusplus.com/reference/list/list/splice/
	// This moves all the boats behind the one to delete (hence advance of 1)
	// into the holding bay.
	advance(positionOfBoatToDelete, 1);
	holdingBay.splice(holdingBay.begin(), mooredBoats, positionOfBoatToDelete, mooredBoats.end());

	cout << "Moving boats into the holding bay..." << endl;

	cout << "Moored boats:" << endl;
	displayMooredBoats();
	cout << "\nHolding bay: " << endl;
	displayHoldingBay();

	cout << "=============" << endl;
	cout << "\nBoat " << (*positionOfBoatToDelete)->getName() << " leaving the marina..." << endl;
	mooredBoats.pop_back();

	mooredBoats.splice(mooredBoats.end(), holdingBay);
	cout << "\n\nMoored boats:" << endl;
	displayMooredBoats();
	cout << "\nHolding bay: " << endl;
	displayHoldingBay();
}

Marina::~Marina()
{
}

//https://gist.github.com/pazdera/1098119
Marina *Marina::instance = 0;
