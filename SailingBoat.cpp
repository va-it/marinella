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
	//https ://asciiart.website/index.php?art=transportation/nautical
	cout << "\n ***** Sailing boat *****" << endl;
	cout << "        _" << endl;
	cout << "       /|\\" << endl;
	cout << "      /_|_\\" << endl;
	cout << "    ___ | ___" << endl;
	cout << "    \\_o_o_o_/" << endl;
	cout << "   ~~~~~~~~~~~~" << endl;

	Boat::displayInfo();
}
