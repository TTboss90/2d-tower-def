
#include "menu_scene.hpp"

void main_menu::update()
{
	switch (m_menu_state)
	{
		case menu_state::MAIN:
			main_menu::update_main_menu();
			break;
		case menu_state::OPTIONS:
			main_menu::update_options_menu();
			break;
	}
}

void main_menu::draw_scene()
{
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
}

main_menu::main_menu()
{
	main_menu::init_main_menu();
	main_menu::init_options_menu();
}

main_menu::~main_menu() {}