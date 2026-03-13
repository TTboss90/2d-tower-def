
#pragma once
#include "scenes/scenes.hpp"
#include <raylib.h>

class game_scene : public scene
{
public:
	game_scene();
	~game_scene() override;
	void run() override;

private:
	Camera2D m_camera{ 0 };

	bool m_exit = false;
};