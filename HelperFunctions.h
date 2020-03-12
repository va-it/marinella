#pragma once
#include <string>
#include "Marina.h"

using namespace std;

class HelperFunctions
{
private:

	HelperFunctions();
	~HelperFunctions();
public:

	static void ignore_cin();

	static string get_string_input();

	static bool check_if_string_is_integer(string input);

	static int convert_string_to_integer(string input);

	static bool check_if_string_is_float(string input);

	static float convert_string_to_float(string input);

	static void clear_screen();

	static void print_menu();

	static void print_sub_menu(int choice, int level);

	static void print_invalid_input_message();

	static void print_goodbye_message();

	static void pause_execution();

	// Input/output with files

	static void load_marina_status(Marina* &marina);

	static void save_marina_status(Marina* marina);
};

