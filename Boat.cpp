#include "Boat.h"
#include "HelperFunctions.h"

Boat::Boat()
{
}

Boat::Boat(bool ask_details)
{
	bool invalid_length, invalid_depth;
	Marina* marina = Marina::get_instance();

	do
	{
		invalid_length = false;
		cout << "\nPlease enter the length of the boat (max " << marina->get_max_boat_length() << "):\n> ";
		const string boat_length = HelperFunctions::getStringInput();

		if (HelperFunctions::checkIfStringIsFloat(boat_length))
		{
			length_ = HelperFunctions::convertStringToFloat(boat_length);
		}
		else
		{
			HelperFunctions::printInvalidInputMessage();
			invalid_length = true;
		}
	}
	while (invalid_length);

	do
	{
		invalid_depth = false;
		cout << "\nPlease enter the depth of the boat (max " << marina->get_max_boat_depth() << "):\n> ";
		const string boat_depth = HelperFunctions::getStringInput();

		if (HelperFunctions::checkIfStringIsFloat(boat_depth))
		{
			depth_ = HelperFunctions::convertStringToFloat(boat_depth);
		}
		else
		{
			HelperFunctions::printInvalidInputMessage();
			invalid_depth = true;
		}
	}
	while (invalid_depth);
}

Boat::~Boat()
{
}

float Boat::get_length() const
{
	return length_;
}

float Boat::get_depth() const
{
	return depth_;
}

string Boat::get_boat_name() const
{
	return boat_name_;
}

void Boat::set_boat_name(const string boat_name_input)
{
	boat_name_ = boat_name_input;
}

void Boat::ask_and_set_boat_name()
{
	cout << "\nPlease enter the name of the boat:\n> ";
	set_boat_name(HelperFunctions::getStringInput());
}

string Boat::get_owner_name() const
{
	return owner_name_;
}

void Boat::set_owner_name(const string owner_name_input)
{
	owner_name_ = owner_name_input;
}

int Boat::get_booking_duration() const
{
	return booking_duration_;
}

void Boat::set_booking_duration(const int booking_duration_input)
{
	booking_duration_ = booking_duration_input;
}

void Boat::ask_and_set_booking_duration()
{
	bool invalid_duration;
	do
	{
		invalid_duration = false;
		cout << "\nPlease enter the duration (in whole months) of the booking:\n> ";
		const string booking_duration_input = HelperFunctions::getStringInput();

		if (HelperFunctions::checkIfStringIsInteger(booking_duration_input))
		{
			booking_duration_ = HelperFunctions::convertStringToInteger(booking_duration_input);
		}
		else
		{
			HelperFunctions::printInvalidInputMessage();
			invalid_duration = true;
		}
	}
	while (invalid_duration);
}

void Boat::ask_and_set_owner_name()
{
	cout << "\nPlease enter the name of the boat's owner:\n> ";
	set_owner_name(HelperFunctions::getStringInput());
}

void Boat::display_measures() const
{
	cout << "Boat length: " << length_ << "m | " << "Boat depth: " << depth_ << "m" << endl;
}

void Boat::display_boat_name() const
{
	cout << "Boat Name: " << boat_name_ << endl;
}

void Boat::display_owner_name() const
{
	cout << "Owner Name: " << owner_name_ << endl;
}

void Boat::display_boat_and_owner_names() const
{
	cout << "Boat Name: " << boat_name_ << " | " << "Owner Name: " << owner_name_ << endl;
}

void Boat::display_booking_duration() const
{
	cout << "Booking duration: " << booking_duration_ << " months" << endl;
}

void Boat::display_info()
{
	display_measures();
	display_boat_and_owner_names();
	display_booking_duration();
	cout << "\n";
}
