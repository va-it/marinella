#pragma once
#include "Boat.h"

#include <iostream>
using namespace std;

class NarrowBoat :
	public Boat
{
public:
	NarrowBoat();

	NarrowBoat(float lenght, float depth) : Boat(lenght, depth)
	{
		cout << "Narrow Boat created";
	};

	~NarrowBoat();
};
