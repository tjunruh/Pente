#pragma once
#include <string>
#include <ascii_board.h>
#include <menu.h>
#include <label.h>
#include <frame.h>
#include <text_box.h>
#include "logic.h"
#include <controls.h>

class display
{
public:
	display(frame* main_display, frame* multipurpose_display, frame* settings_display, controls* game_controls);
	void display_board(const int(&board_data)[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int cursor_row, int cursor_column);
	void set_board_directions_content(const std::string& content);
	std::string get_player_data(const std::string& prompt);
	void display_set_controls();

private:
	std::vector<format_tools::index_format> build_central_element_color_structure(int color, bool bold);
	std::vector<format_tools::index_format> build_complete_element_color_structure(int color, bool bold);
	void reset_color(std::string control_name, int color_code);
	
	label multipurpose_label;
	text_box multipurpose_text_box;
	frame* multipurpose_frame;

	ascii_board board;
	label directions_label;
	frame* main_frame;

	label settings_label;
	menu settings_menu;
	frame* settings_frame;

	controls* _game_controls;

	enum setting_type
	{
		regular,
		boolean,
		color
	};

	struct control_settings_menu_item
	{
		std::string name_id = "";
		setting_type type = regular;
	};

	enum color_type
	{
		central,
		complete
	};

	const std::vector<control_settings_menu_item> control_settings_menu_items =
	{
		{"up", regular},
		{"down", regular},
		{"right", regular},
		{"left", regular},
		{"select", regular},
		{"quit", regular},
		{"delete", regular},
		{"help", regular},
		{"enable line drawing", boolean},
		{"enable color", boolean},
		{"background color", color},
		{"foreground color", color},
		{"player 1 color", color},
		{"player 2 color", color},
		{"player 3 color", color},
		{"player 4 color", color},
		{"cursor over empty space color", color},
		{"cursor over occupied space color", color},
		{"bold foreground", boolean}
	};

	struct config_name_color_pair
	{
		std::string name_id = "";
		std::string value = "";
		color_type type = central;
	};

	struct config_color_group
	{
		std::string color = "";
		std::vector<config_name_color_pair> groups;
	};

	const std::vector<config_color_group> color_group_map
	{
		{"player 1 color", {{"1", "(X)", complete}}},
		{"player 2 color", {{"2", "(O)", complete}}},
		{"player 3 color", {{"3", "(H)", complete}}},
		{"player 4 color", {{"4", "(K)", complete}}},
		{"cursor over empty space color", {{"cursor empty", "*<*", central}}},
		{"cursor over occupied space color", {{"cursor occupied", "*?*", central}}}
	};
};
