#include "game_operations.h"
#include <string>
#include <frame.h>
#include <menu.h>
#include <label.h>
#include <ascii_io.h>
#include "file_management.h"
#include "default_controls.h"

int main()
{
    ascii_io::ascii_engine_init();
    frame* home_frame = new frame();
    frame* main_frame = new frame();
    frame* multipurpose_frame = new frame();
    frame* settings_frame = new frame();
    controls* game_controls = new controls();
    pente_file_management::load_controls("controls.json", game_controls);
    for (unsigned int i = 0; i < default_control_names.size(); i++)
    {
        if (game_controls->get_key(default_control_names[i].name) == ascii_io::undefined)
        {
            game_controls->bind(default_control_names[i].name, default_control_names[i].key);
        }
    }
    game_operations game_manager(main_frame, multipurpose_frame, settings_frame, game_controls);
    label logo(home_frame);
    menu initialization_menu(home_frame, "new line");
    logo.set_alignment("center block");
    logo.set_output(game_manager.logo);
    logo.set_spacing(15, 3, 0, 0);

    initialization_menu.append_item("New Game");
    initialization_menu.append_item("Exit");
    initialization_menu.disable_quit();
    initialization_menu.set_alignment("center block");

    ascii_io::hide_cursor();

    do
    {
        initialization_menu.set_controls({ game_controls->get_key("select") }, game_controls->get_key("up"), game_controls->get_key("down"), game_controls->get_key("quit"));
        home_frame->set_default_foreground_color(game_controls->get_key("foreground color"));
        home_frame->set_default_background_color(game_controls->get_key("background color"));
        std::string selection = "";
        int key_stroke = ascii_io::undefined;
        home_frame->display();
        initialization_menu.get_selection(selection, key_stroke);

        if (selection == "New Game")
        {
            game_manager.game_loop();
        }
        else if (selection == "Exit")
        {
            break;
        }

    } while (1);

    pente_file_management::save_controls("controls.json", game_controls);

    delete(home_frame);
    delete(main_frame);
    delete(multipurpose_frame);
    delete(settings_frame);
    delete(game_controls);

    ascii_io::ascii_engine_end();
}
