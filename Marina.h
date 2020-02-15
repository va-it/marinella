#pragma once
#include <list>
#include "Boat.h"

class Marina
{
private:
	float length;
	static Marina *instance;

	Marina();

public:
	list<Boat*> mooredBoats;

	static Marina* getInstance();

	float getRemainingSpace();

	float getOccupiedSpace();

	void displayMooredBoats();

	~Marina();
};

