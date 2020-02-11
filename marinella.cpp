#include <iostream>
#include <cstdlib>
#include <cstring>

#include "HelperFunctions.h"

#include "Boat.h"
#include "MotorBoat.h"
#include "NarrowBoat.h"
#include "SailingBoat.h"

#include "Marina.h"

using namespace std;

int main(void)
{
	// =================== MENU ======================
	int choice;
	HelperFunctions::printMenu();
	cin >> choice;
	// ===============================================

	switch (choice)
	{
		// New booking
		case 1:
		{
			int boatChoice;
			HelperFunctions::printSubMenu(choice);
			cin >> boatChoice;

			switch (boatChoice)
			{
				case 1:
				{
					MotorBoat* motorBoat = new MotorBoat();
					motorBoat->getMeasures();
				}
				break;
				case 2:
				{
					NarrowBoat* narrowBoat = new NarrowBoat();
					narrowBoat->getMeasures();
				}
				break;
				case 3:
				{
					SailingBoat* sailingBoat = new SailingBoat();
					sailingBoat->getMeasures();
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

	system("PAUSE");
	return 0;
}