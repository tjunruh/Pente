#pragma once
#include <string>
#include <ascii_io.h>
#include <format_tools.h>

struct control_mapping
{
	std::string name = "";
	int key = ascii_io::undefined;
};

const std::vector<control_mapping> default_control_names =
{
	{"up", ascii_io::up},
	{"down", ascii_io::down},
	{"right", ascii_io::right},
	{"left", ascii_io::left},
	{"select", ascii_io::enter},
	{"quit", ascii_io::q},
	{"delete", ascii_io::DEL},
	{"help", ascii_io::h},
	{"enable line drawing", 0},
	{"enable color", 1},
	{"background color", format_tools::black},
	{"foreground color", format_tools::white},
	{"player 1 color", format_tools::blue},
	{"player 2 color", format_tools::red},
	{"player 3 color", format_tools::green},
	{"player 4 color", format_tools::yellow},
	{"cursor over empty space color", format_tools::cyan},
	{"cursor over occupied space color", format_tools::magenta},
	{"bold foreground", 0}
};