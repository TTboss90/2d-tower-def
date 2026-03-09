
#include "menu_scene.hpp"
#include "game_scene.hpp"
#include <iostream>

void main_menu::init_main_menu()
{
	int i = 0;
	for (button& the_button : m_main_buttons) {
		i++;
		the_button.rect.width = 200;
		the_button.rect.height = 100;
		the_button.rect.x = ((int)GetRenderWidth() / 2) - ((int)the_button.rect.width / 2);
		the_button.rect.y = i * 150;

		the_button.label = "Button  " + std::to_string(i);

		switch (i)
		{
		case 1:
			the_button.label = "Play";
			the_button.on_click = [this, i]() {
				next_scene = std::make_unique<game_scene>();
				};
			break;
		case 2:
			the_button.on_click = [this, i]() {
				m_click_count++;
				m_main_buttons[i - 1].label = "clickt " + std::to_string(m_click_count) + " times";
				};
			break;
		case 3:
			the_button.on_click = [this]() {
				};
			break;
		case 4:
			the_button.label = "Options";
			the_button.on_click = [this]() {
				m_menu_state = menu_state::OPTIONS;
				};
			break;
		case 5:
			the_button.label = "Exit";
			the_button.on_click = [this]() {
				exit = true;
				};
			break;
		default:
			break;
		}
	}
}

void main_menu::init_options_menu()
{
	int i = 0;
	for (button& the_button : m_option_buttons) {
		i++;
		the_button.rect.width = 200;
		the_button.rect.height = 100;
		the_button.rect.x = ((int)GetRenderWidth() / 2) - ((int)the_button.rect.width / 2);
		the_button.rect.y = i * 150;

		the_button.label = "setting  " + std::to_string(i);

		switch (i)
		{
		case 1:
			the_button.on_click = [this, i]() {
				next_scene = std::make_unique<game_scene>();
				};
			break;
		case 2:
			the_button.on_click = [this, i]() {
				m_click_count++;
				m_option_buttons[i - 1].label = "clickt " + std::to_string(m_click_count) + " times";
				};
			break;
		case 3:
			the_button.on_click = [this]() {
				};
			break;
		case 4:
			the_button.on_click = [this]() {
				};
			break;
		case 5:
			the_button.label = "Back";
			the_button.on_click = [this]() {
				m_menu_state = menu_state::MAIN;
				};
			break;
		default:
			break;
		}
	}
}

void main_menu::draw_main_menu()
{
	for (button& the_button : m_main_buttons)
	{
		DrawRectangleRec(the_button.rect, BLUE);
		int fontSize = 30;
		int textWidth = MeasureText(the_button.label.c_str(), fontSize);

		float textX = the_button.rect.x + (the_button.rect.width - textWidth) / 2.0f;
		float textY = the_button.rect.y + (the_button.rect.height - fontSize) / 2.0f;

		DrawText(the_button.label.c_str(), textX, textY, fontSize, BLACK);

	}
}

void main_menu::draw_options_menu()
{
	for (button& the_button : m_option_buttons)
	{
		DrawRectangleRec(the_button.rect, BLUE);
		int fontSize = 30;
		int textWidth = MeasureText(the_button.label.c_str(), fontSize);

		float textX = the_button.rect.x + (the_button.rect.width - textWidth) / 2.0f;
		float textY = the_button.rect.y + (the_button.rect.height - fontSize) / 2.0f;

		DrawText(the_button.label.c_str(), textX, textY, fontSize, BLACK);

	}
}

void main_menu::update_main_menu()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mouse_pos = GetMousePosition();
		for (button& the_button : m_main_buttons) {
			if (CheckCollisionPointRec(mouse_pos, the_button.rect)) {
				the_button.on_click();
			}
		}
	}
}

void main_menu::update_options_menu()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mouse_pos = GetMousePosition();
		for (button& the_button : m_option_buttons) {
			if (CheckCollisionPointRec(mouse_pos, the_button.rect)) {
				the_button.on_click();
			}
		}
	}
}

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