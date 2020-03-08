#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
#include <string>
#include <iomanip>

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
	string menuChoice;
	int menuChoiceInteger = 0;
	//set decimal points http://www.cplusplus.com/reference/iomanip/setprecision/
	cout << fixed << setprecision(2);

	HelperFunctions::loadMarinaStatus(marina);

	do
	{
		HelperFunctions::clearScreen();

		// =================== MENU ======================
		HelperFunctions::printMenu();
		// ===============================================

		menuChoice = HelperFunctions::getStringInput();

		if (HelperFunctions::checkIfStringIsInteger(menuChoice))
		{
			HelperFunctions::clearScreen();

			menuChoiceInteger = HelperFunctions::convertStringToInteger(menuChoice);

			switch (menuChoiceInteger)
			{
				// New booking
				case 1:
				{
					Boat* incomingBoat;
					bool invalidInput;

					do
					{
						invalidInput = false;

						// =================== MENU ======================
						HelperFunctions::printSubMenu(menuChoiceInteger, 1);
						// ===============================================
						string boatType = HelperFunctions::getStringInput();

						if (HelperFunctions::checkIfStringIsInteger(boatType))
						{
							int boatTypeInteger = HelperFunctions::convertStringToInteger(boatType);
							switch (boatTypeInteger)
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
									HelperFunctions::printInvalidInputMessage();
									invalidInput = true;
									continue;
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
								string confirmation;
								bool invalidConfirmation;
								int confirmationInteger;

								do
								{
									invalidConfirmation = false;

									HelperFunctions::printSubMenu(menuChoiceInteger, 2);
									confirmation = HelperFunctions::getStringInput();

									if (HelperFunctions::checkIfStringIsInteger(confirmation))
									{
										confirmationInteger = HelperFunctions::convertStringToInteger(confirmation);
										
										switch (confirmationInteger)
										{
											case 1:
											{
												// if confirmed get boat and owner name
												incomingBoat->askAndSetBoatName();
												incomingBoat->askAndSetOwnerName();
												// boat can be moored
												marina->mooredBoats.push_back(incomingBoat);
											}
											break;
											case 2:
											{
												//user has declined the offer
												marina->printDeclinedOfferMessage();
												HelperFunctions::pauseExecution();
												continue;
											}
											break;
											default:
											{
												HelperFunctions::printInvalidInputMessage();
												invalidConfirmation = true;
												continue;
											}
										}
									}
									else
									{
										HelperFunctions::printInvalidInputMessage();
										invalidConfirmation = true;
										continue;
									}

								} while (invalidConfirmation);
							}
							else
							{
								marina->printBoatIsNotAllowed(incomingBoat);
								HelperFunctions::pauseExecution();
							}
						}
						else
						{
							HelperFunctions::printInvalidInputMessage();
							invalidInput = true;
							continue;
						}

					} while (invalidInput);
				}
				break;

				// Delete record
				case 2:
				{
					string nameOfBoatToDelete;

					HelperFunctions::printSubMenu(menuChoiceInteger, 1);

					nameOfBoatToDelete = HelperFunctions::getStringInput();

					list<Boat*>::iterator positionOfBoatToDelete;
					positionOfBoatToDelete = marina->searchMooredBoatByName(nameOfBoatToDelete);

					// searchMooredBoatByName returns iterator to end if a boat is not found 
					if (positionOfBoatToDelete != marina->mooredBoats.end())
					{
						marina->removeBoatFromMarina(positionOfBoatToDelete);
					}
					else
					{
						marina->printBoatNotFound(nameOfBoatToDelete);
					}
					
					HelperFunctions::pauseExecution();
				}
				break;

				// Show marina
				case 3:
				{
					// Nicely display the space left and the moored boats
					marina->displayMarinaInformation();
					HelperFunctions::pauseExecution();
				}
				break;

				//Exit
				case 4:
				{
					// Save Marina status to file
					HelperFunctions::saveMarinaStatus(marina);

					HelperFunctions::printGoodbyeMessage();
				}
				break;
				default:
				{
					// Try again
					HelperFunctions::printInvalidInputMessage();
					continue;
				}
			}
		}
		else
		{
			HelperFunctions::printInvalidInputMessage();
			continue;
		}
	}
	while (menuChoiceInteger != 4);
	
	HelperFunctions::pauseExecution();
	return 0;
}