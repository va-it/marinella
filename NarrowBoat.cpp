#include "NarrowBoat.h"


NarrowBoat::NarrowBoat()
{
	float boatLenght, boatDepth;
	boatLenght = Boat::readLenght();
	boatDepth = Boat::readDepth();

	NarrowBoat(boatLenght, boatDepth);
}

NarrowBoat::NarrowBoat(float lenght, float depth) :Boat(lenght, depth)
{
	cout << "Motor Boat created";
}

NarrowBoat::~NarrowBoat()
{
}
