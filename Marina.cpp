#include "Marina.h"
#include <string>
#include <iomanip>

Marina::Marina()
{
	marina_length_ = 150;
	max_boat_length_ = 15;
	max_boat_depth_ = 5;
	cost_per_meter_per_month_ = 10;
	name_of_status_file = "status.bin";
}

Marina* Marina::get_instance()
{
	if (!instance_)
	{
		instance_ = new Marina();
	}

	return instance_;
}

float Marina::get_max_boat_length() const
{
	return max_boat_length_;
}

float Marina::get_max_boat_depth() const
{
	return max_boat_depth_;
}

float Marina::get_remaining_space()
{
	return marina_length_ - Marina::get_occupied_space();
}

void Marina::print_remaining_space()
{
	cout << "\nSpace left: " << get_remaining_space() << "m" << endl;
}

float Marina::get_occupied_space()
{
	float totalLength = 0;

	for (std::list<Boat*>::iterator boat = moored_boats.begin(); boat != moored_boats.end(); ++boat)
	{
		totalLength += (*boat)->get_length();
	}

	return totalLength;
}

bool Marina::is_boat_allowed(Boat* boat)
{
	// Boat is within limits
	if (boat->get_depth() <= max_boat_depth_ && boat->get_length() <= max_boat_length_)
	{
		// There is enough space left
		if (boat->get_length() <= Marina::get_remaining_space())
		{
			return true;
		}
	}

	return false;
}

void Marina::display_moored_boats()
{
	if (!moored_boats.empty())
	{
		cout << "\n========== Moored boats (" << moored_boats.size() << ") ==========" << endl;

		display_moored_boats_graphical();

		for (list<Boat*>::iterator boat_position = moored_boats.begin(); boat_position != moored_boats.end(); ++boat_position)
		{
			(*boat_position)->display_info();
		}
	}
	else
	{
		cout << "\n========== No boats moored ==========" << endl;
	}
}

void Marina::display_moored_boats_graphical(const bool show_heading) const
{
	if (!moored_boats.empty())
	{
		if (show_heading)
		{
			cout << "\n========== Moored boats (" << moored_boats.size() << ") ==========" << endl;
		}

		cout << "--------------------------------------" << endl;

		for (list<Boat*>::const_iterator boat_position = moored_boats.cbegin(); boat_position != moored_boats.cend(); ++boat_position)
		{
			cout << (*boat_position)->get_boat_name() << " | ";
		}

		cout << "\n--------------------------------------" << endl;
	}
}

void Marina::display_holding_bay()
{
	if (!holding_bay.empty())
	{
		cout << "\n========== Holding bay (" << holding_bay.size() << ") ==========" << endl;

		display_holding_bay_graphical();

		for (std::list<Boat*>::iterator boat_position = holding_bay.begin(); boat_position != holding_bay.end(); ++boat_position)
		{
			(*boat_position)->display_info();
		}
	}
	else
	{
		cout << "\n========== Holding bay is empty ==========" << endl;
	}
}

void Marina::display_holding_bay_graphical(bool show_heading) const
{
	if (!holding_bay.empty())
	{
		if (show_heading)
		{
			cout << "\n========== Holding bay (" << holding_bay.size() << ") ==========" << endl;
		}

		cout << "--------------------------------------" << endl;

		for (list<Boat*>::const_iterator boat_position = holding_bay.cbegin(); boat_position != holding_bay.cend(); ++boat_position)
		{
			cout << (*boat_position)->get_boat_name() << " | ";
		}

		cout << "\n--------------------------------------" << endl;
	}
}

void Marina::display_marina_information()
{
	cout << "\n%%%%%%%%%% MARINA INFORMATION %%%%%%%%%%" << endl;
	print_remaining_space();
	display_moored_boats();
}

//http://www.cplusplus.com/reference/list/list/splice/
list<Boat*>::iterator Marina::search_moored_boat_by_name(const string boat_name)
{
	for (list<Boat*>::iterator boat_position = moored_boats.begin(); boat_position != moored_boats.end(); ++boat_position)
	{
		if ((*boat_position)->get_boat_name() == boat_name)
		{
			return boat_position;
		}
	}

	// return end position if no matching boat is found
	// same behaviour as find function
	// http://www.cplusplus.com/reference/algorithm/find/
	return moored_boats.end();
}

