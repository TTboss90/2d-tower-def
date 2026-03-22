
#pragma once
#include "scenes/scenes.hpp"
#include <array>
#include <raylib.h>
#include <functional>
#include <string>
#include "core/ui/button.hpp"

//menu state enum, can be expanded in the future to include more states like credits, etc.
enum class menu_state
{
	TITLE,
	OPTIONS,
};

//main menu scene class, inherits from the base scene class, handles the main menu logic and rendering
class main_menu : public scene
{
public:
	main_menu();
	~main_menu() override;

	void run() override;

private:
	void init_title_menu();
	void init_options_menu();

	void options_menu();

	void title_menu();

	std::array<button, 5> m_title_buttons;
	std::array<button, 4> m_option_buttons;

	Rectangle m_volume_slider{ 0 };

	menu_state m_menu_state = menu_state::TITLE;

	int m_click_count = 0;

	float m_volume;

	bool m_exit = false;

	Sound m_click_sound;
};