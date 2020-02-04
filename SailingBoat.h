#pragma once
#include "Boat.h"

#include <iostream>
using namespace std;

class SailingBoat :
	public Boat
{
public:
	SailingBoat();

	SailingBoat(float lenght, float depth) : Boat(lenght, depth)
	{
		cout << "Sailing Boat created";
	};

	~SailingBoat();
};

