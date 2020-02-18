#pragma once
#include <list>
#include "Boat.h"

class Marina
{
private:
	float length, maxBoatLength, maxBoatDepth, costPerMeterPerMonth;
	static Marina *instance;

	Marina();

public:
	list<Boat*> mooredBoats, holdingBay;

	static Marina* getInstance();

	float getRemainingSpace();

	float getOccupiedSpace();

	bool isBoatAllowed(Boat* boat);

	void displayMooredBoats();

	void displayHoldingBay();

	void displayMarinaInformation();

	list<Boat*>::iterator searchMooredBoatByName(string boatName);

	void removeBoatFromMarina(list<Boat*>::iterator);

	void calculateAndDisplayBookingCost(Boat* boat);

	~Marina();
};

