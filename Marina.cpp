#include "Marina.h"

Marina::Marina()
{
	length = 150;
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
	for (auto b : mooredBoats)
	{
		totalLength += b->getLength();
	}

	return totalLength;
}

void Marina::displayMooredBoats()
{
	for (auto b : mooredBoats)
	{
		b->displayInfo();
	}
}

Marina::~Marina()
{
}

//https://gist.github.com/pazdera/1098119
Marina *Marina::instance = 0;
