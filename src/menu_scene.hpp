
#pragma once
#include "2d_tower_def.hpp"
#include <array>

class main_menu : public scene
{
public:
	main_menu();
	~main_menu() override;

	void draw_scene() override;
	void update() override;

private:
	std::array<button, 5> m_buttons;

	int m_click_count = 0;
};