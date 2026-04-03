#include <scenes/game_scene.hpp>
#include <scenes/menu_scene.hpp>
#include <raygui.h>

void game_scene::game_menu() 
{
	if (GuiButton(Rectangle{ 100,100,100,100 }, "to main menu")) {
		next_scene = std::make_unique<main_menu>();
	}
}