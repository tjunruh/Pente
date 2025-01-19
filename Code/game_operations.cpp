#include "game_operations.h"
#include <string>
#include <ascii_io.h>
#include "input_to_logic_interface.h"

game_operations::game_operations(frame* main_display, frame* multipurpose_display) : display_manager(main_display, multipurpose_display)
{

}

void game_operations::game_loop()
{
	std::string player_names[4] = {};
	int number_of_players = 0;
	int pairs_taken[4] = {};
	bool winner_five_in_a_row = false;
	bool winner = false;
	bool number_of_players_complete = false;
	int player_turn = 1;
	int board_data[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = { 0 };

	do
	{
		std::string number_of_players_string = display_manager.get_player_data("How many players are playing?");
		if ((number_of_players_string.length() == 1) && isdigit(number_of_players_string[0]) && (stoi(number_of_players_string) <= 4) && (stoi(number_of_players_string) > 1))
		{
			number_of_players = stoi(number_of_players_string);
			number_of_players_complete = true;
		}
	} while (!number_of_players_complete);

	for (int i = 0; i < number_of_players; i++)
	{
		player_names[i] = display_manager.get_player_data("Type in your player name, player " + std::to_string(i + 1) + ".");
	}

	logic_manager.reset();
	logic_manager.set_cursor_row(9);
	logic_manager.set_cursor_column(9);
	logic_manager.get_board_info(board_data);

	do
	{
		bool turn_completed = false;
		do
		{
			int input = ascii_io::undefined;
			display_manager.set_board_directions_content(player_names[player_turn - 1] + ": place a piece.");
			display_manager.display_board(board_data, logic_manager.get_cursor_row(), logic_manager.get_cursor_column());
			input = ascii_io::getchar();
			if (input == ascii_io::enter)
			{
				if (logic_manager.place_piece(player_turn, logic_manager.get_cursor_row(), logic_manager.get_cursor_column()))
				{
					pairs_taken[player_turn - 1] = pairs_taken[player_turn - 1] + logic_manager.check_take_pieces(player_turn);
					logic_manager.get_board_info(board_data);
					display_manager.display_board(board_data, logic_manager.get_cursor_row(), logic_manager.get_cursor_column());
					turn_completed = true;
				}
			}
			else if ((input == ascii_io::right) || (input == ascii_io::left) || (input == ascii_io::up) || (input == ascii_io::down))
			{
				logic_manager.move_cursor(interface::user_to_logic(input));
			}

		} while (!turn_completed);

		winner_five_in_a_row = logic_manager.check_winner(player_turn);

		if (winner_five_in_a_row)
		{
			winner = true;
			display_manager.set_board_directions_content(player_names[player_turn - 1] + " got five in a row!");
			display_manager.display_board(board_data, logic_manager.get_cursor_row(), logic_manager.get_cursor_column());
			ascii_io::getchar();
		}

		if (pairs_taken[player_turn - 1] >= 5)
		{
			winner = true;
			display_manager.set_board_directions_content(player_names[player_turn - 1] + " took five pairs!");
			display_manager.display_board(board_data, logic_manager.get_cursor_row(), logic_manager.get_cursor_column());
			ascii_io::getchar();
		}

		if ((player_turn + 1) > number_of_players)
		{
			player_turn = 1;
		}
		else
		{
			player_turn++;
		}

	} while (!winner);
}