#include "NarrowBoat.h"


NarrowBoat::NarrowBoat()
{
	cout << "Narrow boat created" << endl;
}

NarrowBoat::~NarrowBoat()
{
}

void NarrowBoat::displayInfo()
{
	cout << "this is a narrow boat";
	Boat::displayInfo();
}