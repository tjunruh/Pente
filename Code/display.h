#pragma once
#include <string>
#include <ascii_board.h>
#include <label.h>
#include <frame.h>
#include <text_box.h>
#include <spacer.h>
#include "logic.h"

class display
{
public:
	display(frame* main_display, frame* multipurpose_display);
	void display_board(const int(&board_data)[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int cursor_row, int cursor_column);
	void set_board_directions_content(const std::string& content);
	std::string get_player_data(const std::string& prompt);

private:
	label multipurpose_label;
	spacer left_multipurpose_spacer;
	text_box multipurpose_text_box;
	spacer right_multipurpose_spacer;
	frame* multipurpose_frame;

	ascii_board board;
	spacer left_main_spacer;
	label directions_label;
	spacer right_main_spacer;
	frame* main_frame;
};
