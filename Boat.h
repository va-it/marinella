#pragma once
#include <iostream>
using namespace std;

class Boat
{
private:
	
	float lenght, depth;

public:
	Boat();
	
	Boat(float childLenght, float childDepth);

	~Boat();

	float getLenght();
	
	float getDepth();

	void getMeasures();

	void getDetails();

	// ++++++++++++++++++ STATIC METHODS +++++++++++++++++
	static float readLenght();

	static float readDepth();
};

