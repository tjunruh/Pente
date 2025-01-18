#include "logic.h"

bool logic::check_winner(int player) 
{
	bool winner = false;
	bool rows = false;
	bool columns = false;
	bool diagonal = false;

	rows = rows_check_winner(player);
	columns = columns_check_winner(player);
	diagonal = diagonal_check_winner(player);

	if (rows || columns || diagonal) 
	{
		winner = true;
	}

	return winner;
}

bool logic::rows_check_winner(int player) 
{
	int consecuative_pieces = 0;
	bool winner = false;
	for (int rows = 0; rows < NUMBER_OF_ROWS; rows++) 
	{
		consecuative_pieces = 0;
		for (int columns = 0; columns < NUMBER_OF_COLUMNS; columns++) 
		{
			if (board[rows][columns] == player) 
			{
				consecuative_pieces++;
			}
			else 
			{
				consecuative_pieces = 0;
			}
			if (consecuative_pieces == 5) 
			{
				winner = true;
			}
		}
		if (consecuative_pieces == 5) 
		{
			break;
		}

	}
	return winner;
}

bool logic::columns_check_winner(int player) 
{
	int consecuative_pieces = 0;
	bool winner = false;
	for (int columns = 0; columns < NUMBER_OF_COLUMNS; columns++) 
	{
		consecuative_pieces = 0;
		for (int rows = 0; rows < NUMBER_OF_ROWS; rows++)
		{
			if (board[rows][columns] == player)
			{
				consecuative_pieces++;
			}
			else 
			{
				consecuative_pieces = 0;
			}
			if (consecuative_pieces == 5)
			{
				winner = true;
			}
		}
		if (consecuative_pieces == 5)
		{
			break;
		}
	}
	return winner;
}

bool logic::diagonal_top_left_triangle_check_winner(int player) 
{
	int consecuative_pieces = 0;
	bool winner = false;
	for (int starting_row = 0; starting_row < NUMBER_OF_ROWS; starting_row++) 
	{
		consecuative_pieces = 0;
		for (int i = 0; i < (starting_row + 1); i++) 
		{
			if (board[starting_row - i][i] == player) 
			{
				consecuative_pieces++;
			}
			else 
			{
				consecuative_pieces = 0;
			}
			if (consecuative_pieces == 5) 
			{
				winner = true;
			}
		}
		if (consecuative_pieces == 5) 
		{
			break;
		}
	}
	return winner;
}

bool logic::diagonal_bottom_left_triangle_check_winner(int player) 
{
	int consecuative_pieces = 0;
	bool winner = false;
	for (int starting_row = 0; starting_row < NUMBER_OF_ROWS; starting_row++) 
	{
		consecuative_pieces = 0;
		for (int i = 0; i < (NUMBER_OF_ROWS - starting_row); i++) 
		{
			if (board[starting_row + i][i] == player) 
			{
				consecuative_pieces++;
			}
			else 
			{
				consecuative_pieces = 0;
			}
			if (consecuative_pieces == 5) 
			{
				winner = true;
			}
		}
		if (consecuative_pieces == 5) 
		{
			break;
		}
	}
	return winner;
}

bool logic::diagonal_top_right_triangle_check_winner(int player) 
{
	int consecuative_pieces = 0;
	bool winner = false;
	for (int starting_row = 0; starting_row < NUMBER_OF_ROWS; starting_row++) 
	{
		consecuative_pieces = 0;
		for (int i = 0; i < (starting_row + 1); i++) 
		{
			if (board[starting_row - i][(NUMBER_OF_COLUMNS - 1) - i] == player) 
			{
				consecuative_pieces++;
			}
			else 
			{
				consecuative_pieces = 0;
			}
			if (consecuative_pieces == 5) 
			{
				winner = true;
			}
		}
		if (consecuative_pieces == 5) 
		{
			break;
		}
	}
	return winner;
}

