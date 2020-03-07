#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include "Marina.h"
#include "Boat.h"
using namespace std;

class HelperFunctions
{
private:

	/*static string statusFilePath = "status.bin";
	static ofstream statusFile;*/

	HelperFunctions();
	~HelperFunctions();
public:

	static void ignoreCin();

	static string getStringInput();

	static bool checkIfStringIsInteger(string input);

	static int convertStringToInteger(string input);

	static bool checkIfStringIsFloat(string input);

	static float convertStringToFloat(string input);

	static void clearScreen();

	static void printMenu();

	static void printSubMenu(int choice, int level);

	static void printInvalidInputMessage();

	static void pauseExecution();

	// Input/output with files

	static void loadMarinaStatus(Marina* &marina);

	static void saveMarinaStatus(Marina* marina);
};

