
#include "scenes/menu_scene.hpp"
#include <raygui.h>


//runs the main menu, checks the current menu state and runs the corresponding menu, also checks if the exit flag is set to break the loop
void main_menu::run()
{
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawFPS(10, 10);

		switch (m_menu_state)
		{
		case menu_state::TITLE:
			main_menu::title_menu();
			break;
		case menu_state::OPTIONS:
			main_menu::options_menu();
			break;
		}

		EndDrawing();

		if (m_exit) {
			break;
		}
	}
}

//constructor, initializes the main menu, loads the click sound and sets the text size for the buttons
main_menu::main_menu()
{
	m_click_sound = LoadSound(".\\resources\\click.wav");

	GuiSetStyle(DEFAULT, TEXT_SIZE, 25);
	main_menu::init_title_menu();
	main_menu::init_options_menu();
}

//destructor, unloads the click sound and resets the text size for the buttons
main_menu::~main_menu() {
	UnloadSound(m_click_sound);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 10);
}