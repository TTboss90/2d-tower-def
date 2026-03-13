
#include "scenes/menu_scene.hpp"

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

main_menu::main_menu()
{
	main_menu::init_main_menu();
	main_menu::init_options_menu();
}

main_menu::~main_menu() {}