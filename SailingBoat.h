#pragma once
#include "Boat.h"
#include <iostream>

using namespace std;

class SailingBoat :
	public Boat
{
public:
	SailingBoat();

	~SailingBoat();

	void display_info();
};

