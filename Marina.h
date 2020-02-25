#pragma once
#include <list>
#include "Boat.h"

class Marina
{
private:
	float marinaLength, maxBoatLength, maxBoatDepth, costPerMeterPerMonth;
	static Marina *instance;

	Marina();

public:
	list<Boat*> mooredBoats, holdingBay;

	static Marina* getInstance();

	float getRemainingSpace();

	void printRemainingSpace();

	float getOccupiedSpace();

	bool isBoatAllowed(Boat* boat);

	void displayMooredBoats();

	void displayMooredBoatsGraphical(bool showHeading = false);

	void displayHoldingBay();

	void displayHoldingBayGraphical(bool showHeading = false);

	void displayMarinaInformation();

	list<Boat*>::iterator searchMooredBoatByName(string boatName);

	void removeBoatFromMarina(list<Boat*>::iterator positionOfBoatToDelete);

	void calculateAndDisplayBookingCost(Boat* boat);

	void printBoatNotFound(string boatName);

	void printBoatIsNotAllowed(Boat* boat);

	void printDeclinedOfferMessage();

	void printMaxBoatSizes();

	~Marina();
};

