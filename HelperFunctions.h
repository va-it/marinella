#pragma once
#include <iostream>
using namespace std;

class HelperFunctions
{
private:
	HelperFunctions();
	~HelperFunctions();
public:

	static string getStringInput(string input);

	static void clearScreen();

	static void printMenu();

	static void printSubMenu(int choice);
};

