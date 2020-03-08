#include "SailingBoat.h"

SailingBoat::SailingBoat() : Boat(true)
{
}

SailingBoat::~SailingBoat()
{
}

void SailingBoat::displayInfo()
{
	//Based on drawings from https://asciiart.website/index.php?art=transportation/nautical
	cout << "\n********** Sailing boat **********" << endl;
	cout << "        _     _" << endl;
	cout << "       /|\\   /|\\" << endl;
	cout << "      /_|_\\ /_|_\\" << endl;
	cout << "    ___ | ___ | ___" << endl;
	cout << "    \\ o o o o o o /" << endl;
	cout << "   ~~~~~~~~~~~~~~~~~" << endl;

	Boat::displayInfo();
}
