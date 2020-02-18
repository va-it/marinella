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
	//https ://asciiart.website/index.php?art=transportation/nautical
	cout << "\n *************** Narrow boat **************" << endl;
	cout << "        ________________________" << endl;
	cout << " ______/  /___/  /___/  /___/  \\________" << endl;
	cout << " \\ = : : : : : : : : : : : : : : : : : /" << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	Boat::displayInfo();
}