void Marina::remove_boat_from_marina(const list<Boat*>::iterator position_of_boat_to_delete)
{
	list<Boat*>::iterator boat_to_delete;
	bool boat_to_delete_is_last = false;

	const string name_of_boat_to_delete = (*position_of_boat_to_delete)->get_boat_name();

	if (moored_boats.size() == 1)
	{
		cout << "\n##### Boat " << name_of_boat_to_delete << " leaving the marina #####" << endl;

		// Free up memory. clear wouldn't call the destructor since the object has been created dynamically
		delete moored_boats.back();
		// simply empty the list
		moored_boats.clear();
		// Show that the marina is empty
		display_moored_boats();
	}
	else
	{
		// If the boat to delete is the last one then don't show the message about moving things into the holding bay 
		// https://stackoverflow.com/questions/3516196/testing-whether-an-iterator-points-to-the-last-item
		if ((position_of_boat_to_delete != moored_boats.end()) && (next(position_of_boat_to_delete) == moored_boats.end()))
		{
			boat_to_delete_is_last = true;
		}

		// Show the current status of the marina
		display_moored_boats_graphical(true);
		display_holding_bay_graphical(true);

		if (!boat_to_delete_is_last)
		{
			cout << "\n>>>>> Moving boats into the holding bay... >>>>>" << endl;

			// To move boats between lists use splice
			// http://www.cplusplus.com/reference/list/list/splice/
			// Display all the boats that are being moved into the holding bay
			// https://thispointer.com/c-different-ways-to-iterate-over-a-list-of-objects/
			// Using next to only move the boats behind the one to delete.
			for (list<Boat*>::reverse_iterator reverse_iterator = moored_boats.rbegin(); reverse_iterator.base() != next(position_of_boat_to_delete); ++reverse_iterator)
			{
				cout << "\n" << (*reverse_iterator)->get_boat_name() << " ===> Holding bay";
			}

			// Moving boats from marina to holding bay
			holding_bay.splice(holding_bay.begin(), moored_boats, next(position_of_boat_to_delete), moored_boats.end());

			// Show how the boats behind the one to delete are now in the holding bay
			cout << "\n";
			display_moored_boats_graphical(true);
			display_holding_bay_graphical(true);
		}

		cout << "\n##### Boat " << name_of_boat_to_delete << " leaving the marina #####" << endl;

		// pop_back doesn't call the destructor since the object has been created dynamically
		// this (delete mooredBoats.back();) should work, but it causes error in certain situations.

		// Remove last boat from marina (the one we want to get out)
		moored_boats.pop_back();

		if (!boat_to_delete_is_last)
		{
			cout << "\n<<<<< Moving boats back into the marina... <<<<<" << endl;

			// Display all the boats that are being moved into the holding bay
			for (list<Boat*>::iterator iterator = holding_bay.begin(); iterator != holding_bay.end(); ++iterator)
			{
				cout << "\nMarina <=== " << (*iterator)->get_boat_name();
			}

			moored_boats.splice(moored_boats.end(), holding_bay);
		}

		// Show that all the boats are once again in the marina
		cout << "\n";
		display_moored_boats_graphical(true);
		display_holding_bay_graphical(true);
	}
}

void Marina::calculate_and_display_booking_cost(Boat* boat) const
{
	const float length_of_boat = boat->get_length();
	const int booking_duration = boat->get_booking_duration();

	const float cost_per_length = (cost_per_meter_per_month_ * length_of_boat);
	const float cost_per_length_and_duration = cost_per_length * booking_duration;
	
	cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "The calculated cost for this booking is: " << cost_per_length_and_duration << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
}

void Marina::print_boat_not_found(const string boat_name)
{
	cout << "\nBoat \"" << boat_name << "\" not found" << endl;
}

void Marina::print_boat_is_not_allowed(Boat* boat)
{
	cout << "\n-------------------------------------------------" << endl;
	cout << "|  !!!!!     This boat is not allowed     !!!!! |" << endl;
	cout << "-------------------------------------------------\n";

	cout << "\n----------------------------------------------" << endl;
	boat->display_measures();
	print_max_boat_sizes();
	print_remaining_space();
	cout << "----------------------------------------------" << endl;

}

void Marina::print_declined_offer_message()
{
	cout << "\nSorry, we hope to see you again." << endl;
}

Marina::~Marina()
{
}

void Marina::print_max_boat_sizes() const
{
	cout << "\nMax boat length allowed: " << max_boat_length_ << "m" << endl;
	cout << "Max boat depth allowed: " << max_boat_depth_ << "m" << endl;
}

//https://gist.github.com/pazdera/1098119
Marina *Marina::instance_ = 0;
