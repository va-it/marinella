#include "HelperFunctions.h"
#include <string>
#include <sstream>


HelperFunctions::HelperFunctions()
{
}


HelperFunctions::~HelperFunctions()
{
}

void HelperFunctions::printMenu()
{
	cout << "@@@@@@@@@@@@@@ MARINELLA (R) - Marina Berth Booking System @@@@@@@@@@@@@" << endl;
	cout << "\nPlease select an option from the menu below..." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|  1. New booking  |  2. Delete record  |  3. Show marina  |  4. Exit  |" << endl;
	cout << "------------------------------------------------------------------------" << endl;
}

void HelperFunctions::printSubMenu(int choice)
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
			cout << "Do you know the ID of the record that you want to delete?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No, let me search by boat name" << endl;
			break;
		}
	}
}