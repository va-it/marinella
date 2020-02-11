#include "Boat.h"



Boat::Boat()
{
}

Boat::Boat(float childLenght, float childDepth)
{
	lenght = childLenght;
	depth = childDepth;
}

Boat::~Boat()
{
}

float Boat::getLenght()
{
	return lenght;
}

float Boat::getDepth()
{
	return depth;
}

void Boat::getMeasures()
{
	cout << "\n\nDetails of the boat" << endl;
	cout << "Lenght: " << this->getLenght() << endl;
	cout << "Depth: " << this->getDepth() << endl;
}

void Boat::getDetails()
{
}

// ++++++++++++++++++ STATIC METHODS +++++++++++++++++
float Boat::readLenght()
{
	float boatLenght;
	cout << "Please enter the lenght of the boat: ";
	cin >> boatLenght;
	return boatLenght;
}

float Boat::readDepth()
{
	float boatDepth;
	cout << "Please enter the depth of the boat: ";
	cin >> boatDepth;
	return boatDepth;
}
