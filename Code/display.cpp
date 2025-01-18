#include "display.h"
#include <ascii_io.h>

display::display(frame* main_display, frame* multipurpose_display) :
	multipurpose_label(multipurpose_display),
	left_multipurpose_spacer(multipurpose_display, 1, "new line"),
	multipurpose_text_box(multipurpose_display, "none", 3),
	right_multipurpose_spacer(multipurpose_display, 1),
	board(main_display, "board_configs/pente_board.txt", "default"),
	left_main_spacer(main_display, 1, "new line"),
	directions_label(main_display),
	right_main_spacer(main_display, 1)
{
	main_frame = main_display;
	multipurpose_frame = multipurpose_display;
	board.add_configuration("1", -1, -1, "(X)", '*');
	board.add_configuration("2", -1, -1, "(O)", '*');
	board.add_configuration("3", -1, -1, "(H)", '*');
	board.add_configuration("4", -1, -1, "(K)", '*');
	board.add_configuration("cursor empty space", -1, -1, "*<*", '*');
	board.add_configuration("cursor full space", -1, -1, "*?*", '*');
	board.set_spacing(5, 5, 0, 0);
	directions_label.set_spacing(1, 1, 0, 0);
	directions_label.add_border(true);
	main_frame->set_coordinate_width_multiplier(1, 1, 1);

	multipurpose_frame->set_coordinate_width_multiplier(1, 1, 1);
	multipurpose_label.set_alignment("center block");
	multipurpose_label.set_spacing(15, 0, 0, 0);
}

void display::display_board(const int(&board_data)[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int cursor_row, int cursor_column)
{
	board.clear_all();
	for (unsigned int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (unsigned int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (board_data[i][j] == 1)
			{
				board.activate_configuration("1", i, j);
			}
			else if (board_data[i][j] == 2)
			{
				board.activate_configuration("2", i, j);
			}
			else if (board_data[i][j] == 3)
			{
				board.activate_configuration("3", i, j);
			}
			else if (board_data[i][j] == 4)
			{
				board.activate_configuration("4", i, j);
			}
		}
	}

	if (board_data[cursor_row][cursor_column] == 0)
	{
		board.activate_configuration("cursor empty space", cursor_row, cursor_column);
	}
	else
	{
		board.activate_configuration("cursor full space", cursor_row, cursor_column);
	}

	board.sync();
	main_frame->display();
}

void display::set_board_directions_content(const std::string& content)
{
	directions_label.set_output(content);
}

std::string display::get_player_data(const std::string& prompt)
{
	int input = ascii_io::undefined;
	multipurpose_label.set_output(prompt);
	multipurpose_text_box.add_border(true);
	multipurpose_frame->display();
	do
	{
		input = multipurpose_text_box.write();
	} while (input != ascii_io::enter);
	std::string written_content = multipurpose_text_box.get_text();
	ascii_io::hide_cursor();
	multipurpose_text_box.clear();
	return written_content;
}