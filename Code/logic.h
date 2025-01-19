#pragma once

#include "logic_input.h"

#define NUMBER_OF_ROWS 19
#define NUMBER_OF_COLUMNS 19

class logic
{
public:
	bool check_winner(int player);
	bool cat_game();
	int check_take_pieces(int player);
	void set_cursor_row(int row);
	void set_cursor_column(int column);
	void move_cursor(input user_input);
	int get_cursor_row();
	int get_cursor_column();
	void get_board_info(int(&board_info)[19][19]);
	void reset();
	bool place_piece(int player, int row, int column);

private:
	int cursor_row = 0;
	int cursor_column = 0;

	int board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

	bool rows_check_winner(int player);
	bool columns_check_winner(int player);
	bool diagonal_top_left_triangle_check_winner(int player);
	bool diagonal_bottom_left_triangle_check_winner(int player);
	bool diagonal_top_right_triangle_check_winner(int player);
	bool diagonal_bottom_right_triangle_check_winner(int player);
	bool diagonal_check_winner(int player);
	int check_take_pieces_horizontal(int player);
	int check_take_pieces_vertical(int player);
	int check_take_pieces_diagonal(int player);
	bool board_slot_open(int row, int column);
};