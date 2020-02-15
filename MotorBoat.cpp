#include "MotorBoat.h"



MotorBoat::MotorBoat() : Boat()
{
	cout << "Motor boat created" << endl;
}

MotorBoat::~MotorBoat()
{
}

void MotorBoat::displayInfo()
{
	cout << "this is a motor boat";
	Boat::displayInfo();
}