bool logic::diagonal_bottom_right_triangle_check_winner(int player)
{
	int consecuative_pieces = 0;
	bool winner = false;
	for (int starting_row = 0; starting_row < NUMBER_OF_ROWS; starting_row++) 
	{
		consecuative_pieces = 0;
		for (int i = 0; i < (NUMBER_OF_ROWS - starting_row); i++) 
		{
			if (board[i + starting_row][(NUMBER_OF_COLUMNS - 1) - i] == player) 
			{
				consecuative_pieces++;
			}
			else 
			{
				consecuative_pieces = 0;
			}
			if (consecuative_pieces == 5) 
			{
				winner = true;
			}
		}
		if (consecuative_pieces == 5) 
		{
			break;
		}
	}
	return winner;
}

bool logic::diagonal_check_winner(int player) 
{
	bool diagonal = false;
	bool top_left = false;
	bool bottom_left = false;
	bool top_right = false;
	bool bottom_right = false;

	top_left = diagonal_top_left_triangle_check_winner(player);
	bottom_left = diagonal_bottom_left_triangle_check_winner(player);
	top_right = diagonal_top_right_triangle_check_winner(player);
	bottom_right = diagonal_bottom_right_triangle_check_winner(player);

	if (top_left || bottom_left || top_right || bottom_right) 
	{
		diagonal = true;
	}
	return diagonal;
}

bool logic::cat_game() 
{
	bool cat_game = true;
	for (int rows = 0; rows < NUMBER_OF_ROWS; rows++) 
	{
		for (int columns = 0; columns < NUMBER_OF_COLUMNS; columns++)
		{
			
			if (board[rows][columns] == 0)
			{
				cat_game = false;
				return cat_game;
			}
		}
	}
	return cat_game;
}

int logic::check_take_pieces(int player) 
{
	int number_of_pairs_taken_horizontal = 0;
	int number_of_pairs_taken_vertical = 0;
	int number_of_pairs_taken_diagonal = 0;
	int number_of_pairs_taken_total = 0;
	number_of_pairs_taken_horizontal = check_take_pieces_horizontal(player);
	number_of_pairs_taken_vertical = check_take_pieces_vertical(player);
	number_of_pairs_taken_diagonal = check_take_pieces_diagonal(player);
	number_of_pairs_taken_total = number_of_pairs_taken_horizontal + number_of_pairs_taken_vertical + number_of_pairs_taken_diagonal;

	return number_of_pairs_taken_total;
}

int logic::check_take_pieces_vertical(int player) 
{
	int piece_1 = -1;
	int piece_2 = -1;
	int piece_3 = -1;
	int number_of_pairs_taken = 0;

	if (cursor_row >= 3) 
	{
		piece_1 = board[cursor_row - 1][cursor_column];
		piece_2 = board[cursor_row - 2][cursor_column];
		piece_3 = board[cursor_row - 3][cursor_column];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) 
		{
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row - 1][cursor_column] = piece_1;
			board[cursor_row - 2][cursor_column] = piece_2;
		}
	}


	if (cursor_row <= 15) 
	{
		piece_1 = board[cursor_row + 1][cursor_column];
		piece_2 = board[cursor_row + 2][cursor_column];
		piece_3 = board[cursor_row + 3][cursor_column];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) 
		{
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row + 1][cursor_column] = piece_1;
			board[cursor_row + 2][cursor_column] = piece_2;
		}
	}

	return number_of_pairs_taken;
}

int logic::check_take_pieces_horizontal(int player) {
	int piece_1 = -1;
	int piece_2 = -1;
	int piece_3 = -1;
	int number_of_pairs_taken = 0;

	if (cursor_column >= 3) 
	{
		piece_1 = board[cursor_row][cursor_column - 1];
		piece_2 = board[cursor_row][cursor_column - 2];
		piece_3 = board[cursor_row][cursor_column - 3];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) 
		{
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row][cursor_column - 1] = piece_1;
			board[cursor_row][cursor_column - 2] = piece_2;
		}
	}


	if (cursor_column <= 15) 
	{
		piece_1 = board[cursor_row][cursor_column + 1];
		piece_2 = board[cursor_row][cursor_column + 2];
		piece_3 = board[cursor_row][cursor_column + 3];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) 
		{
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row][cursor_column + 1] = piece_1;
			board[cursor_row][cursor_column + 2] = piece_2;
		}
	}

	return number_of_pairs_taken;
}

