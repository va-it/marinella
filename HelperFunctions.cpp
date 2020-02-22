#include "HelperFunctions.h"
#include <string>
#include <sstream>


HelperFunctions::HelperFunctions()
{
}


HelperFunctions::~HelperFunctions()
{
}

void HelperFunctions::ignoreCin()
{
	cin.clear();
	//https://stackoverflow.com/questions/3731529/program-is-skipping-over-getline-without-taking-user-input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

string HelperFunctions::getStringInput()
{
	string input;
	ignoreCin();
	getline(cin, input);
	return input;
}

void HelperFunctions::clearScreen()
{
	if (system("CLS"))
	{
		system("clear");
	}
}

void HelperFunctions::printMenu()
{
	cout << "@@@@@@@@@@@@@@ MARINELLA (R) - Marina Berth Booking System @@@@@@@@@@@@@" << endl;
	cout << "\nPlease select an option from the menu below..." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|  1. New booking  |  2. Delete record  |  3. Show marina  |  4. Exit  |" << endl;
	cout << "------------------------------------------------------------------------" << endl;
}

void HelperFunctions::printSubMenu(int choice, int level)
{
	switch (level)
	{
		case 1:
		{
			switch (choice)
			{
				case 1:
				{
					cout << "Please select type of boat:" << endl;
					cout << "1. Motorboat" << endl;
					cout << "2. Narrowboat" << endl;
					cout << "3. Sailingboat" << endl;
					break;
				}
				case 2:
				{
					cout << "Enter the name of the boat to delete:" << endl;
					break;
				}
			}
		}
		break;
		case 2: // sub sub menu
		{
			switch (choice)
			{
				case 1:
				{
					cout << "Do you confirm?" << endl;
					cout << "1. Yes" << endl;
					cout << "2. No" << endl;
					break;
				}
			}
		}
		break;
	}
}

void HelperFunctions::printInvalidInputMessage()
{
	cout << "Invalid input. Please try again" << endl;
	ignoreCin();
}