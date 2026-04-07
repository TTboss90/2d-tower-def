#include <scenes/game_scene.hpp>
#include <scenes/menu_scene.hpp>
#include <raygui.h>

void game_scene::game_menu() 
{
	if (GuiButton(Rectangle{ 100,100,100,100 }, "to main menu")) {
		next_scene = std::make_unique<main_menu>();
		m_exit = true;
	}

	GuiSlider(m_volume_slider, "Volume", TextFormat("%.0f", m_volume), &m_volume, 0.0f, 100.0f);

	SetMasterVolume(m_volume / 100.0f);
}