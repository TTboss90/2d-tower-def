#include "scenes/menu_scene.hpp"
#include "scenes/game_scene.hpp"
#include <raygui.h>

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
				m_menu_state = menu_state::TITLE;
				};
			break;
		default:
			break;
		}
	}
}

void main_menu::options_menu()
{
	for (button& the_button : m_option_buttons)
	{
		if (GuiButton(the_button.rect, the_button.label.c_str())) 
		{
			PlaySound(m_click_sound);
			the_button.on_click();
		}
	}
}