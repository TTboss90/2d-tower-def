
#pragma once
#include "scenes/scenes.hpp"
#include <array>
#include <raylib.h>
#include <functional>
#include <string>
#include "core/ui/button.hpp"

enum class menu_state
{
	TITLE,
	OPTIONS,
};

class main_menu : public scene
{
public:
	main_menu();
	~main_menu() override;

	void run() override;

private:
	void init_main_menu();
	void init_options_menu();

	void options_menu();

	void title_menu();

	std::array<button, 5> m_main_buttons;
	std::array<button, 5> m_option_buttons;

	menu_state m_menu_state = menu_state::TITLE;

	int m_click_count = 0;

	bool m_exit = false;
};