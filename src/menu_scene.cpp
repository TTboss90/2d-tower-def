
#include "menu_scene.hpp"
#include "game_scene.hpp"
#include <iostream>

main_menu::main_menu()
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
				std::cout << "Play" << std::endl;
				next_scene = std::make_unique<game_scene>();
				};
			break;
		case 2:
			the_button.on_click = [this, i]() {
				std::cout << "Button 2 Clicked!" << std::endl;
				m_click_count++;
				m_main_buttons[i - 1].label = "clickt " + std::to_string(m_click_count) + " times";
				};
			break;
		case 3:
			the_button.on_click = [this]() {
				std::cout << "Button 3 Clicked!" << std::endl;
				};
			break;
		case 4:
			the_button.label = "Options";
			the_button.on_click = [this]() {
				std::cout << "Button 4 Clicked!" << std::endl;
				m_menu_state = menu_state::OPTIONS;
				};
			break;
		case 5:
			the_button.label = "Exit";
			the_button.on_click = [this]() {
				std::cout << "Button 5 Clicked!" << std::endl;
				exit = true;
				};
			break;
		default:
			break;
		}
	}
}

void main_menu::update()
{
	switch (m_menu_state)
	{
		case menu_state::MAIN:
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				Vector2 mouse_pos = GetMousePosition();
				for (button& the_button : m_main_buttons) {
					if (CheckCollisionPointRec(mouse_pos, the_button.rect)) {
						the_button.on_click();
					}
				}
			}
			break;
		case menu_state::OPTIONS:
			if (IsKeyPressed(KEY_K))
				m_menu_state = menu_state::MAIN;
			break;
	}
}

void main_menu::draw_scene()
{
	DrawFPS(10, 10);

	switch (m_menu_state) 
	{
		case menu_state::MAIN:
			for (button& the_button : m_main_buttons)
			{
				DrawRectangleRec(the_button.rect, BLUE);
				int fontSize = 30;
				int textWidth = MeasureText(the_button.label.c_str(), fontSize);

				float textX = the_button.rect.x + (the_button.rect.width - textWidth) / 2.0f;
				float textY = the_button.rect.y + (the_button.rect.height - fontSize) / 2.0f;

				DrawText(the_button.label.c_str(), textX, textY, fontSize, BLACK);

			}
			break;
		case menu_state::OPTIONS:
			DrawText("Options Menu", 10, 10, 40, RED);
			break;
	}
}

main_menu::~main_menu() {}