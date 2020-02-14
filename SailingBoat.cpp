#include "SailingBoat.h"



SailingBoat::SailingBoat()
{
	float boatLenght, boatDepth;
	boatLenght = Boat::readLenght();
	boatDepth = Boat::readDepth();

	SailingBoat(boatLenght, boatDepth);
}

SailingBoat::SailingBoat(float lenght, float depth) :Boat(lenght, depth)
{
	cout << "Sailing Boat created";
}


SailingBoat::~SailingBoat()
{
}
