#include "NarrowBoat.h"


NarrowBoat::NarrowBoat() : Boat(true)
{
}

NarrowBoat::~NarrowBoat()
{
}

void NarrowBoat::displayInfo()
{
	//Based on drawings from https ://asciiart.website/index.php?art=transportation/nautical
	cout << "\n********** Narrow boat **********" << endl;
	cout << "        _________________" << endl;
	cout << " ______/  /___/  /___/  \\________" << endl;
	cout << " \\ = : : : :  : : : : : : : : : /" << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	Boat::displayInfo();
}