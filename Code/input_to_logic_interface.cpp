#include "input_to_logic_interface.h"
#include <ascii_io.h>

input interface::user_to_logic(int user_input)
{
	if (user_input == ascii_io::q)
	{
		return q;
	}
	else if (user_input == ascii_io::up)
	{
		return _up;
	}
	else if (user_input == ascii_io::down)
	{
		return _down;
	}
	else if (user_input == ascii_io::right)
	{
		return _right;
	}
	else if (user_input == ascii_io::left)
	{
		return _left;
	}
	else if (user_input == ascii_io::enter)
	{
		return enter;
	}

	return undefined;
}