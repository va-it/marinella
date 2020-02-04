#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Boat.h"
#include "MotorBoat.h"
#include "NarrowBoat.h"
#include "SailingBoat.h"

using namespace std;

int main(void)
{
	MotorBoat* motorBoat = new MotorBoat(5,1.5);
	NarrowBoat* narrowBoat = new NarrowBoat(6, 1.6);
	SailingBoat* sailingBoat = new SailingBoat(7, 1.7);

	cout << "\n\nThe first boat is a motorboat" << endl;
	cout << "Lenght: " << motorBoat->getLenght() << endl;
	cout << "Depth: " << motorBoat->getDepth() << endl;

	cout << "\n\nThe second boat is a narrowboat" << endl;
	cout << "Lenght: " << narrowBoat->getLenght() << endl;
	cout << "Depth: " << narrowBoat->getDepth() << endl;

	cout << "\n\nThe third boat is a sailingboat" << endl;
	cout << "Lenght: " << sailingBoat->getLenght() << endl;
	cout << "Depth: " << sailingBoat->getDepth() << endl;

	system("PAUSE");
	return 0;
}