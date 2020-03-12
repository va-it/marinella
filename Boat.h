#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Boat
{
private:
	string boat_name_, owner_name_;
	float length_, depth_;
	int booking_duration_;

public:
	Boat();

	Boat(bool ask_details);

	/* The destructor is virtual because otherwise deleting a derived object
	 * will only call the parent destructor causing memory leak
	 https://www.studytonight.com/cpp/virtual-destructors.php
	 */
	virtual ~Boat();

	float get_length() const;

	float get_depth() const;

	string get_boat_name() const;

	void set_boat_name(string boat_name_input);

	string get_owner_name() const;

	void set_owner_name(string owner_name_input);

	int get_booking_duration() const;

	void set_booking_duration(int booking_duration_input);

	void ask_and_set_booking_duration();

	void ask_and_set_boat_name();

	void ask_and_set_owner_name();

	void display_measures() const;

	void display_boat_name() const;

	void display_owner_name() const;

	void display_boat_and_owner_names() const;

	void display_booking_duration() const;

	virtual void display_info();
};
