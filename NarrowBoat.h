#pragma once
#include "Boat.h"
#include <iostream>

using namespace std;

class NarrowBoat :
	public Boat
{
public:
	NarrowBoat();

	~NarrowBoat();

	void displayInfo();
};
