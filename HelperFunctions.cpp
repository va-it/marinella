#include "HelperFunctions.h"

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
	cout << "------------------------------------------------------------------------\n> ";
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
			cout << "\n%%%%%%%%%% NEW BOOKING %%%%%%%%%%" << endl;
			cout << "\nPlease select type of boat:" << endl;
			cout << "1. Motorboat" << endl;
			cout << "2. Narrowboat" << endl;
			cout << "3. Sailingboat\n> ";
			break;
		}
		case 2:
		{
			cout << "\n%%%%%%%%%% DELETE RECORD %%%%%%%%%%" << endl;
			cout << "\nEnter the name of the boat to delete:\n> ";
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
			cout << "\nDo you accept the offer?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No\n> ";
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

void HelperFunctions::printGoodbyeMessage()
{
	cout << "\nThank you for using MARINELLA (R) - Marina Berth Booking System" << endl;

	//Based on drawings from https://asciiart.website/index.php?art=transportation/nautical
	cout << "      ..." << endl;
	cout << "    ..    ...                 .      vv" << endl;
	cout << "  ...    .     ..            /|~~                vv" << endl;
	cout << " ..   .      ..  .      ,   / |~~" << endl;
	cout << "   ...     .   ..      /|  /  |          vv" << endl;
	cout << "      ..              / |~~   |     ,~~~~" << endl;
	cout << "                     /  |~~   |    /|~~~~" << endl;
	cout << "                    /   |     |   / |" << endl;
	cout << "                   /    |     |  /  |" << endl;
	cout << "                  /     |     | /   |" << endl;
	cout << "                 /      |     |/    |" << endl;
	cout << "     =====______/       |     |=====|  __" << endl;
	cout << "        \\   __ \\========|=====|    / \\|__)" << endl;
	cout << "         \\'V` _\\o_o_o_o_o_o_o_o_o_o_o_o__)" << endl;
	cout << "          \\ -------  --  ---- - -  --- /" << endl;
	cout << "           \\  ----------- -  --- ----  |}" << endl;
	cout << "     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@ GOODBYE @@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

void HelperFunctions::pauseExecution()
{
	do
	{
		cout << "\n### Press Enter to continue ###";
	} while (cin.get() != '\n');
}


// Pass by reference so that the marina object gets changed
void HelperFunctions::loadMarinaStatus(Marina* &marina)
{
	// read status from file
	ifstream loadedFile(marina->name_of_status_file, ios::binary | ios::in);

	if (loadedFile.is_open())
	{
		int numberOfBoats = 0;
		loadedFile.read((char*)&numberOfBoats, sizeof(int));

		// initialize a vector to hold new Boat objects inside for loop below
		vector<Boat*> loadedBoats(numberOfBoats);

		for (int j = 0; j < numberOfBoats; j++)
		{
			loadedBoats[j] = new Boat();
			loadedFile.read((char*)loadedBoats[j], sizeof(Boat));
			marina->moored_boats.push_back(loadedBoats[j]);
		}

		// free memory used to store Boat objects
		loadedBoats.clear();
	}
	else
	{
		cout << "Error loading status file" << endl;
	}

	loadedFile.close();
}

void HelperFunctions::saveMarinaStatus(Marina* marina)
{
	ofstream fileToSave;
	// save current state to file
	fileToSave.open(marina->name_of_status_file, ios::out | ios::binary);
	if (!fileToSave) {
		cout << "Error in creating status file" << endl;
	}

	// get the number of boats and write that to the beginning of the file
	// used to loop X many times when loading the file
	int numberOfBoats = marina->moored_boats.size();
	fileToSave.write((char*)&numberOfBoats, sizeof(int));

	list<Boat*>::const_iterator boatPosition;
	// loop over every boat in the marina and save to file
	for (boatPosition = marina->moored_boats.cbegin(); boatPosition != marina->moored_boats.cend(); boatPosition++)
	{
		fileToSave.write((char*)(*boatPosition), sizeof(Boat));
	}

	fileToSave.close();

	cout << "Data saved into status file" << endl;
}