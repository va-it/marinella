#include "HelperFunctions.h"
#include <string>
#include <sstream>
#include <algorithm>


HelperFunctions::HelperFunctions()
{
}


HelperFunctions::~HelperFunctions()
{
}

void HelperFunctions::ignoreCin()
{
	//https://stackoverflow.com/questions/3731529/program-is-skipping-over-getline-without-taking-user-input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

string HelperFunctions::getStringInput()
{
	string input;
	getline(cin, input);
	return input;
}

bool HelperFunctions::checkIfStringIsInteger(string input)
{
	bool valid = true;

	if (input.length() == 0)
	{
		valid = false;
	}
	else
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (isdigit(input[i]) == false)
			{
				valid = false;
				break;
			}
		}
	}

	return valid;
}

int HelperFunctions::convertStringToInteger(string input)
{
	//https://www.systutorials.com/convert-string-to-int-and-reverse/
	int integer = stoi(input);
	return integer;
}

bool HelperFunctions::checkIfStringIsFloat(string input)
{
	bool valid = true;

	if (input.length() == 0)
	{
		valid = false;
	}
	else
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (isdigit(input[i]) == false && input[i] != '.')
			{
				valid = false;
				break;
			}
		}
	}

	return valid;
}

float HelperFunctions::convertStringToFloat(string input)
{
	float number = stof(input);
	return number;
}

void HelperFunctions::clearScreen()
{
	//http://www.cplusplus.com/articles/4z18T05o/#OSAgnosticWays
	cout << string(100, '\n');
}

void HelperFunctions::printMenu()
{
	cout << "@@@@@@@@@@@@@@ MARINELLA (R) - Marina Berth Booking System @@@@@@@@@@@@@" << endl;
	cout << "\nPlease select an option from the menu below..." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|  1. New booking  |  2. Delete record  |  3. Show marina  |  4. Exit  |" << endl;
	cout << "------------------------------------------------------------------------\n>";
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
					cout << "3. Sailingboat\n>";
					break;
				}
				case 2:
				{
					cout << "Enter the name of the boat to delete:\n>";
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
					cout << "2. No\n>";
					break;
				}
			}
		}
		break;
	}
}

void HelperFunctions::printInvalidInputMessage()
{
	cout << "-------------------------------------------------" << endl;
	cout << "|  !!!!! Invalid input. Please try again. !!!!! |" << endl;
	cout << "-------------------------------------------------\n";

	pauseExecution();
}

void HelperFunctions::pauseExecution()
{
	do 
	{
		cout << "\n### Press Enter to continue ###\n";
	} 
	while (cin.get() != '\n');
}