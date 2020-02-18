#pragma once
#include <iostream>
using namespace std;

class Boat
{
private:
	string boatName, ownerName;
	float length, depth;
	int bookingDuration;

public:
	Boat();

	~Boat();

	float getLength();
	
	float getDepth();

	string getBoatName();

	void setBoatName(string boatNameInput);

	string getOwnerName();

	void setOwnerName(string ownerNameInput);

	int getBookingDuration();

	void setBookingDuration(int bookingDurationInput);

	void askAndSetBookingDuration();

	void askAndSetBoatName();

	void askAndSetOwnerName();

	void displayMeasures();

	void displayBoatName();

	void displayOwnerName();

	void displayBoatAndOwnerNames();

	virtual void displayInfo();

	// ++++++++++++++++++ STATIC METHODS +++++++++++++++++
	static float askAndSetLength();

	static float ansAndSetDepth();
};

