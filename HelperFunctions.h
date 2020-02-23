#pragma once
#include <iostream>
using namespace std;

class HelperFunctions
{
private:
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
};

