#pragma once
#include <string>
#include <controls.h>

namespace pente_file_management
{
#ifdef _WIN32
	const std::string controls_path = "Pente_Controls\\";
#elif __linux__
	const std::string controls_path = "Pente_Controls/";
#endif
	int save_controls(std::string file_name, controls* game_controls);
	int load_controls(std::string file_name, controls* game_controls);
}