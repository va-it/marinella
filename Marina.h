#pragma once
#include <list>
#include "Boat.h"

class Marina
{
private:
	float marina_length_, max_boat_length_, max_boat_depth_, cost_per_meter_per_month_;
	static Marina* instance_;

	Marina();

public:
	list<Boat*> moored_boats, holding_bay;

	string name_of_status_file;

	static Marina* get_instance();

	float get_max_boat_length() const;
	
	float get_max_boat_depth() const;

	float get_remaining_space();

	void print_remaining_space();

	float get_occupied_space();

	bool is_boat_allowed(Boat* boat);

	void display_moored_boats();

	void display_moored_boats_graphical(bool show_heading = false) const;

	void display_holding_bay();

	void display_holding_bay_graphical(bool show_heading = false) const;

	void display_marina_information();

	list<Boat*>::iterator search_moored_boat_by_name(string boat_name);

	void remove_boat_from_marina(list<Boat*>::iterator position_of_boat_to_delete);

	void calculate_and_display_booking_cost(Boat* boat) const;

	static void print_boat_not_found(string boat_name);

	void print_boat_is_not_allowed(Boat* boat);

	static void print_declined_offer_message();

	void print_max_boat_sizes() const;

	~Marina();
};

