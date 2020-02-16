#include "Marina.h"

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
	// return an invalid position to signify no boat found
	return mooredBoats.end();
}

Marina::~Marina()
{
}

//https://gist.github.com/pazdera/1098119
Marina *Marina::instance = 0;
