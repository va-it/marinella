#pragma once
#include "Boat.h"
#include <iostream>

using namespace std;

// final specifies that the class cannot be inherited from
class MotorBoat final :
	public Boat
{
public:
	MotorBoat();

	~MotorBoat();

	// override specifies that the function overrides the virtual function from the parent class
	void display_info() override;
};

