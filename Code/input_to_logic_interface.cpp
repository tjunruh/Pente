#include "input_to_logic_interface.h"
#include <ascii_io.h>

input interface::user_to_logic(int user_input, controls* game_controls)
{
	if (user_input == game_controls->get_key("quit"))
	{
		return q;
	}
	else if (user_input == game_controls->get_key("up"))
	{
		return _up;
	}
	else if (user_input == game_controls->get_key("down"))
	{
		return _down;
	}
	else if (user_input == game_controls->get_key("right"))
	{
		return _right;
	}
	else if (user_input == game_controls->get_key("left"))
	{
		return _left;
	}
	else if (user_input == game_controls->get_key("select"))
	{
		return enter;
	}

	return undefined;
}