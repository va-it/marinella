#include "SailingBoat.h"



SailingBoat::SailingBoat()
{
	cout << "Sailing boat created" << endl;
}

SailingBoat::~SailingBoat()
{
}

void SailingBoat::displayInfo()
{
	cout << "this is a sailing boat";
	Boat::displayInfo();
}
