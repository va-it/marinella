#include "MotorBoat.h"



MotorBoat::MotorBoat()
{
	float boatLenght, boatDepth;
	boatLenght = Boat::readLenght();
	boatDepth = Boat::readDepth();

	MotorBoat(boatLenght, boatDepth);
}

MotorBoat::MotorBoat(float lenght, float depth) : Boat(lenght, depth)
{
	cout << "Motor Boat created";
}


MotorBoat::~MotorBoat()
{
}
