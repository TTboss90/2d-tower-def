
#include "scenes/menu_scene.hpp"

void main_menu::run()
{
	while (!WindowShouldClose()) {
		switch (m_menu_state)
		{
		case menu_state::MAIN:
			main_menu::update_main_menu();
			break;
		case menu_state::OPTIONS:
			main_menu::update_options_menu();
			break;
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawFPS(10, 10);

		switch (m_menu_state)
		{
		case menu_state::MAIN:
			main_menu::draw_main_menu();
			break;
		case menu_state::OPTIONS:
			main_menu::draw_options_menu();
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