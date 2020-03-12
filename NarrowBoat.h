#pragma once
#include "Boat.h"
#include <iostream>

using namespace std;

// final specifies that the class cannot be inherited from
class NarrowBoat final :
	public Boat
{
public:
	NarrowBoat();

	~NarrowBoat();

	// override specifies that the function overrides the virtual function from the parent class
	void display_info() override;
};
