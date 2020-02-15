#pragma once
#include <iostream>
using namespace std;

class Boat
{
private:
	string name;
	float length, depth;

public:
	Boat();

	~Boat();

	float getLength();
	
	float getDepth();

	void getMeasures();

	virtual void displayInfo();

	// ++++++++++++++++++ STATIC METHODS +++++++++++++++++
	static float readLength();

	static float readDepth();
};

