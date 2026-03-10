
#pragma once
#include "scenes/scenes.hpp"
#include <raylib.h>

class game_scene : public scene
{
public:
	game_scene();
	~game_scene() override;
	void draw_scene() override;
	void update() override;

private:
	Camera2D m_camera{ 0 };

};