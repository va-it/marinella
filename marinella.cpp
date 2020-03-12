#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <iomanip>

#include "HelperFunctions.h"
#include "Boat.h"
#include "MotorBoat.h"
#include "NarrowBoat.h"
#include "SailingBoat.h"
#include "Marina.h"

using namespace std;

int main(void)
{

	Marina* marina = Marina::get_instance();
	int menu_choice_integer = 0;

	//set decimal points http://www.cplusplus.com/reference/iomanip/setprecision/
	cout << fixed << setprecision(2);

	HelperFunctions::load_marina_status(marina);

	do
	{
		HelperFunctions::clear_screen();

		// =================== MENU ======================
		HelperFunctions::print_menu();
		// ===============================================

		const string menu_choice = HelperFunctions::get_string_input();

		if (HelperFunctions::check_if_string_is_integer(menu_choice))
		{
			HelperFunctions::clear_screen();

			menu_choice_integer = HelperFunctions::convert_string_to_integer(menu_choice);

			switch (menu_choice_integer)
			{
				// New booking
			case 1:
			{
				Boat* incoming_boat;
				bool invalid_input;

				do
				{
					invalid_input = false;

					// =================== MENU ======================
					HelperFunctions::print_sub_menu(menu_choice_integer, 1);
					// ===============================================

					const string boat_type = HelperFunctions::get_string_input();

					if (HelperFunctions::check_if_string_is_integer(boat_type))
					{
						const int boat_type_integer = HelperFunctions::convert_string_to_integer(boat_type);
						switch (boat_type_integer)
						{
						case 1:
						{
							MotorBoat* motor_boat = new MotorBoat();
							incoming_boat = motor_boat;
						}
						break;
						case 2:
						{
							NarrowBoat* narrow_boat = new NarrowBoat();
							incoming_boat = narrow_boat;
						}
						break;
						case 3:
						{
							SailingBoat* sailing_boat = new SailingBoat();
							incoming_boat = sailing_boat;
						}
						break;
						default:
						{
							// No type matched. Ask again.
							HelperFunctions::print_invalid_input_message();
							invalid_input = true;
							continue;
						}
						}

						// check that there is enough space 
						if (marina->is_boat_allowed(incoming_boat))
						{
							// If yes, then get duration of stay
							incoming_boat->ask_and_set_booking_duration();

							// calculate price and ask confirmation
							marina->calculate_and_display_booking_cost(incoming_boat);

							bool invalid_confirmation;

							do
							{
								invalid_confirmation = false;

								HelperFunctions::print_sub_menu(menu_choice_integer, 2);
								const string confirmation = HelperFunctions::get_string_input();

								if (HelperFunctions::check_if_string_is_integer(confirmation))
								{
									const int confirmation_integer = HelperFunctions::convert_string_to_integer(confirmation);

									switch (confirmation_integer)
									{
									case 1:
									{
										// if confirmed get boat and owner name
										incoming_boat->ask_and_set_boat_name();
										incoming_boat->ask_and_set_owner_name();
										// boat can be moored
										marina->moored_boats.push_back(incoming_boat);
									}
									break;
									case 2:
									{
										//user has declined the offer
										Marina::print_declined_offer_message();
										HelperFunctions::pause_execution();
										continue;
									}
									break;
									default:
									{
										HelperFunctions::print_invalid_input_message();
										invalid_confirmation = true;
										continue;
									}
									}
								}
								else
								{
									HelperFunctions::print_invalid_input_message();
									invalid_confirmation = true;
									continue;
								}

							} while (invalid_confirmation);
						}
						else
						{
							marina->print_boat_is_not_allowed(incoming_boat);
							HelperFunctions::pause_execution();
						}
					}
					else
					{
						HelperFunctions::print_invalid_input_message();
						invalid_input = true;
						continue;
					}

				} while (invalid_input);
			}
			break;

			// Delete record
			case 2:
			{
				HelperFunctions::print_sub_menu(menu_choice_integer, 1);

				const string name_of_boat_to_delete = HelperFunctions::get_string_input();

				list<Boat*>::iterator position_of_boat_to_delete;
				position_of_boat_to_delete = marina->search_moored_boat_by_name(name_of_boat_to_delete);

				// search_moored_boat_by_name() returns iterator to end() if a boat is not found 
				if (position_of_boat_to_delete != marina->moored_boats.end())
				{
					marina->remove_boat_from_marina(position_of_boat_to_delete);
				}
				else
				{
					Marina::print_boat_not_found(name_of_boat_to_delete);
				}

				HelperFunctions::pause_execution();
			}
			break;

			// Show marina
			case 3:
			{
				// Nicely display the space left and the moored boats
				marina->display_marina_information();
				HelperFunctions::pause_execution();
			}
			break;

			//Exit
			case 4:
			{
				// Save Marina status to file
				HelperFunctions::save_marina_status(marina);

				HelperFunctions::print_goodbye_message();
			}
			break;
			default:
			{
				// No menu entry is matched
				HelperFunctions::print_invalid_input_message();
				continue;
			}
			}
		}
		else
		{
			HelperFunctions::print_invalid_input_message();
			continue;
		}
	} while (menu_choice_integer != 4);

	HelperFunctions::pause_execution();
	return 0;
}