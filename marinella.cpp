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

	Boat* incomingBoat = NULL;

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
				int boatType;
				
				// =================== MENU ======================
				HelperFunctions::printSubMenu(choice, 1);
				// ===============================================

				cin >> boatType;

				switch (boatType)
				{
					case 1:
					{
						MotorBoat* motorBoat = new MotorBoat();
						incomingBoat = motorBoat;
					}
					break;
					case 2:
					{
						NarrowBoat* narrowBoat = new NarrowBoat();
						incomingBoat = narrowBoat;
					}
					break;
					case 3:
					{
						SailingBoat* sailingBoat = new SailingBoat();
						incomingBoat = sailingBoat;
					}
					break;
					default:
					{
						// No type matched. Ask again.
					}
				}

				// check that there is enough space 
				if (marina->isBoatAllowed(incomingBoat))
				{
					// If yes, then get duration of stay
					incomingBoat->askAndSetBookingDuration();

					// calculate price and ask confirmation
					marina->calculateAndDisplayBookingCost(incomingBoat);

					// user can confirm or reject
					int confirmation;
					HelperFunctions::printSubMenu(choice, 2);
					cin >> confirmation;

					if (confirmation == 1)
					{
						// if confirmed get boat and owner name
						incomingBoat->askAndSetBoatName();
						incomingBoat->askAndSetOwnerName();
						// boat can be moored
						marina->mooredBoats.push_back(incomingBoat);
					}
					else
					{
						//user has declined offer
						cout << "Sorry, we hope to see you again." << endl;
					}
				}
				else
				{
					cout << "Boat is not allowed" << endl;
				}
			}
			break;

			// Delete record
			case 2:
			{
				string nameOfBoatToDelete;

				HelperFunctions::printSubMenu(choice, 1);

				nameOfBoatToDelete = HelperFunctions::getStringInput();

				list<Boat*>::iterator positionOfBoatToDelete;
				positionOfBoatToDelete = marina->searchMooredBoatByName(nameOfBoatToDelete);
				
				// searchMooredBoatByName returns iterator to last if a boat is not found 
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
				// BUG - AFTER ENTERING LETTER, SYSTEM DOES NOT LISTEN TO INPUT ANY MORE
			}
		}

		system("PAUSE");
		HelperFunctions::clearScreen();
	}
	while (choice != 4);

	system("PAUSE");
	return 0;
}