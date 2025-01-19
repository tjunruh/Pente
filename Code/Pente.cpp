#include "game_operations.h"
#include <string>
#include <frame.h>
#include <menu.h>
#include <label.h>
#include <ascii_io.h>

int main()
{
    ascii_io::ascii_engine_init();
    frame* home_frame = new frame();
    frame* main_frame = new frame();
    frame* multipurpose_frame = new frame();
    game_operations game_manager(main_frame, multipurpose_frame);
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

    delete(home_frame);
    delete(main_frame);
    delete(multipurpose_frame);

    ascii_io::ascii_engine_end();
}
