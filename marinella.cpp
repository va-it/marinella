#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Boat.h"
#include "MotorBoat.h"
#include "NarrowBoat.h"
#include "SailingBoat.h"

#include "Marina.h"

using namespace std;

int main(void)
{
	int choice;

	// =================== MENU ======================

	cout << "@@@@@@@@@@@@@@ MARINELLA (R) - Marina Berth Booking System @@@@@@@@@@@@@" << endl;
	cout << "\nPlease select an option from the menu below..." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|  1. New booking  |  2. Delete record  |  3. Show marina  |  4. Exit  |" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	cin >> choice;

	// ===============================================

	if (choice == 1)
	{
		int boatChoice;

		cout << "Please select type of boat:" << endl;
		cout << "1. Motorboat" << endl;
		cout << "2. Narrowboat" << endl;
		cout << "3. Sailingboat" << endl;
		cin >> boatChoice;

		float boatLenght, boatDepth;
		cout << "Please enter the lenght of the boat: ";
		cin >> boatLenght;
		cout << "Please enter the depth of the boat: ";
		cin >> boatDepth;

		switch (boatChoice)
		{
			case 1: 
			{
				MotorBoat* motorBoat = new MotorBoat(boatLenght, boatDepth);
				cout << "\n\nDetails of the motorboat" << endl;
				cout << "Lenght: " << motorBoat->getLenght() << endl;
				cout << "Depth: " << motorBoat->getDepth() << endl;
				break;
			}
			case 2: 
			{
				NarrowBoat* narrowBoat = new NarrowBoat(boatLenght, boatDepth);
				cout << "\n\nDetails of the narrowboat" << endl;
				cout << "Lenght: " << narrowBoat->getLenght() << endl;
				cout << "Depth: " << narrowBoat->getDepth() << endl;
				break;
			}
			case 3:
			{
				SailingBoat* sailingBoat = new SailingBoat(boatLenght, boatDepth);
				cout << "\n\nDetails of the sailingboat" << endl;
				cout << "Lenght: " << sailingBoat->getLenght() << endl;
				cout << "Depth: " << sailingBoat->getDepth() << endl;
				break;
			}
		}
	}

	system("PAUSE");
	return 0;
}