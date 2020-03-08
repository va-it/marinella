#pragma once
#include "Boat.h"
#include <iostream>

using namespace std;

class MotorBoat :
	public Boat
{
public:
	MotorBoat();

	~MotorBoat();

	void displayInfo();
};

