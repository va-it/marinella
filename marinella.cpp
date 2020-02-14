#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>

#include "HelperFunctions.h"

#include "Boat.h"
#include "MotorBoat.h"
#include "NarrowBoat.h"
#include "SailingBoat.h"

#include "Marina.h"

using namespace std;

int main(void)
{

	
	int choice;
	list<Boat*> mooredBoats;

	do
	{
		// =================== MENU ======================
		HelperFunctions::printMenu();
		// ===============================================
		
		// Needs validation
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
						//motorBoat->getMeasures();
						mooredBoats.push_back(motorBoat);
					}
					break;
					case 2:
					{
						NarrowBoat* narrowBoat = new NarrowBoat();
						//narrowBoat->getMeasures();
						mooredBoats.push_back(narrowBoat);
					}
					break;
					case 3:
					{
						SailingBoat* sailingBoat = new SailingBoat();
						//sailingBoat->getMeasures();
						mooredBoats.push_back(sailingBoat);
					}
					break;
				}
			}
			break;

			// Delete record
			case 2: 
			{
				int deleteChoice;
				HelperFunctions::printSubMenu(choice);
				cin >> deleteChoice;

				// switch (deleteChoice)
			}
			break;

			// Show marina
			case 3:
			{
				// print Marina information
			}
			break;

			//Exit
			case 4:
			{
				// Goodbye message
			}
			break;
		}

		//https://stackoverflow.com/questions/16229729/printing-out-contents-of-a-list-from-the-c-list-library
		for (auto b : mooredBoats)
		{
			cout << b->getDepth() << "\n";
		}

	

	}
	while (choice != 4);

	system("PAUSE");
	return 0;
}