int logic::check_take_pieces_diagonal(int player) {
	int piece_1 = -1;
	int piece_2 = -1;
	int piece_3 = -1;
	int number_of_pairs_taken = 0;

	if ((cursor_row <= 15) && (cursor_column <= 15)) 
	{
		piece_1 = board[cursor_row + 1][cursor_column + 1];
		piece_2 = board[cursor_row + 2][cursor_column + 2];
		piece_3 = board[cursor_row + 3][cursor_column + 3];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) 
		{
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row + 1][cursor_column + 1] = piece_1;
			board[cursor_row + 2][cursor_column + 2] = piece_2;
		}
	}

	if ((cursor_row <= 15) && (cursor_column >= 3)) 
	{
		piece_1 = board[cursor_row + 1][cursor_column - 1];
		piece_2 = board[cursor_row + 2][cursor_column - 2];
		piece_3 = board[cursor_row + 3][cursor_column - 3];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) 
		{
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row + 1][cursor_column - 1] = piece_1;
			board[cursor_row + 2][cursor_column - 2] = piece_2;
		}
	}

	if ((cursor_row >= 3) && (cursor_column >= 3)) 
	{
		piece_1 = board[cursor_row - 1][cursor_column - 1];
		piece_2 = board[cursor_row - 2][cursor_column - 2];
		piece_3 = board[cursor_row - 3][cursor_column - 3];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) 
		{
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row - 1][cursor_column - 1] = piece_1;
			board[cursor_row - 2][cursor_column - 2] = piece_2;

		}
	}

	if ((cursor_row >= 3) && (cursor_column <= 15)) {
		piece_1 = board[cursor_row - 1][cursor_column + 1];
		piece_2 = board[cursor_row - 2][cursor_column + 2];
		piece_3 = board[cursor_row - 3][cursor_column + 3];
		if ((piece_1 == piece_2) && (piece_3 == player) && (piece_1 != player) && (piece_2 != player) && (piece_1 != 0) && (piece_2 != 0)) {
			number_of_pairs_taken++;
			piece_1 = 0;
			piece_2 = 0;
			board[cursor_row - 1][cursor_column + 1] = piece_1;
			board[cursor_row - 2][cursor_column + 2] = piece_2;

		}
	}

	return number_of_pairs_taken;
}

void logic::set_cursor_row(int row)
{
	if ((row >= 0) && (row < NUMBER_OF_ROWS))
	{
		cursor_row = row;
	}
}

void logic::set_cursor_column(int column)
{
	if ((column >= 0) && (column < NUMBER_OF_COLUMNS))
	{
		cursor_column = column;
	}
}

void logic::move_cursor(input user_input)
{
	if (user_input == _up)
	{
		set_cursor_row(cursor_row - 1);
	}
	else if (user_input == _down)
	{
		set_cursor_row(cursor_row + 1);
	}
	else if (user_input == _right)
	{
		set_cursor_column(cursor_column + 1);
	}
	else if (user_input == _left)
	{
		set_cursor_column(cursor_column - 1);
	}
}

int logic::get_cursor_row()
{
	return cursor_row;
}

int logic::get_cursor_column()
{
	return cursor_column;
}

void logic::get_board_info(int(&board_info)[19][19])
{
	for (unsigned int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (unsigned int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			board_info[row][column] = board[row][column];
		}
	}
}

void logic::reset()
{
	for (unsigned int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (unsigned int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			board[row][column] = 0;
		}
	}
}

bool logic::board_slot_open(int row, int column)
{
	bool open = false;
	if ((row >= 0) && (row < NUMBER_OF_ROWS) && (column >= 0) && (column < NUMBER_OF_COLUMNS))
	{
		if (board[row][column] == 0)
		{
			open = true;
		}
	}

	return open;
}

bool logic::place_piece(int row, int column, int player)
{
	if ((row >= 0) && (row < NUMBER_OF_ROWS) && (column >= 0) && (column < NUMBER_OF_COLUMNS) && board_slot_open(row, column))
	{
		board[row][column] = player;
		return true;
	}
	else
	{
		return false;
	}
}