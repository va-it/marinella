#pragma once
#include <iostream>
using namespace std;

class HelperFunctions
{
private:
	HelperFunctions();
	~HelperFunctions();
public:

	static void clearScreen();

	static void printMenu();

	static void printSubMenu(int choice);
};

