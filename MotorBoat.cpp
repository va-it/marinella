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
	//Based on drawings from https://asciiart.website/index.php?art=transportation/nautical
	cout << "\n********** Motor boat **********" << endl;
	cout << "                 __ /__" << endl;
	cout << "          _____ /______|" << endl;
	cout << " _______ / _____\\_______\\_____" << endl;
	cout << " \\              < < <         |" << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	Boat::displayInfo();
}