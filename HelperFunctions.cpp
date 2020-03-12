#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "Boat.h"
#include "HelperFunctions.h"

HelperFunctions::HelperFunctions()
{
}


HelperFunctions::~HelperFunctions()
{
}

void HelperFunctions::ignore_cin()
{
	// Prevent issue whereby user input is ignored
	// https://stackoverflow.com/questions/3731529/program-is-skipping-over-getline-without-taking-user-input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

string HelperFunctions::get_string_input()
{
	string input;
	getline(cin, input);
	return input;
}

bool HelperFunctions::check_if_string_is_integer(string input)
{
	bool valid = true;

	if (input.length() == 0)
	{
		valid = false;
	}
	else
	{
		// length() returns an unsigned integer
		for (unsigned int i = 0; i < input.length(); i++)
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

int HelperFunctions::convert_string_to_integer(const string input)
{
	// convert input string to integer
	// https://www.systutorials.com/convert-string-to-int-and-reverse/
	const int integer = stoi(input);
	return integer;
}

bool HelperFunctions::check_if_string_is_float(string input)
{
	bool valid = true;

	if (input.length() == 0)
	{
		valid = false;
	}
	else
	{
		for (unsigned int i = 0; i < input.length(); i++)
		{
			if (isdigit(input[i]) == false && input[i] != '.')
			{
				// the character is neither a number nor a dot for the decimal point
				valid = false;
				break;
			}
		}
	}

	return valid;
}

float HelperFunctions::convert_string_to_float(const string input)
{
	const float number = stof(input);
	return number;
}

void HelperFunctions::clear_screen()
{
	// Enter 100 new lines to simulate the cleaning of the screen
	// http://www.cplusplus.com/articles/4z18T05o/#OSAgnosticWays
	cout << string(100, '\n');
}

void HelperFunctions::print_menu()
{
	cout << "@@@@@@@@@@@@@@ MARINELLA (R) - Marina Berth Booking System @@@@@@@@@@@@@" << endl;
	cout << "\nPlease select an option from the menu below..." << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "|  1. New booking  |  2. Delete record  |  3. Show marina  |  4. Exit  |" << endl;
	cout << "------------------------------------------------------------------------\n> ";
}

void HelperFunctions::print_sub_menu(const int choice, const int level)
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
		default: break;
		}
	}
	break;
	case 2: // sub sub menu
	{
		if (choice == 1)
		{
			cout << "\nDo you accept the offer?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No\n> ";
		}
	}
	break;
	default: break;
	}
}

void HelperFunctions::print_invalid_input_message()
{
	cout << "-------------------------------------------------" << endl;
	cout << "|  !!!!! Invalid input. Please try again. !!!!! |" << endl;
	cout << "-------------------------------------------------\n";

	pause_execution();
}

void HelperFunctions::print_goodbye_message()
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

void HelperFunctions::pause_execution()
{
	do
	{
		cout << "\n### Press Enter to continue ###";
	} while (cin.get() != '\n');
}


// Pass by reference so that the marina object gets changed
void HelperFunctions::load_marina_status(Marina* &marina)
{
	// read status from file
	ifstream loaded_file(marina->name_of_status_file, ios::binary | ios::in);

	if (loaded_file.is_open())
	{
		int number_of_boats = 0;

		// avoid using (char*) (C style) to cast the type of  number_of_boats variable
		// as suggested by Resharper and comments in question available here:
		// https://stackoverflow.com/questions/9244563/writing-integer-to-binary-file-using-c
		loaded_file.read(reinterpret_cast<char*>(&number_of_boats), sizeof(int));

		// initialize a vector to hold new Boat objects inside for loop below
		vector<Boat*> loaded_boats(number_of_boats);

		for (int j = 0; j < number_of_boats; j++)
		{
			loaded_boats[j] = new Boat();
			loaded_file.read(reinterpret_cast<char*>(loaded_boats[j]), sizeof(Boat));
			marina->moored_boats.push_back(loaded_boats[j]);
		}

		// free memory used to store Boat objects
		loaded_boats.clear();
	}
	else
	{
		cout << "Error loading status file" << endl;
	}

	loaded_file.close();
}

void HelperFunctions::save_marina_status(Marina* marina)
{
	ofstream file_to_save;
	// save current state to file
	file_to_save.open(marina->name_of_status_file, ios::out | ios::binary);
	if (!file_to_save) {
		cout << "Error in creating status file" << endl;
	}

	// get the number of boats and write that to the beginning of the file
	// used to loop X many times when loading the file
	int number_of_boats = marina->moored_boats.size();
	file_to_save.write(reinterpret_cast<char*>(&number_of_boats), sizeof(int));

	// loop over every boat in the marina and save to file
	// using cbegin() means that the iterator (const_iterator) cannot be used to modify the object that it points to
	// http://www.cplusplus.com/reference/list/list/cbegin/
	for (list<Boat*>::const_iterator boat_position = marina->moored_boats.cbegin(); boat_position != marina->moored_boats.cend(); ++boat_position)
	{
		file_to_save.write(reinterpret_cast<char*>(*boat_position), sizeof(Boat));
	}

	file_to_save.close();

	cout << "Data saved into status file" << endl;
}