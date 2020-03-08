#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Boat
{
private:
	string boatName, ownerName;
	float length, depth;
	int bookingDuration;

public:
	Boat();

	Boat(bool askDetails);

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

	void displayBookingDuration();

	virtual void displayInfo();
};

