#include "scenes/menu_scene.hpp"
#include "scenes/game_scene.hpp"
#include <raygui.h>

constexpr std::string_view game_name = "2d tower defense";

//constructor, initializes the title menu and loads the click sound
void main_menu::init_title_menu()
{
	int i = 0;
	for (button& the_button : m_title_buttons) {
		i++;
		the_button.rect.width = 200;
		the_button.rect.height = 100;
		the_button.rect.x = ((int)GetRenderWidth() / 2) - ((int)the_button.rect.width / 2);
		the_button.rect.y = i * 150 + 150;

		the_button.label = "Button  " + std::to_string(i);

		switch (i)
		{
		case 1:
			the_button.label = "Play";
			the_button.on_click = [this, i]() {
				next_scene = std::make_unique<game_scene>(100,100,"resources\\test_tile_map.png");
				m_exit = true;
				};
			break;
		case 2:
			the_button.on_click = [this, i]() {
				m_click_count++;
				m_title_buttons[i - 1].label = "clickt " + std::to_string(m_click_count) + " times";
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
				m_exit = true;
				};
			break;
		default:
			break;
		}
	}
}

//runs the title menu, checks if any button is clicked and plays the click sound
void main_menu::title_menu()
{
	int fontSize = 50;
	int textWidth = MeasureText(game_name.data(), fontSize);

	int screenWidth = GetRenderWidth();
	int x = (screenWidth - textWidth) / 2;
	int y = 150; 

	DrawText(game_name.data(), x, y, fontSize, BLACK);

	for (button& the_button : m_title_buttons)
	{
		if (GuiButton(the_button.rect, the_button.label.c_str()))
		{
			PlaySound(m_click_sound);
			the_button.on_click();
		}
	}
}