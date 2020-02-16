#pragma once
#include <list>
#include "Boat.h"

class Marina
{
private:
	float length, maxBoatLength, maxBoatDepth;
	static Marina *instance;

	Marina();

public:
	list<Boat*> mooredBoats, holdingBay;

	static Marina* getInstance();

	float getRemainingSpace();

	float getOccupiedSpace();

	void displayMooredBoats();

	void displayHoldingBay();

	list<Boat*>::iterator searchMooredBoatByName(string boatName);

	void removeBoatFromMarina(list<Boat*>::iterator);

	~Marina();
};

