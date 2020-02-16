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

				nameOfBoatToDelete = HelperFunctions::getStringInput(nameOfBoatToDelete);

				list<Boat*>::iterator positionOfBoatToDelete;
				positionOfBoatToDelete = marina->searchMooredBoatByName(nameOfBoatToDelete);
				
				// searchMooredBoatByName returns iterator to last element if a boat is not found 
				if (positionOfBoatToDelete != marina->mooredBoats.end())
				{
					marina->removeBoatFromMarina(positionOfBoatToDelete);
				}
				else
				{
					cout << "Boat not found" << endl;
				}
			}
			break;

			// Show marina
			case 3:
			{
				cout << "\n\nSpace left: " << marina->getRemainingSpace() << endl;
				marina->displayMooredBoats();
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