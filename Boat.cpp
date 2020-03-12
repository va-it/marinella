#include "Boat.h"
#include "HelperFunctions.h"

Boat::Boat()
{
	// assign default values to class properties
	boat_name_ = owner_name_ = "";
	length_ = depth_ = 0;
	booking_duration_ = 0;
}

Boat::Boat(const bool ask_details)
{
	if (ask_details)
	{
		bool invalid_length, invalid_depth;
		Marina* marina = Marina::get_instance();

		do
		{
			invalid_length = false;
			cout << "\nPlease enter the length of the boat (max " << marina->get_max_boat_length() << "):\n> ";
			const string boat_length = HelperFunctions::get_string_input();

			if (HelperFunctions::check_if_string_is_float(boat_length))
			{
				length_ = HelperFunctions::convert_string_to_float(boat_length);
			}
			else
			{
				HelperFunctions::print_invalid_input_message();
				invalid_length = true;
			}
		} while (invalid_length);

		do
		{
			invalid_depth = false;
			cout << "\nPlease enter the depth of the boat (max " << marina->get_max_boat_depth() << "):\n> ";
			const string boat_depth = HelperFunctions::get_string_input();

			if (HelperFunctions::check_if_string_is_float(boat_depth))
			{
				depth_ = HelperFunctions::convert_string_to_float(boat_depth);
			}
			else
			{
				HelperFunctions::print_invalid_input_message();
				invalid_depth = true;
			}
		} while (invalid_depth);
		
		// assign default value to not initialized property
		booking_duration_ = 0;
	}
	else
	{
		// don't ask user for details (e.g. call default constructor)
		Boat();
	}
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
	set_boat_name(HelperFunctions::get_string_input());
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
		const string booking_duration_input = HelperFunctions::get_string_input();

		if (HelperFunctions::check_if_string_is_integer(booking_duration_input))
		{
			booking_duration_ = HelperFunctions::convert_string_to_integer(booking_duration_input);
		}
		else
		{
			HelperFunctions::print_invalid_input_message();
			invalid_duration = true;
		}
	}
	while (invalid_duration);
}

void Boat::ask_and_set_owner_name()
{
	cout << "\nPlease enter the name of the boat's owner:\n> ";
	set_owner_name(HelperFunctions::get_string_input());
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
