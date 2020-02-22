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

	static void clearScreen();

	static void printMenu();

	static void printSubMenu(int choice, int level);

	static void printInvalidInputMessage();
};

