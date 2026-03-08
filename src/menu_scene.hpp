
#pragma once
#include "2d_tower_def.hpp"
#include <array>

enum class menu_state
{
	MAIN,
	OPTIONS,
};

class main_menu : public scene
{
public:
	main_menu();
	~main_menu() override;

	void draw_scene() override;
	void update() override;

private:
	std::array<button, 5> m_main_buttons;

	menu_state m_menu_state = menu_state::MAIN;

	int m_click_count = 0;
};