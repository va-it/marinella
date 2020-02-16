#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
#include <string>

#include "HelperFunctions.h"

#include "Boat.h"
#include "MotorBoat.h"
#include "NarrowBoat.h"
#include "SailingBoat.h"

#include "Marina.h"

using namespace std;

int main(void)
{

	Marina* marina = Marina::getInstance();

	int choice;

	do
	{
		// =================== MENU ======================
		HelperFunctions::printMenu();
		// ===============================================
		
		cin >> choice;

		switch (choice)
		{
			// New booking
			case 1:
			{
				int boatChoice;

				// =================== MENU ======================
				HelperFunctions::printSubMenu(choice);
				// ===============================================

				cin >> boatChoice;

				switch (boatChoice)
				{
				case 1:
				{
					MotorBoat* motorBoat = new MotorBoat();
					marina->mooredBoats.push_back(motorBoat);
				}
				break;
				case 2:
				{
					NarrowBoat* narrowBoat = new NarrowBoat();
					marina->mooredBoats.push_back(narrowBoat);
				}
				break;
				case 3:
				{
					SailingBoat* sailingBoat = new SailingBoat();
					marina->mooredBoats.push_back(sailingBoat);
				}
				break;
				}
			}
			break;

			// Delete record
			case 2:
			{
				string nameOfBoatToDelete;

				HelperFunctions::printSubMenu(choice);

				//https://stackoverflow.com/questions/3731529/program-is-skipping-over-getline-without-taking-user-input
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nameOfBoatToDelete);

	
				list<Boat*>::iterator boatPosition;
				boatPosition = marina->searchMooredBoatByName(nameOfBoatToDelete);

				// To move boats between lists use splice
				// http://www.cplusplus.com/reference/list/list/splice/
				// This moves all the boats behind the one to delete into the holding bay.
				advance(boatPosition, 1);
				marina->holdingBay.splice(marina->holdingBay.begin(),marina->mooredBoats,boatPosition,marina->mooredBoats.end());

				cout << "Moving boats into the holding bay..." << endl;

				cout << "Moored boats:" << endl;
				marina->displayMooredBoats();
				cout << "\nHolding bay: " << endl;
				marina->displayHoldingBay();

				cout << "=============" << endl;
				cout << "\nBoat" << nameOfBoatToDelete << "leaving the marina..." << endl;
				marina->mooredBoats.pop_back();
 
				marina->mooredBoats.splice(marina->mooredBoats.end(), marina->holdingBay);
				cout << "\n\nMoored boats:" << endl;
				marina->displayMooredBoats();
				cout << "\nHolding bay: " << endl;
				marina->displayHoldingBay();

			}
			break;

			// Show marina
			case 3:
			{
				marina->displayMooredBoats();

				cout << "\n\nSpace left: " << marina->getRemainingSpace() << endl;
			}
			break;

			//Exit
			case 4:
			{
				// Goodbye message
			}
			break;
			default:
			{
				// Try again
				cout << "Invalid input. Please try again" << endl;
				cin.clear();
			}
		}

		system("PAUSE");
		HelperFunctions::clearScreen();
	}
	while (choice != 4);

	system("PAUSE");
	return 0;
}